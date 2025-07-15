## Problem: [3136. Valid Word](https://leetcode.com/problems/valid-word)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** String, Validation  

---

### ✅ Intuition:
Check if the word has at least 3 characters, only alphanumeric characters, at least one vowel, and at least one consonant.

---

### ✅ Approach:
- Return false if length < 3  
- Loop through characters:  
  - If not alphanumeric → return false  
  - If letter:  
    - If vowel → set `vowel_found = true`  
    - Else → set `consonant_found = true`  
- Return true if both flags are true

---

### 💡 Code (C++):
```cpp
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool vowel = false, consonant = false;
        for (char c : word) {
            if (!isalnum((unsigned char)c)) return false;
            c = tolower(c);
            if (isalpha(c)) {
                if (string("aeiou").find(c) != string::npos) vowel = true;
                else consonant = true;
            }
        }
        return vowel && consonant;
    }
};
```