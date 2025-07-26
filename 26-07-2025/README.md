## Problem: [Maximum Number of Non-Overlapping Valid Subarrays](https://leetcode.com/problems/maximum-number-of-non-overlapping-valid-subarrays/)

- **Status:** ❌ Tried but couldn’t solve  
- **Difficulty:** Hard  
- **Tags:** `Prefix Sum`, `Greedy`, `Subarrays`, `Optimization`

---

### ✅ Intuition:

Initially, I tried solving this by brute-force.

The idea was:  
For each conflicting pair `(u, v)`, try **removing** that conflict from the list, then **recompute the total number of valid subarrays** (i.e., subarrays that don’t include any conflicting pair within them).  
To check for conflicts in each subarray, I used a 2D grid + prefix sum to speed up checking whether a subarray `[L, R]` includes a conflict. I repeated this for every conflict — meaning O(m) rounds of O(n²) checks.

**But this was way too slow.**  
It passed some test cases but gave **TLE (Time Limit Exceeded)** on larger inputs. So clearly, I needed a better approach.

Eventually, I came across an **official editorial solution** that gave me an “aha!” moment. Instead of recomputing subarrays again and again, it flips the problem:  
Let’s compute the answer as if we **don’t remove any conflicts** — then cleverly track how much extra we could gain by removing *just one* conflict.

---

### ✅ Explanation of the Solution:

Let’s break the final solution into two major parts — the base score (without removing any conflict), and the bonus gain (by removing one best conflict).

---

#### 🔹 **Part 1: The Base Score – Forbidden Starts**

**Goal**: For each index `r` (the right end of a subarray), count how many valid subarrays end at `r`.  

To do this, we define a rule:
> A conflict `(u, v)` means that no subarray ending at `v` or later should start at or before `u`.

So, for every position `r`, we keep track of all conflict rules `(u, v)` where `v == r`.  
Out of these, the strictest rule is the one with the **largest `u`**, because it forbids the most.

Let’s call this `top1`, the **forbidden start** at position `r`.  
So the number of valid subarrays ending at `r` is:  


✅ Example for `n = 5`, conflicts = `[[1,3],[2,4],[1,4]]`

| r | Conflicts Ending at r | Forbidden Start (top1) | Valid Subarrays Ending at r | Total |
|---|------------------------|-------------------------|------------------------------|-------|
| 1 | —                      | 0                       | 1 (`[1]`)                    | 1     |
| 2 | —                      | 0                       | 2 (`[1,2], [2]`)             | 3     |
| 3 | (1,3)                  | 1                       | 2 (`[2,3], [3]`)             | 5     |
| 4 | (2,4), (1,4)           | 2                       | 2 (`[3,4], [4]`)             | 7     |
| 5 | —                      | 2                       | 3 (`[3,4,5], [4,5], [5]`)    | 10    |

This gives us our **base score** = `10` (the `ans` variable in code).

---

#### 🔹 **Part 2: The Leap – Bonus Gain From Removing One Conflict**

Now comes the smart trick.

At every index `r`, once we’ve decided the current `top1` (largest `u`), we ask:
> If we could remove the conflict that caused `top1`, what would be the new forbidden start?

Let’s say we also keep track of the **second-largest `u`** — we call it `top2`.

Then:
- Original count of valid subarrays = `r - top1`
- New count if we removed top1’s conflict = `r - top2`
- **Bonus gain** = `top1 - top2`

We store this gain in a `bonus[]` array:  
If `top1` = 2 and `top2` = 1, then `bonus[2] += 1`.

At the end, we look for the **maximum value in `bonus[]`**, and add it to the base score.

✅ Continuing the earlier example:

| r | top1 | top2 | Gain | bonus[] Updates |
|---|------|------|------|------------------|
| 3 | 1    | 0    | 1    | bonus[1] += 1     |
| 4 | 2    | 1    | 1    | bonus[2] += 1     |
| 5 | 2    | 1    | 1    | bonus[2] += 1     |

Max bonus = 2 → Final Answer = base score (10) + max bonus (2) = **12**

---

### 🧠 Time & Space Complexity:
- **Time:** O(n + m)  
  - `O(m)` to build the `right[]` map of conflicts.
  - `O(n)` loop for computing base score and bonus.
- **Space:** O(n + m)  
  - `right[]` holds conflict starts for each end.
  - `bonus[]` of size `n`.

---

### 💡 Solution (C++):
```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        std::vector<std::vector<int>> right(n + 1);
        for (const auto& pair : conflictingPairs) {
            int u = std::min(pair[0], pair[1]);
            int v = std::max(pair[0], pair[1]);
            right[v].push_back(u);
        }

        long long ans = 0;
        std::vector<long long> left = {0, 0};
```