/*
 * 1957. Delete Characters to Make Fancy String
 * Date: 21-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3)return s;

        string ans="";
        ans+=s[0];ans+=s[1];

        int n=s.size();
        for(int i=2;i<n;i++){
            if(s[i]==s[i-1]&&s[i]==s[i-2]){
                continue;
            }
            else{
                ans+=s[i];
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
