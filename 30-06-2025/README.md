## Problem: [594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Hash Table, Sorting 

### ✅ Intuition:
Use a frequency map to count occurrences of each number.  
For every key, check if `key + 1` exists, and if so, update the answer with the sum of their frequencies.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(n)

---

### 💡 Solution (C++):

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        int ans = 0;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            auto next_it = hash.find(it->first + 1);
            if (next_it != hash.end()) {
                ans = max(ans, it->second + next_it->second);
            }
        }
        return ans;
    }
};
