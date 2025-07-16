/*
 * 3201. Find the Maximum Length of Valid Subsequence I
 * Date: 16-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums,int x, bool need_odd_asap){
        int odd=0;
        for(int i=0;i<x;i++){
            if(nums[i]%2==0){
                if(need_odd_asap==true)continue;
                else{
                    need_odd_asap=true;
                    odd++;
                }
            }
            else{
                if(need_odd_asap==true){
                    odd++;
                    need_odd_asap=false;
                }
                else continue;
            }
        }
        return odd;
    }
    int maximumLength(vector<int>& nums) {
        int even=0;
        int x=nums.size();
         
         int odd1=helper(nums,x,false);
         int odd2=helper(nums,x,true);
         int odd=odd1>odd2?odd1:odd2;

        //building subsquence with eeven sum
        int only_odds=0;
        int only_evens=0;
        for(auto k:nums){
            if(k%2==0)only_evens++;
            else only_odds++;
        }
        even=only_odds>only_evens?only_odds:only_evens;

        return (even>odd?even:odd);

    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
