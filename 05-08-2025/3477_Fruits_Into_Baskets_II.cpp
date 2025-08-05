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
                    baskets[j] = -1;  
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
    // Test cases
    return 0;
}
