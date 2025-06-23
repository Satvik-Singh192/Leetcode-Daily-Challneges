# [2081. Sum of k-Mirror Numbers](https://leetcode.com/problems/sum-of-k-mirror-numbers/)

## Approach
### My Initial Approach
1. **Trivial Solutions (1 to k-1)**  
   First, I observed that every integer from `1` to `k-1` is trivially a k-mirror number because:
   - Their base-10 and base-`k` representations are single-digit palindromes (e.g., `7` in base-8 is still `7`).
   - Added these to the result first.

2. **Generating Palindromes in Base-`k`**  
   I initially tried generating all palindromic numbers directly in base-`k` (to avoid brute-forcing base-10 numbers), but:
   - The logic became overly complex (mirroring digits, handling even/odd lengths).
   - Conversion from base-`k` to base-10 introduced precision issues.

### Refined Approach (After Learning)
1. **Generate Palindromes in Base-10**  
   - Instead of base-`k`, I generated palindromes in base-10 by:
     - **Even-length**: Mirror the first half (e.g., `12` → `1221`).
     - **Odd-length**: Mirror around a middle digit (e.g., `123` → `12321`).
   - This ensured numbers were generated in ascending order.

2. **Check Base-`k` Palindromes**  
   - For each base-10 palindrome, converted it to base-`k` and checked if it was also a palindrome.
   - **Key Insight**: It’s easier to generate ordered palindromes in base-10 than in base-`k`.

## Solution Code
```cpp
// Link to your C++ solution file (e.g., `2081-sum-of-k-mirror-numbers.cpp`)