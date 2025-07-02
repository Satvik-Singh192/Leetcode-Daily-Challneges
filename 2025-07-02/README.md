## Problem: [3333. Find the Original Typed String II](https://leetcode.com/problems/find-the-original-typed-string-ii/)

- **Status:** ✅ Solved (but had to copy solution)  
- **Difficulty:** Hard  
- **Tags:** String, DP

---

### ✅ Intuition:
I got **cooked** today—it was brutal.  

My initial idea:  
> For example, for `aaabbccaa`, I converted it to the **root word** `abca` and counted extra frequencies:  
> - a: 3  
> - b: 1  
> - c: 1  
>  
> I thought I could reduce the problem to choosing extra repeats so that total length ≥ k, by finding integer solutions for **length = k - root.size()** using the extra frequencies.  

But I **got stuck**:  
> I didn't know how to count the combinations correctly while respecting the max repeats in each group (since you can't pick more than the available count).  
> I also didn't see how to handle the modulo constraint or avoid overcounting.  

Eventually I had to **copy the DP solution**.  

---

### ✅ Explanation of the Copied Solution:

The solution is in two parts:

#### 1️⃣ Count all unrestricted ways
- Each group of repeated characters can be typed **in any length from 1 to its given count**.  
- Total ways without length restriction = **product of group sizes**.  
> Example: groups = [3,2] → ways = 3 * 2 = 6.  
- This counts *all* possible strings Alice could have intended.

---

#### 2️⃣ Remove invalid cases (length < k)
- We want **strings of length at least k**.
- We use **DP** to count how many ways yield total length < k.  
- For each group:
  - We can choose **1 to count** repeats.
  - DP tracks number of ways to reach each total length.
  - Use a **sliding window** to limit choices for each group.

---

#### 3️⃣ Final answer
- Total ways (unrestricted) − ways with length < k.  
- Make sure result is **non-negative modulo 10^9+7**.  

---

### 🧠 Time & Space Complexity:
- **Time:** O(n * k)  
- **Space:** O(k)

---

### 💡 Solution (C++):
```cpp
class Solution {
    static const int MOD = 1e9 + 7;

public:
    int possibleStringCount(std::string word, int k) {
        if (word.empty()) return 0;

        std::vector<int> groups;
        int count = 1;
        for (size_t i = 1; i < word.size(); ++i) {
            if (word[i] == word[i - 1]) count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        // Count all unrestricted ways
        long long total = 1;
        for (int num : groups)
            total = (total * num) % MOD;

        // If all lengths are valid
        if (k <= (int)groups.size()) return total;

        // DP to count invalid ways (length < k)
        std::vector<int> dp(k, 0);
        dp[0] = 1;

        for (int num : groups) {
            std::vector<int> newDp(k, 0);
            long long sum = 0;
            for (int s = 0; s < k; ++s) {
                if (s > 0) sum = (sum + dp[s - 1]) % MOD;
                if (s > num) sum = (sum - dp[s - num - 1] + MOD) % MOD;
                newDp[s] = sum;
            }
            dp = newDp;
        }

        // Sum all invalid (length < k) ways
        long long invalid = 0;
        for (int s = groups.size(); s < k; ++s)
            invalid = (invalid + dp[s]) % MOD;

        return (total - invalid + MOD) % MOD;
    }
};
```
### ✅ Things I Learnt Today:
- Breaking repeated characters into **groups** is a key observation.
- Counting *all unrestricted ways* is just a **product** of group sizes.
- **DP with sliding window** is useful to count number of ways to form limited-length sums under group constraints.
- Always **subtract invalid cases** to get valid ones (inclusion-exclusion idea).
- Be careful with **modulo subtraction** to avoid negatives.

---

### 📌 Things for Future:
- Practice **"integer partition with upper bounds"** DP.
- Get better at **sliding window DP** patterns.
- Study **Inclusion-Exclusion** for counting.
- Be comfortable with **modulo arithmetic** (especially subtraction).
- Review similar LeetCode DP problems (like “Coin Change with limits”).
