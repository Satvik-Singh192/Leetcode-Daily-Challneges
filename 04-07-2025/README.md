## Problem: [3307. Find the K-th Character in String Game II](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/)

- **Status:** Not Solved  
- **Difficulty:** Hard  
- **Tags:** Strings, Simulation, Bit Manipulation

---

### ✅ Intuition:
My first thought was to simulate the string operations by tracking its length.  

- Each operation doubles the string:
  - op = 0 → append original
  - op = 1 → append next(original)
- I realized you can’t build the whole string because k can be as big as 1e14.

So I tried working **backwards**:

- At each step, the final string is twice as long as before.
- I tried to figure out if k was in the first half or second half.

But I got stuck because my initial code used:

```cpp
power = 1;
power <<= (i+1);
```

which was wrong. It miscalculated the length at each step.

I then learned the correct way is to keep the real length and halve it at each step to check if k is in the second half.
### ✅ Explanation of the Solution:

---

#### 1️⃣ Reverse-halving approach (first correct idea):

The final string length after all operations is **2^n**.  

But you don't want to build it.  

Instead, process operations **backwards**:

- Start with the full length.
- Each time halve the length.
- If `k > half`, it means your target letter came from the second half.
  - For `op=0`, second half is same → no shift.
  - For `op=1`, second half is shifted → +1 shift.
- Subtract half from k if you’re in the second half.

This approach keeps track of how many shifts (+1) accumulate as you trace back.

✅ At the end, result = `'a' + (shift % 26)`.

**Example:**
operations = [0,1,0,1]
k = 10
Total length = 16

i=3: length=8, k=10>8 → k=2, op=1 → shift=1
i=2: length=4, k=2≤4 → nothing
i=1: length=2, k=2≤2 → nothing
i=0: length=1, k=2>1 → k=1, op=0 → no shift

Final shift = 1 → answer = 'b'.


---

#### 2️⃣ Godlike bit manipulation insight:

The string doubling can be seen as **a binary tree**.  

Each bit in `k−1` tells you if you took:

- `0` → first half (no shift)
- `1` → second half (maybe shifted)

But not every right move shifts!  

✅ Only when `op[i] == 1`.  

✅ **Formula for total shift:**

total_shift = sum over all i of (bit_i of (k−1)) AND op[i]


**Why k−1?**

- Because indices are 1-based in the problem.
- By subtracting 1, the binary representation of k−1 directly encodes your path in the binary doubling tree.

**Example:**
k = 10
k−1 = 9 = 1001 (binary)
bits = [1,0,0,1]

operations = [0,1,0,1]

Compute:
bit 0 & op[0] = 1 & 0 = 0
bit 1 & op[1] = 0 & 1 = 0
bit 2 & op[2] = 0 & 0 = 0
bit 3 & op[3] = 1 & 1 = 1

Total shift = 1
Answer = 'a' + 1 = 'b'


✅ This method reads each bit of `k−1` (via `k & 1`) and right-shifts k to process all bits, aligning with the levels of the operations array.

It is extremely clean and efficient:

- No length tracking
- No halving
- O(number of bits in k) time

---

### 🧠 Time & Space Complexity:
- **Time:** O(log k) — each bit of k is processed once
- **Space:** O(1) — just counters and shifts

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    char kthCharacter(long long k, vector<int>& arr) {
        int shift = 0; 
        k--;
        for (int i = 0; k != 0; i++, k >>= 1) {
            if ((k & 1) && arr[i]) {
                shift++;
            }
        }
        return (char)('a' + (shift % 26));
    }
};
```

### ✅ Things I Learnt Today:
- How to **work backwards** in a doubling string to find k-th character.
- How to **halve length** at each step and adjust k.
- The **bit manipulation trick**: representing path in a doubling tree via binary of k−1.
- Each bit in k−1 directly encodes left/right choices in the sequence of operations.

---

### 📌 Things for Future:
- Practice **reversing generation rules** in string problems.
- Study **bitwise tricks** for representing paths or choices.
- Look for other problems with **doubling/halving** structures.
- Think carefully about **1-based vs 0-based indexing** and why k−1 is used.


