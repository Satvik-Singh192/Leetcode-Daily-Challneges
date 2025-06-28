# LeetCode Daily Challenge Solution

## [2099. Find Subsequence of Length K With the Largest Sum](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/)

**Status**: Solved with optimizations ✅  
**Difficulty**: Easy  
**Topics**: Array, Heap (Priority Queue), Sorting

---

### Initial Inefficient Approach
#### Intuition
- Maintain a running subsequence in a vector
- Track smallest element using a min-heap
- Replace elements when larger values are found

#### Problems
1. **Unnecessary Storage**: Used `INT_MIN` placeholders requiring post-processing
2. **Index Complexity**: Manual index tracking led to messy logic
3. **Space Waste**: Temporary vector grew to O(n) size

#### Original Code
```cpp
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans(k,0);
        int sum=0;
        int n=nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0;i<k;i++){
            ans[i]=nums[i];
            sum+=ans[i];
            pq.push(make_pair(ans[i],i));
        }
        int j=k;
        for(int i=k;i<n;i++){
            int min=pq.top().first;
            if(nums[i]>min){
                ans.emplace_back(nums[i]);j++;
                sum+=nums[i];
                sum-=min;
                ans[pq.top().second]=INT_MIN;
                pq.pop();
                pq.push(make_pair(nums[i],j-1));
            }
        }
        vector<int> sol;
        for(auto x:ans){
            if(x==INT_MIN)continue;
            sol.emplace_back(x);
        }
        return sol;
    }
};
```


## Optimized Solution

### Key Improvements
- **Heap-Only Tracking**: Eliminated placeholder values by storing indices
- **Clean Reconstruction**: Sorted by indices after heap processing  
- **Space Optimization**: Reduced space from O(n) to O(k)

### Optimized Approach
1. Use min-heap to track top `k` elements with their indices
2. Replace smallest element when finding larger values
3. Sort selected elements by original indices before returning

### Optimized Code
```cpp
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < nums.size(); ++i) {
            if (minHeap.size() < k) {
                minHeap.push({nums[i], i});
            } else if (nums[i] > minHeap.top().first) {
                minHeap.pop();
                minHeap.push({nums[i], i});
            }
        }

        vector<pair<int, int>> temp;
        while (!minHeap.empty()) {
            temp.push_back({minHeap.top().second, minHeap.top().first});
            minHeap.pop();
        }
        sort(temp.begin(), temp.end());

        vector<int> result;
        for (auto& p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};

```


Key formatting notes:
1. Used proper markdown headers (`##` and `###`)
2. Added code fence (```) for the C++ code block
3. Maintained consistent bullet point formatting
4. Separated sections clearly with blank lines
5. Kept complexity analysis in bold for readability

The formatting will render perfectly on GitHub/GitLab or any markdown viewer. Would you like me to adjust any specific part of the formatting?