# LeetCode Daily Challenge Solution

## [2311. Longest Binary Subsequence Less Than or Equal to K](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/)

**Status**: Solved without any problem ✅  
**Difficulty**: Medium  
**Topics**: Greedy, Binary String, Bit Manipulation

### Intuition
1. **All '0's are free** - They can always be included since they add length without increasing value
2. **Rightmost '1's are most valuable** - When processed right-to-left (LSB to MSB), earlier '1's have lower place values
3. **Greedy selection** - Take rightmost '1's first to maximize length while keeping value ≤ k

### Approach
1. Count all '0's (always included)
2. Process right-to-left:
   - Track current bit position (power of 2)
   - For each '1':
     - Check if inclusion would exceed k
     - If safe, add to count and update running sum
     - Else continue (don't break to count remaining '0's)

### Complexity
- **Time**: O(n) - Single pass
- **Space**: O(1) - Constant space

### Improvements
- **Bit Shifting**: 
  - Replaced `pow(2, power)` with `(1 << power)`
  - Bit operations are faster and more precise than floating-point `pow()`
  
- **Overflow Protection**:
  - Added `power < 30` check since 2³⁰ > 1e9 (problem constraints)
  - Prevents potential integer overflow

- **Code Clarity**:
  - Renamed variables for better readability:
    - `position` → `power`
    - `sum` → `current_value`
  - Removed early break to handle all '0's consistently

### Key Insights
- Right-to-left processing naturally handles binary place values
- Early value checks optimize performance
- Problem reduces to careful '1's selection after including all '0's

### Solution Code
See separate [C++ implementation](./Longest_Binary_Subsequence_Less_Than_or_Equal_to_K.cpp

)

### Reflection
- Practiced bit manipulation optimizations
- Reinforced greedy algorithm principles
- Learned importance of overflow protection