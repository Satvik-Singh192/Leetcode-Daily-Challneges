## Problem: [2561. Rearranging Fruits](https://leetcode.com/problems/rearranging-fruits)
- Status: ✅ Solved  
- Difficulty: Medium  
- Tags: Greedy, Hashmap, Sorting  

---

### ✅ Intuition:
The goal is to make both baskets identical (after sorting) by swapping elements.  
Swapping has a cost — specifically, the **minimum** of the two fruit values involved.  
We want to minimize the total cost.

Initial idea:
1. Count how many times each fruit appears in both baskets.
2. Find out which fruits are unbalanced (extra in one basket).
3. Use the cheapest swaps possible to fix the imbalance.
4. If the imbalance count of **any** fruit is odd → it's impossible to balance.

---

### ✅ Explanation of the Solution:
1. Create a frequency map (`freq`) where each fruit's net count is `basket1[i] - basket2[i]`.
2. For any fruit with imbalance, push `abs(diff) / 2` entries into a vector `to_swap`.
   - This vector represents fruits we must move between baskets.
3. If **any** fruit has an **odd imbalance**, return `-1` (can't fix).
4. Sort `to_swap` — cheapest fruits go first.
5. Let `global_min` be the smallest fruit in both baskets.
6. For the first `n/2` fruits in `to_swap`, add `min(fruit, 2 * global_min)` to total cost.
   - We can either swap directly or use the global minimum as an intermediary swap (bridge).

---

### 🧠 Time & Space Complexity:
- **Time**: O(n log n)  
  Sorting the `to_swap` vector dominates.
- **Space**: O(n)  
  Hash map and vector for fruit differences.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;

        // Count differences
        for (int x : basket1) freq[x]++;
        for (int x : basket2) freq[x]--;

        vector<int> to_swap;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0) return -1;  // Impossible
            for (int i = 0; i < abs(count) / 2; ++i)
                to_swap.push_back(fruit);
        }

        sort(to_swap.begin(), to_swap.end());

        int global_min = min(
            *min_element(basket1.begin(), basket1.end()),
            *min_element(basket2.begin(), basket2.end())
        );

        long long cost = 0;
        int n = to_swap.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(to_swap[i], 2 * global_min);
        }

        return cost;
    }
};
