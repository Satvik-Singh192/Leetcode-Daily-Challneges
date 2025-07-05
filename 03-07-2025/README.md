## Problem: [3304. Find the K-th Character in String Game I](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/)

- **Status:** ✅ Solved  but not the best sol
- **Difficulty:** Easy  
- **Tags:** brute force, Bit Manipulation, Math, Recursion  

---

### ✅ Intuition:
My first approach was to simulate the process as described:

- Start with `"a"`  
- Repeatedly append the next-letter version of the entire string  
- Keep doing this until the string is long enough to return the k-th character

While this was straightforward and passed small inputs, I immediately realized that it was **too slow** for large values of `k` (e.g., `10^6` or beyond), since the string doubles each round, and the size grows exponentially.

So I started thinking—do I really need to build the string?
then i learnt the following from someone's solution
---

### ✅ Explanation of the Final Solution (Bit-Counting Trick):

After examining the pattern carefully, I realized that the string growth mimics a **binary recursion tree**.

Each operation doubles the string like this:

new_word = word + next(word)

Where `next(word)` is the same string with each character incremented (`'z' → 'a'` wrapped).

#### 🔍 What this means:
At every level of string doubling:

- The **first half** comes directly from the previous string.
- The **second half** is exactly the same, but with all characters **incremented by 1**.

So, to find the `k`-th character:
- If it's in the **first half**, it's the same as in the previous string.
- If it's in the **second half**, it's the same as some position in the first half **but incremented by 1**.

This continues recursively.

#### 🧠 Here's the amazing insight:
If you look at the **binary representation of `k - 1`**, each bit from **most significant to least** tells you:

- `0` → move to the first half → no increment  
- `1` → move to the second half → add `+1` to character

So, the **number of `1` bits in (k - 1)** tells you **how many times you went to the second half**, and therefore **how many times the character got incremented**.

#### ✨ Therefore:
The final character is simply:


---

### 🧠 Time & Space Complexity:
- **Time:** O(1)  
  (bit counting in an integer is constant time)
- **Space:** O(1)  

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};
```
### ✅ Things I Learnt Today:
- Simulation works but scales poorly for doubling patterns.
- Recursive divide-and-append structures often hide **binary properties**.
- Binary representation of an index can encode **the path of recursive decisions**.
- Each `1` in `k - 1`'s binary means you took the second half → added +1 to the character.

---

### 📌 Things for Future:
- Practice identifying problems with **binary-decision depth**.
- Study how problems like **K-th Symbol in Grammar** and similar divide-and-conquer problems relate to **bit manipulations**.
- Learn and practice standard binary operations like:
  - `__builtin_popcount` (C++)
  - `Integer.bitCount()` (Java)
  - `bin(x).count('1')` (Python)
- Explore more **O(1)** tricks using bitwise math in competitive programming.
