/*
 * 2044. Count Number of Maximum Bitwise-OR Subsets
 * Date: 28-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count=0;
    int maxor=0;
    void dfs(vector<int>& nums, int curr, int index) {
        if (index == nums.size()) {
            if (curr == maxor) count++;
            return;
        }
        dfs(nums, curr | nums[index], index + 1);
        dfs(nums, curr, index + 1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto k:nums)maxor|=k;
        dfs(nums,0,0);
        return count;
    }
};
int main() {
    Solution sol;
    // Test cases
    return 0;
}
