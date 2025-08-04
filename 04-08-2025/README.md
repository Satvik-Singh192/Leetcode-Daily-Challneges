# 904. Fruit Into Baskets - 04-08-2025

## Problem Description

You're walking through a row of fruit trees. Each tree gives one type of fruit, and you can carry only **2 types** using **2 baskets**. Starting at any tree, you must collect **one fruit from each tree moving to the right**, but **stop as soon as you hit a third type**.

Your goal? **Grab the max number of fruits** in one go!

Example:
```text
Input:  [1,0,1,4,1,4,1,2,3]  
Output: 5
```
## Approach

We use the **Sliding Window** technique with two baskets (variables) to track the current fruit types.

### 🔑 Key Variables:

- `type1` and `type2`: Current fruit types in our two baskets.
- `live1` and `live2`: Number of fruits of `type1` and `type2` in the current window.
- `last1`, `last2`: Last seen positions of `type1` and `type2`.
- `left`, `right`: Window pointers.
- `ans`: Stores the maximum fruit count collected so far.

---

### ⚙️ How it works:

1. Move the `right` pointer to expand the window.
2. If the next fruit fits in either basket, increase its count.
3. If you find a third type:
   - Drop the older fruit type (based on the last seen index).
   - Slide the `left` pointer forward.
   - Adjust counters (`live1` or `live2`) by walking from the old `left` to the drop point.
4. Keep updating `ans` with the max window size (`live1 + live2`).

---

## ✅ Solution Code
```cpp
/*
 * 904. Fruit Into Baskets
 * Date: 04-08-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type1 = fruits[0];
        int n = fruits.size();
        if(n == 1 || n == 2) return n;

        int type2 = -1;
        bool basket_empty = true;
        int live1 = 1, live2 = 0;
        int ans = 1;
        int left = 0, right = 0;
        int last1 = 0, last2 = -1;

        while (left < n - 1 && right < n - 1) {
            ans = max(ans, live1 + live2);

            if (fruits[right + 1] == type1 || fruits[right + 1] == type2) {
                right++;
                if (fruits[right] == type1) { last1 = right; live1++; }
                else { last2 = right; live2++; }
            }
            else if (basket_empty) {
                if (type1 == -1) {
                    type1 = fruits[right + 1];
                    last1 = right + 1;
                    live1++;
                } else {
                    type2 = fruits[right + 1];
                    last2 = right + 1;
                    live2++;
                }
                right++;
                basket_empty = (type1 == -1 || type2 == -1);
            }
            else {
                if (last1 < last2) {
                    for (int i = left; i < last1; i++)
                        if (fruits[i] == type2) live2--;
                    left = last1 + 1;
                    type1 = fruits[right + 1];
                    live1 = 1;
                    last1 = right + 1;
                } else {
                    for (int i = left; i < last2; i++)
                        if (fruits[i] == type1) live1--;
                    left = last2 + 1;
                    type2 = fruits[right + 1];
                    live2 = 1;
                    last2 = right + 1;
                }
                right++;
            }
        }

        ans = max(ans, live1 + live2);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1,0,1,4,1,4,1,2,3};
    cout << sol.totalFruit(fruits) << endl;  // Output: 5
    return 0;
}
```