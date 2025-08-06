/*
 * 3479. Fruits Into Baskets III
 * Date: 06-08-2025
 */
#include <bits/stdc++.h>
using namespace std;

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


int main() {
    Solution sol;
    // Test cases
    return 0;
}
