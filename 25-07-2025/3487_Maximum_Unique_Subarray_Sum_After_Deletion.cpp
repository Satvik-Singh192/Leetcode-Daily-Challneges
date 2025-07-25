/*
 * 3487. Maximum Unique Subarray Sum After Deletion
 * Date: 25-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        int positive_present=-1;;
        int negative_only=INT_MIN;

        unordered_map<int,int>hash;
        for(auto k :nums){
            if(hash[k]>0)continue;
            hash[k]++;
            if(k>=0){
                if(positive_present==-1)positive_present=0;
                positive_present+=k;
            }
            else{
                if(k>negative_only)negative_only=k;
            }
        }
        if(positive_present==-1)return negative_only;
        return positive_present;
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
