## Problem: [2106. Maximum Fruits Harvested After at Most K Steps](https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps)
- Status: ✅ Solved
- Difficulty: Medium
- Tags: Sliding Window, Greedy, Two Pointers

---

### ✅ Intuition:
Okay, so imagine you're standing at a spot on the number line (`startPos`) and you can take at most `k` steps. There's fruit at different positions, and you wanna collect as much as you can.

At first, I thought: what if we just try going a little left, then right? Or just go right? Or all the way left? But trying every combo sounds slow.

Then I realized — we can **slide a window** across the fruit positions and just keep track of how much fruit we can get within our step limit.

---

### ✅ Explanation of the Solution:
1. Use two pointers: `left` and `right` to make a sliding window over the sorted `fruits` list.
2. For every window `[left, right]`, we check how many total fruits we can collect in that range.
3. We calculate how many steps it would take to go from `startPos` and collect from `fruits[left][0]` to `fruits[right][0]`.
4. If it’s within the step limit `k`, we check if the total fruit in this window is a new max.
5. If it exceeds `k`, we move the `left` pointer forward to shrink the window.
6. A helper function `minSteps()` handles different movement strategies: only left, only right, or left-then-right (or vice versa).

---

### 🧠 Time & Space Complexity:
- Time: O(n)  
  Each fruit is visited at most twice — once by the left pointer and once by the right pointer.
- Space: O(1)  
  No extra space is used except a few integer variables.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, right = 0;
        int currentSum = 0, maxSum = 0;

        while (right < n) {
            currentSum += fruits[right][1]; // pick fruit at 'right'

            // If too far from startPos, shrink the window from the left
            while (left <= right && minSteps(fruits, startPos, left, right) > k) {
                currentSum -= fruits[left][1];
                left++;
            }

            maxSum = max(maxSum, currentSum); // update max
            right++; // expand window
        }

        return maxSum;
    }

private:
    int minSteps(const vector<vector<int>>& fruits, int startPos, int left, int right) {
        int leftPos = fruits[left][0];
        int rightPos = fruits[right][0];

        if (rightPos <= startPos) {
            // Only go left
            return startPos - leftPos;
        } else if (leftPos >= startPos) {
            // Only go right
            return rightPos - startPos;
        } else {
            // Go to one side first, then the other
            return min(startPos - leftPos, rightPos - startPos) + (rightPos - leftPos);
        }
    }
};
```