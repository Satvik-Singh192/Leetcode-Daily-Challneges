# 3477. Fruits Into Baskets II - 05-08-2025

## Problem Description
You’re given a list of fruits with their sizes and a list of baskets with capacities. Each basket can hold **at most one** fruit, and only if its capacity is **greater than or equal to** the size of the fruit.  
Your job is to figure out **how many fruits end up sad and unplaced** after trying to put each fruit into any available basket (one basket per fruit).

---

## Approach
Think of it like you’re standing in front of a line of fruits 🍉 and a bunch of baskets 🧺. Each basket can be used only *once*.   
For every fruit in the list:
1. Try every basket one by one.
2. If a basket hasn’t been used yet **(not marked as `-1`)** *and* its capacity is big enough to hold the fruit → put the fruit in, mark that basket as `-1`, and stop searching for that fruit.
3. If no basket can fit that fruit → count it as **unplaced**.

This is a simple brute-force approach using a **nested loop**, which makes the time complexity **O(n²)**. The upside? No extra space — everything is done directly in the input array 💪 (constant memory).

---

## Solution Code
```cpp
/*
 * 3477. Fruits Into Baskets II
 * Date: 05-08-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < m; ++j) {
                if (baskets[j] != -1 && baskets[j] >= fruits[i]) {
                    baskets[j] = -1;  // mark this basket as used
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }

        return unplaced;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {2,3,5};
    vector<int> baskets = {5,3,2};
    cout << sol.numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}
```