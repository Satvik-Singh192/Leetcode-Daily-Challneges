/*
 * 1695. Maximum Erasure Value
 * Date: 22-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int ans = INT_MIN;
        int sum = nums[0];
        int left = 0;
        int right = 0;

        vector<int> precompute(n, 0);
        precompute[0] = nums[0];
        for (int i = 1; i < n; i++) {
            precompute[i] = precompute[i - 1] + nums[i];
        }

        unordered_map<int, int> hash;
        hash[nums[0]] = 0;

        while (right < n - 1) {
            int new_index = right + 1;
            int key = nums[new_index];

            if (hash.count(key) && hash[key] >= left) {
                int duplicate_index = hash[key];
                int removed = 0;
                if (left == 0) {
                    removed = precompute[duplicate_index];
                } else {
                    removed = precompute[duplicate_index] - precompute[left - 1];
                }
                sum -= removed;
                left = duplicate_index + 1;
            }

            sum += key;
            right = new_index;
            hash[key] = right;
            ans = max(ans, sum);
        }

        ans = max(ans, sum);
        return ans;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
