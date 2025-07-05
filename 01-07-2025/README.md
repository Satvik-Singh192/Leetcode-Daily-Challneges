## Problem: [3330. Find the Original Typed String I](https://leetcode.com/problems/find-the-original-typed-string-i/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** String

### ✅ Intuition:
Alice typed a string, but she may have long-pressed one key **at most once**, resulting in **a character being repeated consecutively**.  
We need to determine how many possible **original** strings could have been intended, assuming **only one group of repeated characters** might be extra.

Every time we find a group of repeated adjacent characters, it represents a chance that **only one of them was originally intended**, and the rest are due to a long press.

We can only choose one such group (due to the "at most once" constraint), so the total number of possible original strings is:

> `1 + (number of groups of repeated characters)`

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(1)

---

### 💡 Solution (C++):

```cpp
class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        int n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            if (word[i] == word[i + 1]) {
                ++ans;
                while (i < n - 1 && word[i] == word[i + 1]) {
                    ++i; // skip the rest of the duplicates in this group
                }
            }
        }
        return ans;
    }
};
