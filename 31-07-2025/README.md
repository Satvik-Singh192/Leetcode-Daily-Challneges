## Problem: [898. Bitwise ORs of Subarrays](https://leetcode.com/problems/bitwise-ors-of-subarrays)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** `Bit Manipulation`, `Set`, `Subarrays`, `Optimization`

---

### ✅ Intuition:
Brute-forcing all subarrays and OR-ing them is too slow.  
So I thought — can we remove any values that don’t change the final result?

Turns out:
- Multiple 0s don’t help — once you’ve ORed with 0, more 0s don’t matter.
- Repeating the same value (e.g., `1,1,1`) gives the same result again and again.

So I cleaned the input to shrink the number of subarrays,  
without losing any unique OR values.

---

### ✅ Explanation of the Solution:
**Step-by-step:**

1. **Preprocessing:**
   - Keep only the **first occurrence of 0** (ignore the rest).
   - Remove **consecutive duplicates** from the array.

2. **Main Logic:**
   - Compute the **bitwise OR of every subarray** in the cleaned array.
   - Store the results in a set for uniqueness.
   - Stop early if the running OR hits the **maximum possible OR** (to avoid redundant work).

This works because we only remove redundant inputs, not ones that contribute new ORs.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n²) worst case, but typically better due to early stopping & preprocessing  
- **Space:** O(k) where `k` is the number of unique ORs (set + cleaned array)

---

### 💡 My Solution (C++):
```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& ar) {
        // Step 1: Remove all but one 0
        int zero_seen = 0;
        vector<int> no_extra_zeros;
        for (int x : ar) {
            if (x == 0) {
                if (!zero_seen) {
                    no_extra_zeros.push_back(0);
                    zero_seen = 1;
                }
            } else {
                no_extra_zeros.push_back(x);
            }
        }

        // Step 2: Remove consecutive duplicates
        vector<int> arr;
        for (int i = 0; i < no_extra_zeros.size(); ++i) {
            if (i == 0 || no_extra_zeros[i] != no_extra_zeros[i - 1]) {
                arr.push_back(no_extra_zeros[i]);
            }
        }

        // Step 3: Subarray ORs
        int greatest = 0;
        for (auto k : arr) greatest |= k;
        if (greatest == 0) return 1;

        unordered_set<int> hash;
        int n = arr.size();
        int live = 0;
        for (int i = 0; i < n; i++) {
            live = arr[i];
            for (int j = i; j < n; j++) {
                live |= arr[j];
                hash.insert(live);
                if (live == greatest) break;
            }
        }
        return hash.size();
    }
};

```
---

### 🧾 What I Learned:

- **Bitwise OR is monotonic** — adding more elements can only increase or retain the current OR value.
- **Cleaning the input** (e.g., collapsing redundant elements like extra 0s or consecutive duplicates) can massively improve efficiency.
- A **brute-force approach**, if trimmed smartly, can perform surprisingly well.
- Subarray problems are often about **recognizing repeated patterns** and optimizing them away.

---

### 🧠 Official Optimal Solution (Explanation + Code)

#### ✅ Intuition
We want all **distinct bitwise ORs** from all non-empty subarrays.  
Since **OR is monotonic** (once a bit is set, it stays set), we can avoid recomputing every subarray  
and instead build efficiently on top of previously computed OR values.

---

#### ✅ Approach
We iterate through the array and, for each number:

1. Start a new set `cur` that contains just `num`.
2. For every OR result `x` in the **previous** `cur`, compute `x | num` and insert it into `cur`.
3. Add all values from `cur` into the global result set `res`.
4. Set `cur` to the newly computed values (`next`).

This method avoids unnecessary recomputation and takes advantage of OR’s monotonic behavior.

---

#### ⏱️ Time Complexity:
- **O(n × log M)**  
  Where `n` is the size of the array and `M` is the maximum integer value in the array.  
  The log comes from the bit-length of the integers being OR’ed.

#### 📦 Space Complexity:
- **O(n)**  
  For storing intermediate sets (`cur`, `next`) and the final result set (`res`).

---

#### 💡 Code:
```cpp
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, next;
        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};
```