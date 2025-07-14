## Problem: [1290. Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Linked List, Math, Bit Manipulation  

---

### ✅ Intuition:
The linked list stores **binary digits from MSB to LSB**.  
Initially, it might seem you'd need the length to know powers of 2. But because the MSB comes first, you can directly simulate conversion:

> At each node, shift the current result left (multiply by 2) and add the node's value.

This approach doesn't require knowing the length in advance or precomputing powers of 2.

---

### ✅ Explanation of the Solution:
**Step by step:**
1. **Initialize** a result variable to 0.
2. **Traverse** the linked list node by node.
3. For each node:
   - Multiply the result by 2 (left shift).
   - Add the node’s value.
4. Continue until the end of the list.
5. **Return** the final result.

**Why it works:**  
Multiplying by 2 shifts the current bits left, making space for the new bit. Adding the new bit places it in the correct spot. This process mimics binary number construction from MSB to LSB.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
  - One pass through the linked list.
- **Space:** O(1) extra  
  - Just a single integer for accumulation.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != nullptr) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};
```