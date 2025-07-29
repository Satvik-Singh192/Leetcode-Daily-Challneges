## Problem: [2411. Smallest Subarrays With Maximum Bitwise OR](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** `Greedy`, `Bit Manipulation`, `Sliding Window`, `Suffix Processing`

---

### ✅ Intuition:
From each index `i`, we need to find the **shortest subarray starting at `i`** such that its **bitwise OR equals the OR of the entire suffix** from `i` to the end.  
The key insight is that for the OR to match the suffix, we must include **all the bits that appear anywhere in the suffix**, starting at `i`.  
So we can process the array **backwards**, and track for each bit position the **latest index** it appears in the suffix. This tells us how far we must extend the subarray starting at `i`.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. Traverse the array in reverse (from right to left).
2. For each index `i`, update the latest position for every bit set in `nums[i]`.
3. Keep track of the **furthest index** (say `j`) where any currently-needed bit is set.
4. The shortest subarray starting at `i` must extend up to `j`, so length = `j - i + 1`.
5. Store this result in the answer array.

This greedy approach ensures that we include only the necessary elements to capture all required bits, and processing right to left ensures the latest positions are always correctly tracked.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n × 30) — for each of `n` indices, we check up to 30 bits  
- **Space:** O(30 + n) → `last[30]` + `ans[n]`

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        vector<int> last(30, -1); // Last seen index for each bit

        for (int i = n - 1; i >= 0; --i) {
            int j = i;
            bitset<30> X(nums[i]);
            for (int b = 0; b < 30; ++b) {
                if (X[b]) last[b] = i;
                j = max(j, last[b]);
            }
            ans[i] = j - i + 1;
        }

        return ans;
    }
};
