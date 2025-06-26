class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count=0;
        for(auto a:s){
            if(a=='0')count++;
        }
        int position=0;
        int n=s.size();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                position++;
            }
            else{
                if(sum+pow(2,position)>k){
                    break;
                }
                else {
                    count++;
                    sum+=pow(2,position);
                    position++;
                }
            }
        }
        return count;
    }
};