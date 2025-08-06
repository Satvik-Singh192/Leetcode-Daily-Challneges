## Problem: [Fruits Into Baskets III](https://leetcode.com/problems/fruits-into-baskets-iii)
- Status: ✅ Solved  
- Difficulty: Medium  
- Tags: block decomposition, greedy, sqrt decomposition  

---

### ✅ Intuition:
Naively scanning the `baskets[]` array for each fruit to find a suitable basket led to **TLE**.  
So I thought of dividing the baskets into blocks and storing the maximum value in each block.  
That way, I could skip over entire blocks that can't satisfy the current fruit's requirement, speeding things up.

---

### ✅ Explanation of the Solution:
1. Split the `baskets[]` array into √n blocks.
2. Precompute the maximum basket size in each block and store in `maxv[]`.
3. For each fruit:
   - Iterate through the blocks.
   - If a block's max is less than the fruit's requirement, skip it.
   - Otherwise, scan only that block for the first suitable basket.
   - Mark that basket as used (`baskets[i] = 0`) and recompute the block's max.
4. If no basket is found, count the fruit as unplaced.

---

### 🧠 Time & Space Complexity:
- Time: O(n × √n)  
- Space: O(√n)

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int block_size = sqrt(n);
        int block_nums = (n + block_size - 1) / block_size;
        vector<int> maxv(block_nums, 0);
        for (int i = 0; i < n; ++i) {
            int b = i / block_size;
            maxv[b] = max(maxv[b], baskets[i]);
        }
        int unplaced = 0;
        for (int i = 0; i < n; ++i) {
            int required = fruits[i];
            bool placed = false;
            for (int j = 0; j < block_nums && !placed; ++j) {
                if (maxv[j] < required) continue;
                int start = j * block_size;
                int end = min(n, (j + 1) * block_size);
                for (int k = start; k < end; ++k) {
                    if (baskets[k] >= required) {
                        baskets[k] = 0;
                        placed = true;
                        maxv[j] = 0;
                        for (int x = start; x < end; ++x)
                            maxv[j] = max(maxv[j], baskets[x]);
                        break;
                    }
                }
            }
            if (!placed) unplaced++;
        }
        return unplaced;
    }
};
```
🧾 What I Learned:
How to implement block/sqrt decomposition for range queries.

Precomputing values (like max per block) saves time if queries are frequent.

You can reduce time complexity drastically without learning full segment trees yet.

Still, this has limitations and won't scale for all query types (esp. frequent updates).

