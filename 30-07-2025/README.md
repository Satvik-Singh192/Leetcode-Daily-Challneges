## Problem: [2419. Longest Subarray With Maximum Bitwise AND](https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** `Array`, `Bit Manipulation`, `Sliding Window`

---

### ✅ Intuition:
The maximum bitwise AND possible in any subarray will be equal to the maximum element in the array. This is because bitwise AND only clears bits — any number less than the maximum will have at least one less set bit, reducing the AND result.

So the only subarrays that can achieve the maximum bitwise AND are those consisting **only** of the maximum element.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. Find the maximum element in the array.
2. Iterate through the array and track the length of the current contiguous subarray where all elements equal this maximum.
3. Keep updating the maximum length seen so far.
4. Return the maximum such length.

This approach is correct because:
- Any subarray with a number less than the maximum will reduce the bitwise AND.
- Only contiguous segments of max elements can give the result.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(1)

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int greatest = INT_MIN;
        for (auto k : nums) greatest = max(k, greatest);

        int ans = 1;
        bool flag = false;
        int live = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == greatest) {
                if (flag) live++;
                else live = 1;
                flag = true;
            } else {
                flag = false;
            }
            ans = max(live, ans);
        }

        return ans;
    }
};
