## Problem: [594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Hash Table, Sorting 

### ✅ Intuition:
We are given a string `word` that may contain **at most one long-pressed character group**, meaning a character might have been repeated unintentionally.

Your solution identifies **consecutive groups of identical characters**. For each such group of size `k > 1`, there are `(k - 1)` possible ways Alice may have over-typed the character. Since only **one group** could have been long-pressed, we can choose **any one of those extra characters to remove**.

We initialize the answer as `1` (the case where no correction is needed), and for each group of repeated characters, we add `(group size - 1)` to the answer. This gives the total number of possible original strings Alice could have intended.
---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(1)

---

### 💡 Solution (C++):

```cpp
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
```


