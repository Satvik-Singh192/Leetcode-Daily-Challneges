/*
 * 118. Pascal's Triangle
 * Date: 01-08-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> temp(i + 1, 1); 
            for (int j = 1; j < i; j++) {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
