## Problem: [1717. Maximum Score From Removing Substrings](https://leetcode.com/problems/maximum-score-from-removing-substrings/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** `Greedy`, `Stack`, `String`, `Simulation`

---

### ✅ Intuition:
The problem involves removing substrings `"ab"` and `"ba"` for points `x` and `y` respectively. The challenge is to maximize the total points by optimally choosing the order and occurrences of removals.  
My initial idea was to simulate removals using stacks, removing the substring with the higher value first, then removing the other from the leftover characters.

---

### 🔹 My Approach (Using Two Stack Passes):

**Step-by-step:**
1. Determine which substring, `"ab"` or `"ba"`, has the higher score (`x` or `y`).
2. Use a stack to scan the string from left to right and greedily remove all occurrences of the higher-value substring.
3. After this first pass, reconstruct the leftover string from the stack.
4. Use a second pass with another stack to remove the other substring from the leftover string.
5. Sum the points earned in both passes.

This approach simulates the removals explicitly and is intuitive, but requires two traversals and additional space for stacks.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n) — two linear passes over the string.  
- **Space:** O(n) — for stack storage.

---

### 💡 My Stack-Based Solution (C++):

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string prime_target, sec_target;
        int prime_val, sec_val;

        if (x >= y) {
            prime_target = "ab";
            sec_target = "ba";
            prime_val = x;
            sec_val = y;
        } else {
            prime_target = "ba";
            sec_target = "ab";
            prime_val = y;
            sec_val = x;
        }

        int ans = 0;
        stack<char> st;

        // First pass: remove prime_target
        for (char c : s) {
            if (!st.empty() && st.top() == prime_target[0] && c == prime_target[1]) {
                ans += prime_val;
                st.pop();
            } else {
                st.push(c);
            }
        }

        // Reconstruct remaining string
        string leftover = "";
        while (!st.empty()) {
            leftover += st.top();
            st.pop();
        }
        reverse(leftover.begin(), leftover.end());

        // Second pass: remove sec_target from leftover
        for (char c : leftover) {
            if (!st.empty() && st.top() == sec_target[0] && c == sec_target[1]) {
                ans += sec_val;
                st.pop();
            } else {
                st.push(c);
            }
        }

        return ans;
    }
};
```
---

### 🔹 Best Optimized Approach (Greedy + Counting):

**Step-by-step:**

1. If `y > x`, reverse the string and swap `x` and `y` so that `"ab"` is always the higher scoring substring.  
2. Traverse the string once, using counters to greedily remove `"ab"` substrings:  
   - When you see a `'b'` and you have leftover `'a'`s, remove `"ab"` and add `x` points.  
3. For characters other than `'a'` or `'b'`, calculate how many `"ba"` substrings can be removed from leftover `'a'`s and `'b'`s and add `y` points accordingly.  
4. After the loop ends, remove any leftover `"ba"` substrings from remaining counts.  
5. Return the total score.

This approach uses a single pass and constant space, providing a more optimal and elegant solution.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n) — single pass through the string.  
- **Space:** O(1) — only counters are used.

---

### 💡 Optimized Greedy Solution (C++):

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }
        int ans = 0, a_count = 0, b_count = 0;

        for (char c : s) {
            if (c != 'a' && c != 'b') {
                ans += min(a_count, b_count) * y;
                a_count = 0;
                b_count = 0;
            } else {
                if (c == 'b') {
                    if (a_count > 0) {
                        a_count--;
                        ans += x;
                    } else {
                        b_count++;
                    }
                } else {
                    a_count++;
                }
            }
        }
        ans += min(a_count, b_count) * y;
        return ans;
    }
};
```
📝 What I Learned:
Stack simulation works but can be less optimal: My initial stack approach was intuitive but required multiple passes and extra space.

Greedy logic combined with string reversal is powerful: Transforming the problem so one substring is always the priority simplifies logic.

Counting leftover characters for the second substring is efficient: This reduces space and speeds up the solution.

Attention to edge cases: Handling leftovers after the main loop is crucial.

Always question if a more optimal approach exists: My optimized approach emerged after exploring and discussing the problem.
