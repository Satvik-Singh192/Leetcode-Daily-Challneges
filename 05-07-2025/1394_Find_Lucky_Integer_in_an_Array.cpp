/*
 * 1394. Find Lucky Integer in an Array
 * Date: 2025-07-05
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(auto  k:arr)hash[k]++;
        int ans=-1;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->first == it->second&& it->first>ans)ans=it->first;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
