/*
 * 1751. Maximum Number of Events That Can Be Attended II
 * Date: 08-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return recursion(0, k, dp, events, n);
    }

    int recursion(int current_index, int k, vector<vector<int>>& dp, vector<vector<int>>& events, int n) {
        if (k == 0 || current_index == n) return 0;
        if (dp[current_index][k] != -1) return dp[current_index][k];
        int next_index = binary_search(events[current_index][1], events, n);
        int include = events[current_index][2] + recursion(next_index, k - 1, dp, events, n);
        int exclude = recursion(current_index + 1, k, dp, events, n);
        return dp[current_index][k] = max(include, exclude);
    }

    int binary_search(int targetEnd, vector<vector<int>>& events, int n) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > targetEnd) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
