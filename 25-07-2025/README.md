## Problem: [3487. Maximum Unique Subarray Sum After Deletion](https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Hash Map, Set, Greedy, Array

---

### ✅ Intuition:
The goal is to find the maximum sum of a subarray with all unique elements, allowing us to delete elements to enable such a subarray. The key insight is:
- We only want to consider each number once (i.e., uniqueness is enforced).
- Positive numbers increase the sum, so we want to keep as many unique positive numbers as possible.
- If all numbers are negative, we must choose the least negative one.

This led to using a hash map to track duplicates and summing only unique non-negative numbers.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. If the array contains only one element, return that element directly.
2. Initialize:
   - A hash map (`unordered_map`) to track already processed numbers.
   - `positive_present` to sum unique non-negative numbers.
   - `negative_only` to store the largest negative number in case all numbers are negative.
3. Iterate through each number:
   - Skip if it’s already been seen.
   - If it’s non-negative, add to `positive_present`.
   - If it’s negative, update `negative_only` if it's the largest seen so far.
4. If no positive number was found, return the maximum negative number.
5. Otherwise, return the sum of unique non-negative numbers.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(n) – due to the hash map used for tracking duplicates

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int positive_present = -1;
        int negative_only = INT_MIN;

        unordered_map<int, int> hash;
        for (auto k : nums) {
            if (hash[k] > 0) continue;
            hash[k]++;
            if (k >= 0) {
                if (positive_present == -1) positive_present = 0;
                positive_present += k;
            } else {
                if (k > negative_only) negative_only = k;
            }
        }

        if (positive_present == -1) return negative_only;
        return positive_present;
    }
};
