## Problem: [1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** Greedy, Heap, Sorting  

---

### ✅ Intuition:
Initially, I thought I could sort all events by duration (shortest first), and for each event, pick its first available day.  
I implemented this by sorting events by their duration and marking used days in a visited array.  
This greedy idea worked on many test cases but failed on inputs where multiple events overlap heavily.  

For example, with events like `[[1,3],[1,3],[1,3],[3,4]]`, my approach picked the earliest days for the 3 `[1,3]` events and couldn't find a valid day for `[3,4]`.  

I realized that picking the shortest-duration event first doesn't always leave enough space for tight intervals that come later.  

---

### ✅ Explanation of the Solution:
The correct greedy strategy is to always attend the event that **ends the earliest** among available options.  

Here’s why:
- By choosing the event with the earliest end day, you free up as many future days as possible for other events.  
- This is a classic greedy approach for interval scheduling with flexibility in choosing any day within an event’s window.

**Steps:**
1. Sort all events by their start day.  
2. Use a min-heap (priority queue) to keep track of all "available" events’ end days.  
3. Iterate over each day:
   - Add all events that start today to the heap.  
   - Remove any events whose end day is before today (they expired).  
   - If the heap isn't empty, attend the event with the earliest end day (pop from heap), and move to the next day.

This ensures you never waste early days on events that could have been scheduled later, preserving room for tighter intervals.

---

### 🧠 Time & Space Complexity:
- **Time:** O(N log N)  
  - Sorting events: O(N log N)  
  - Each event is added and removed from the heap once: O(log N) per operation  
- **Space:** O(N) for the heap  

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());  // sort by start day

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int res = 0;
        int day = 0;
        int i = 0, n = events.size();

        while (!minHeap.empty() || i < n) {
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // Add all events starting today
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Remove expired events
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();  // Attend the event ending earliest
                res++;
                day++;
            }
        }

        return res;
    }
};
```
### ✅ Things I Learnt Today:
- **Key insight:** For scheduling problems with flexible intervals, *always pick the event with the earliest end date* to maximize future choices.
- Sorting by duration isn't always safe — it can block later tight intervals that don't have as much flexibility.
- Using a **min-heap** is a standard technique to efficiently track and access the next best event to attend.
- It's crucial to **clean up expired events** from the heap (where `end < current_day`) to avoid attending invalid or already-expired options.
