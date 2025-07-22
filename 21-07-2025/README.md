## Problem: [1957. Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** String, Greedy, Two Pointers  

---

### ✅ Intuition:
The problem requires us to remove characters so that no three consecutive characters are the same. The key observation is that we can iterate through the string while checking if the current character and the two preceding ones are the same. If they are, skip the current character; otherwise, add it to the result. This simple greedy check ensures we preserve as many characters as possible while still satisfying the "fancy" condition.

---

### ✅ Explanation of the Solution:
**Step-by-step:**
1. If the string length is less than 3, return it as is — it can't have three repeating characters.
2. Initialize the result `ans` with the first two characters.
3. Iterate from the third character onward.
4. For each character, check if it and the two previous characters are equal.
5. If yes, skip adding the character.
6. If not, append it to the result.
7. Finally, return the built string.

This guarantees that no segment of the result will have three equal consecutive characters.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n) — Single pass through the string  
- **Space:** O(n) — For storing the output string

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;

        string ans = "";
        ans += s[0];
        ans += s[1];

        int n = s.size();
        for(int i = 2; i < n; i++) {
            if(s[i] == s[i-1] && s[i] == s[i-2]) {
                continue;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
