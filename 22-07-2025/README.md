## Problem: [1695. Maximum Erasure Value](https://leetcode.com/problems/maximum-erasure-value/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** Sliding Window, HashMap, Prefix Sum, Two Pointers  

---

### ✅ Intuition:
I noticed that the problem asks for a subarray with all *unique* elements and the *maximum* possible sum. This suggested using a sliding window to dynamically track a window of unique elements. As soon as a duplicate appears, we shrink the window from the left to remove it, maintaining uniqueness.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. Use two pointers `left` and `right` to define a sliding window.
2. Keep a running `sum` of the current window and maintain a `hash map` to track the last index of each element.
3. If the new element already exists within the window (i.e., its index is ≥ `left`), update `left` to `duplicate_index + 1` and remove that portion’s sum using precomputed prefix sums.
4. Update `sum`, move `right`, and track the maximum value of `sum` seen so far.

This approach ensures we always maintain a window of unique elements while maximizing the sum.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n) — Each element is visited at most twice (once by `right`, once by `left`)  
- **Space:** O(n) — For hash map and prefix sum array

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int ans = INT_MIN;
        int sum = nums[0];
        int left = 0;
        int right = 0;

        vector<int> precompute(n, 0);
        precompute[0] = nums[0];
        for (int i = 1; i < n; i++) {
            precompute[i] = precompute[i - 1] + nums[i];
        }

        unordered_map<int, int> hash;
        hash[nums[0]] = 0;

        while (right < n - 1) {
            int new_index = right + 1;
            int key = nums[new_index];

            if (hash.count(key) && hash[key] >= left) {
                int duplicate_index = hash[key];
                int removed = 0;
                if (left == 0) {
                    removed = precompute[duplicate_index];
                } else {
                    removed = precompute[duplicate_index] - precompute[left - 1];
                }
                sum -= removed;
                left = duplicate_index + 1;
            }

            sum += key;
            right = new_index;
            hash[key] = right;
            ans = max(ans, sum);
        }

        ans = max(ans, sum);
        return ans;
    }
};
