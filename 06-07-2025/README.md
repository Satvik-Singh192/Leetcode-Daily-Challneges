## Problem: [1865. Finding Pairs With a Certain Sum](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** Hash Map, Design, Two Pointers, Frequency Map

---

### ✅ Intuition:
The key observation is that `nums1` is immutable, while `nums2` can be updated. So, to support fast lookups for pair sums, we can preprocess and maintain a frequency map for `nums2`. Every time `nums2` is modified, we update the frequency map accordingly. This lets us count the number of valid pairs in linear time with respect to `nums1`.

---

### ✅ Explanation of the Solution:
1. Store the `nums1` and `nums2` arrays.
2. Build a frequency hash map for `nums2` to quickly look up how many times a complement value appears.
3. For the `add(index, val)` operation:
   - Decrement the count of the old value in the hash map.
   - Increment the count of the new value after updating `nums2[index]`.
4. For the `count(tot)` operation:
   - Iterate through each element in `nums1`.
   - For each element `x`, compute `tot - x` and look it up in the frequency map of `nums2`.
   - Sum up the frequencies for all valid complements.

This approach ensures efficient updates and queries.

---

### 🧠 Time & Space Complexity:
- **Time:**  
  - Constructor: O(n), where n = size of `nums2`  
  - `add(index, val)`: O(1)  
  - `count(tot)`: O(m), where m = size of `nums1`  

- **Space:** O(n), for the frequency map of `nums2`

---

### 💡 Solution (C++):
```cpp
/*
 * 1865. Finding Pairs With a Certain Sum
 * Date: 06-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int, int> hash;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->num1 = nums1;
        this->num2 = nums2;
        for (int val : nums2) {
            hash[val]++;
        }
    }

    void add(int index, int val) {
        hash[num2[index]]--;
        if (hash[num2[index]] == 0) {
            hash.erase(num2[index]);
        }
        num2[index] += val;
        hash[num2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int val : num1) {
            int complement = tot - val;
            if (hash.count(complement)) {
                res += hash[complement];
            }
        }
        return res;
    }
};

```
