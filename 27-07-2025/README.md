## Problem: [2210. Count Hills and Valleys in an Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** `Array`, `Simulation`

---

### ✅ Intuition:
The problem defines a "hill" as an index with **closest non-equal neighbors smaller** than itself, and a "valley" as an index with **closest non-equal neighbors greater** than itself. 

Since elements can be repeated, we must **skip over equal adjacent values** to find the **true left and right non-equal neighbors**. Once we determine the relationship with both sides, we can classify it as a hill or valley.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. Iterate through the array from index `1` to `n-2` since hills/valleys require both left and right neighbors.
2. Skip the current index if it’s equal to the previous one, as we want to compare only with **non-equal** neighbors.
3. From the current index `i`, scan **backwards** to find the first element not equal to `nums[i]`. Determine if it’s smaller (`-1`) or greater (`+1`) and save it as `left`.
4. Similarly, scan **forward** to find the first non-equal neighbor on the right, store its comparison in `right`.
5. If `left == right` and neither is zero, then `nums[i]` is either:
   - a hill (`left == right == -1`) or
   - a valley (`left == right == 1`)
6. Increment the count for each such occurrence.
7. Return the total count.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n²) in the worst case (if all elements are equal and we need to scan far to find non-equal neighbors).
- **Space:** O(1), constant extra space.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;  
        int n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            int left = 0;  
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] > nums[i]) {
                    left = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    left = -1;
                    break;
                }
            }
            int right = 0;  
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    right = 1;
                    break;
                } else if (nums[j] < nums[i]) {
                    right = -1;
                    break;
                }
            }
            if (left == right && left != 0) {
                ++res;
            }
        }
        return res;
    }
};
