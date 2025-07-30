/*
 * 2419. Longest Subarray With Maximum Bitwise AND
 * Date: 30-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int greatest=INT_MIN;
        for(auto k:nums)greatest=max(k,greatest);
        int ans=1;
        bool flag=false;
        int live=1;
        for(int i=0;i<n;i++){
            if(nums[i]==greatest){
                if(flag)live++;
                else live=1;
                flag=true;
            }
            else flag=false;
            ans=max(live,ans);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
