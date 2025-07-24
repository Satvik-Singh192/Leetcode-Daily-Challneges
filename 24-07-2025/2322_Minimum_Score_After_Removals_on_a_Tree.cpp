/*
 * 2322. Minimum Score After Removals on a Tree
 * Date: 24-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = INT_MAX;

    int dfs2(int node, int parent, vector<vector<int>>& adj, vector<int>& nums,
             int firstCutXor, int firstCutChild, int totalXor) {
        
        int currXor = nums[node];

        for (int neighbor : adj[node]) {
            if (neighbor == parent || neighbor == firstCutChild) continue;

            int subXor = dfs2(neighbor, node, adj, nums, firstCutXor, firstCutChild, totalXor);
            currXor ^= subXor;

            int part2 = subXor;
            int part3 = totalXor ^ firstCutXor ^ part2;

            int score = max({firstCutXor, part2, part3}) - min({firstCutXor, part2, part3});
            ans = min(ans, score);
        }

        return currXor;
    }

    int dfs1(int node, int parent, vector<int>& nums, vector<vector<int>>& adj, int totalXor) {
        int currXor = nums[node];

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            int childXor = dfs1(neighbor, node, nums, adj, totalXor);
            currXor ^= childXor;

         
            dfs2(node, -1, adj, nums, childXor, neighbor, totalXor);  
        }

        return currXor;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int totalXor = 0;
        for (int val : nums) totalXor ^= val;

        dfs1(0, -1, nums, adj, totalXor);

        return ans;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
