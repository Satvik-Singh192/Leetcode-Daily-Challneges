/*
 * 1717. Maximum Score From Removing Substrings
 * Date: 23-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        // ab is always tehe primary target
        int ans=0;
        int a_count=0;
        int b_count=0;
        for(auto c:s){
            if(c!='a'&&c!='b'){
                ans+=min(a_count,b_count)*y;
                a_count=0;b_count=0;
            }
            else{
                if(c=='b'){
                    if(a_count>0){
                        a_count--;
                        ans+=x;
                    }
                    else b_count++;
                }
                else{
                    a_count++;
                }
            }
        }
        ans+=min(a_count,b_count)*y;
        return ans;

    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
