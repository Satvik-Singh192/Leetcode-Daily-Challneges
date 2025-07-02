## Problem: [594. Longest Harmonious Subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/)

- **Status:** ✅ Solved  
- **Difficulty:** Easy  
- **Tags:** Hash Table, Sorting 

### ✅ Intuition:
Use a frequency map to count occurrences of each number.  
For every key, check if `key + 1` exists, and if so, update the answer with the sum of their frequencies.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
- **Space:** O(n)

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


