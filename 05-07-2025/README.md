## Problem: [1394. Find Lucky Integer in an Array](https://leetcode.com/problems/find-lucky-integer-in-an-array/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Hash Table, Array

---

### ✅ Intuition:
Just count the frequency of each number, then find the largest number whose frequency equals its value.

---

### ✅ Explanation of the Solution:
- Build a frequency map.
- Check for all numbers if `frequency == number`.
- Track the maximum such number, or return -1 if none exists.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;
        int ans = -1;
        for (auto& [num, count] : freq)
            if (num == count) ans = max(ans, num);
        return ans;
    }
};
