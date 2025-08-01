## Problem: [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/)
- Status: ✅ Solved
- Difficulty: Easy
- Tags: Arrays, Dynamic Programming

---

### ✅ Intuition:
The first and last elements of each row in Pascal’s Triangle are always 1.  
Every other element is formed by summing the two elements just above it (from the previous row).  
So we can construct each row iteratively using the row above.

---

### ✅ Explanation of the Solution:
1. Start with an empty 2D vector `ans` to store the result.
2. Loop from `i = 0` to `numRows - 1`:
   - Create a row `temp` of size `i + 1`, initialized to 1.
   - For each inner index `j = 1` to `i - 1`, update `temp[j]` using:
     ```cpp
     temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
     ```
   - Append `temp` to `ans`.
3. Return `ans` after building all rows.

---

### 🧠 Time & Space Complexity:
- Time: O(n²) — where `n = numRows`. Each row requires up to `i` computations.
- Space: O(n²) — storing all rows of the triangle.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
