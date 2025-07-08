## Problem: [1751. Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

- **Status:** ❌ Tried but couldn’t solve
- **Difficulty:** Hard
- **Tags:** Dynamic Programming, Binary Search, Sorting

---

### ✅ Intuition:
My initial idea was to sort the events in **decreasing order of value** and greedily pick the top k events while avoiding overlaps.  

But I realized this approach fails in some cases. For example:

events = [[1,5,5],[1,2,4],[3,4,4]], k=2

If you greedily take 5 first, you can't find a second non-overlapping event. But choosing [1,2,4] and [3,4,4] gives a better total of 8.

---

### ✅ Explanation of the Solution:
To solve it correctly, we use **Dynamic Programming with Binary Search**:

✅ **Key DP definition:**  
dfs(cur_index, remaining)

= maximum value you can achieve starting at `cur_index` with `remaining` events left to attend.

✅ **Choices at each event:**  
- **Skip** the event:  
  - Keep `remaining` the same.  
  - Move to `dfs(cur_index + 1, remaining)`.  
- **Take** the event:  
  - Use one of the remaining slots (`remaining - 1`).  
  - Add this event's value.  
  - Move to the next non-overlapping event.  
  - Find the next index via **binary search** on start times.

✅ **Recurrence relation:**  
dp[cur_index][remaining] = max(
dfs(cur_index + 1, remaining),
events[cur_index][2] + dfs(next_index, remaining - 1)
)


✅ **Binary search:**  
We sort events by start time. For each event, we use binary search to find the earliest event whose start is after the current event’s end.

✅ **Memoization:**  
We cache results for each `(cur_index, remaining)` to avoid recomputing.

✅ **Base cases:**  
- If `remaining == 0` → return 0.  
- If `cur_index == n` → return 0.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n * k * log n)  
  - Sorting: O(n log n)  
  - DP states: O(n * k)  
  - Binary search per DP call: O(log n)
- **Space:** O(n * k) for DP table + O(log n) recursion stack

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return recursion(0, k, dp, events, n);
    }

    int recursion(int current_index, int k, vector<vector<int>>& dp, vector<vector<int>>& events, int n) {
        if (k == 0 || current_index == n) return 0;
        if (dp[current_index][k] != -1) return dp[current_index][k];
        int next_index = binary_search(events[current_index][1], events, n);
        int include = events[current_index][2] + recursion(next_index, k - 1, dp, events, n);
        int exclude = recursion(current_index + 1, k, dp, events, n);
        return dp[current_index][k] = max(include, exclude);
    }

    int binary_search(int targetEnd, vector<vector<int>>& events, int n) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > targetEnd) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
```
### ✅ Things I Learnt Today:
- Greedy by value alone fails when overlaps limit choices
- How to model take/skip decisions in DP
- Using binary search to find the next non-overlapping event
- Memoizing DP states to avoid recomputation

---

### 📌 Things for Future:
- Practice interval DP patterns (like weighted interval scheduling)
- Review coordinate compression for large ranges
- Study bottom-up DP and segment tree variants
- Understand time complexity with DP + binary search
