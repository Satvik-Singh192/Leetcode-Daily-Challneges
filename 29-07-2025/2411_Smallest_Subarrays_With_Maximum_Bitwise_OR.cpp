/*
 * 2411. Smallest Subarrays With Maximum Bitwise OR
 * Date: 29-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
vector<int> smallestSubarrays(vector<int>& nums) {

    const int n=nums.size();
    vector<int> ans(n);
    vector<int> last(30, -1); 

    for (int i=n-1; i>= 0; i--) {
        const unsigned x=nums[i];
        int j=i;
        bitset<30> X(x);
        for (int b=0; b<30; b++) {
            if (X[b]) 
                last[b]=i;
            j=max(j, last[b]);
        }
        ans[i]=j-i+1;
    }

    return ans;
}
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
