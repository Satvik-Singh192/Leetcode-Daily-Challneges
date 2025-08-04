/*
 * 904. Fruit Into Baskets
 * Date: 04-08-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type1=fruits[0];int n=fruits.size();
        if(n==1||n==2)return n;
        int type2=-1;bool basket_empty=true;
        int live1=1;int ans=1;int live2=0;
        int left=0;int right=0;
        int last1=0;int last2=-1;
        while(left<n-1 && right <n-1){
            ans=max(ans,live1+live2);
            if(fruits[right+1]==type1 || fruits[right+1]==type2){
               right++;
                if(fruits[right]==type1){last1=right;live1++;}
                if(fruits[right]==type2){last2=right;live2++;}
            }
            else if(basket_empty){
                if(type1==-1){
                    type1=fruits[right+1];
                    last1=right+1;
                    live1++;
                }
                else{
                    type2=fruits[right+1];
                    last2=right+1;live2++;
                }
                right++;
                basket_empty=(type1==-1 || type2 ==-1)?true:false;
            }
            else{
                if(last1<last2){
                    for(int i=left;i<last1;i++){
                        if(fruits[i]==type2)live2--;
                    }
                    left=last1+1;
                    type1=fruits[right+1];
                    live1=1;
                    last1=right+1;
                }
                else{
                    for(int i=left;i<last2;i++){
                        if(fruits[i]==type1)live1--;
                    }
                    left=last2+1;
                    type2=fruits[right+1];
                    live2=1;last2=right+1;
                }
                right++;
            }
        }
        ans=max(ans,live1+live2);
        return ans;



    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
