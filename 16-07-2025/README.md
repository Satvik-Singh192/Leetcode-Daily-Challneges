## Problem: [3201. Find the Maximum Length of Valid Subsequence I](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** Greedy, Dynamic Programming, Parity, Two Pointers  

---

### ✅ Intuition:
The key observation is that the problem divides naturally into two cases:  
- For **all adjacent sums even**, the subsequence must have elements of the **same parity** (all even or all odd).  
- For **all adjacent sums odd**, the subsequence must **alternate** between even and odd elements.  

So the longest valid subsequence is simply the best we can get in either of these two cases.

---

### ✅ Explanation of the Solution:
**Step by step:**  
1. **Count the number of odd and even numbers** in the array.  
   - Any subsequence of all odd or all even elements will have all adjacent sums even.  
   - So for the "even sums everywhere" case, the answer is `max(countOdds, countEvens)`.  
2. **Find the longest alternating sequence** of even and odd elements for the "all adjacent sums odd" case.  
   - This requires building a subsequence that strictly alternates in parity.  
   - We use a greedy approach that checks both starting with even and starting with odd.  
3. **Return the maximum** of these two possibilities.

**Why it works:**  
- Even + even and odd + odd give even sums → that's the first case.  
- Even + odd and odd + even give odd sums → that's the second case.  
- Considering both patterns ensures we never miss the optimal solution.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
  - Single pass to count odds/evens.  
  - Two passes to compute the maximum alternating subsequence length.  
- **Space:** O(1) extra  
  - Just counters and a couple of booleans.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int helper(vector<int>& nums, bool needOdd) {
        int res = 0;
        for (int v : nums) {
            if (v % 2 == needOdd) {
                res++;
                needOdd = !needOdd;
            }
        }
        return res;
    }

    int maximumLength(vector<int>& nums) {
        int countOdd = 0, countEven = 0;
        for (int v : nums) {
            if (v % 2 == 0) countEven++;
            else countOdd++;
        }
        int maxEvenSum = max(countOdd, countEven);

        int maxOddSum = max(helper(nums, true), helper(nums, false));

        return max(maxEvenSum, maxOddSum);
    }
};
```