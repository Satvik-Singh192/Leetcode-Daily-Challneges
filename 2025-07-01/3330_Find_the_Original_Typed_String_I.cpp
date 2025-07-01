class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int n=word.size();
        int key=word[0];
        int j;
        for(int i=0;i<n-1;i++){
            key=word[i];
            j=i+1;
            while(j<n&&word[j]==key)j++;
            if(j==i+1)continue;
            ans+=j-i-1;
            i=j-1;
        }
        return ans;
    }
};
