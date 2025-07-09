/*
 * 3439. Reschedule Meetings for Maximum Free Time I
 * Date: 09-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> breaks;
        int prev=0;
        int n=startTime.size();
        int current;
        for(int i=0;i<n;i++){
            current=startTime[i];
            
                breaks.emplace_back(current-prev);
            
            prev=endTime[i];
        }
        if(eventTime-endTime[n-1]>0)breaks.emplace_back(eventTime-endTime[n-1]);
        int ans=0;
        if(breaks.size()<k+1){
            for(auto x:breaks)ans+=x;
            return ans;
        }
        int left=0;
        int right=k;
        int m=breaks.size();
        for(int i=0;i<=k;i++)ans+=breaks[i];
        int sum=ans;
        while(right+1<m){
            ans-=breaks[left++];
            ans+=breaks[++right];
            if(ans>sum)sum=ans;
        }
        return sum;
    }
};
int main() {
    Solution sol;
    // Test cases
    return 0;
}
