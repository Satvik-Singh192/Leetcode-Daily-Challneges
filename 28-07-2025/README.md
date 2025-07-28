## Problem: [2044. Count Number of Maximum Bitwise-OR Subsets](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** `Bit Manipulation`, `Backtracking`, `DFS`, `Recursion`

---

### ✅ Intuition:
The problem is asking how many subsets of the given array produce the **maximum possible bitwise OR**. A key realization is that bitwise OR is **monotonic**—adding more elements to a subset cannot decrease the OR. So we can compute the maximum OR first, and then count how many subsets achieve that.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. Compute the **maximum OR** by taking the bitwise OR of all elements in the array. This is the best OR any subset can achieve.
2. Use **Depth-First Search (DFS)** to recursively generate all possible subsets.
3. At each recursive call:
   - You have the option to **include** or **exclude** the current number.
   - You maintain a running `curr` OR value.
4. Once you've considered all elements (`index == nums.size()`), check if the current OR equals the maximum OR.
   - If yes, increment the count.
5. The count is returned at the end.

---

### 🧠 Time & Space Complexity:
- **Time:** O(2ⁿ), where `n` is the size of the input array (each subset is explored).  
- **Space:** O(n), for the recursion stack during DFS.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int count = 0;
    int maxor = 0;

    void dfs(vector<int>& nums, int curr, int index) {
        if (index == nums.size()) {
            if (curr == maxor) count++;
            return;
        }

        // Include nums[index]
        dfs(nums, curr | nums[index], index + 1);

        // Exclude nums[index]
        dfs(nums, curr, index + 1);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (auto k : nums) maxor |= k;
        dfs(nums, 0, 0);
        return count;
    }
};
s