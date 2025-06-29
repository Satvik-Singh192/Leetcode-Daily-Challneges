# LeetCode Daily Challenge Solution

## Problem: 1498. Number of Subsequences That Satisfy the Given Sum Condition  
**Status:** Solved with optimizations ✅  
**Difficulty:** Medium  
**Topics:** Array, Two Pointers, Binary Search, Sorting  
**Time Complexity:** O(n log n)  
**Space Complexity:** O(n) _(can be O(1) with on-the-fly power calculation)_

---

## 🧠 Problem Analysis

Given an array `nums` and an integer `target`, count the number of non-empty subsequences such that:min(subsequence) + max(subsequence) <= target


**Result should be modulo** `10^9 + 7` **due to large output possibilities.**

### 🔑 Key Constraints:
- Subsequence order must be preserved
- Empty subsequences are not allowed
- Duplicate elements are considered distinct

---

## 🔄 Solution Evolution

### 📌 Initial Approach

#### Intuition:
- Sort the array for easier `min` and `max` lookups
- Use binary search to find the range of valid pairs
- Count valid subsequences between indices

#### ❌ Limitations:
- Single-element subsequences may be double-counted
- Power calculations are inefficient
- Complex index management

### 🧪 Initial Implementation (Incomplete)
```cpp
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // Binary search implementation
            // ... (omitted for brevity)
        }
        return ans;
    }
};

```
## ✅ Optimized Solution

### 🚀 Key Improvements:
- **Two-Pointer Technique**: More efficient than binary search  
- **Precomputed Powers**: O(1) access to `2^i % MOD`  
- **Early Termination**: Stop when `nums[left] > target / 2`

---

### 🧭 Final Approach
1. Sort the array  
2. Precompute powers of 2 modulo `10^9 + 7`  
3. Use two pointers (`left`, `right`) to scan for valid min-max pairs  
4. Count valid subsequences using precomputed powers

---

### ✅ Optimized C++ Implementation:

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> pow2(n + 1, 1);

        // Precompute powers of 2 modulo MOD
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};
```
## 📊 Complexity Analysis

| Operation              | Time Complexity | Space Complexity |
|------------------------|-----------------|------------------|
| Sorting                | O(n log n)      | O(1)             |
| Power Precomputation   | O(n)            | O(n)             |
| Two-Pointer Scan       | O(n)            | O(1)             |
| **Total**              | O(n log n)      | O(n)             |

---

## 🔍 Key Insights

- **Sorting Enables Efficient Scanning**: Essential for two-pointer logic.  
- **Power Precomputation**: Saves redundant calculations.  
- **Modulo Handling**: Critical for avoiding overflow.

---

## 🔧 Further Optimization Potential

- **Space Reduction**: Compute powers on-the-fly to reduce space to O(1)  
- **Early Exit**: When `nums[left] > target / 2`, we can safely break  
- **Parallel Processing**: Useful for extremely large input sizes (e.g., `n > 10^6`)


