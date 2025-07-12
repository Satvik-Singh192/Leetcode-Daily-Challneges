## Problem: [2402. Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/)

- **Status:** ✅ Solved  
- **Difficulty:** Hard  
- **Tags:** Heap, Priority Queue, Simulation, Greedy

---

### ✅ Intuition:
At first I thought I could just use a single priority queue of rooms, sorted by their next free time.  
My idea was: always pick the room that is free the earliest, and if it's busy past the meeting start, delay it.  

I thought this would automatically handle everything, since the heap always gives the earliest free room.  

But I got wrong answers. I didn't handle the rule "use *any* available room at the meeting start time with the *lowest* room number."  

My approach forced unnecessary delays because the PQ only knew about "earliest free room" globally—not who was *already free at start*.  

---

### ✅ Explanation of the Solution:
**Key insight**: The problem specifically says:  

> If any room is free at the meeting’s start time, use the unused room with the lowest number. Only if none is free, delay the meeting.

✅ To implement that strictly, we need **two priority queues**:

1️⃣ **UnusedRooms** (min-heap of room numbers):  
- Contains rooms that are actually free at current meeting's start.  
- Lets us always choose the *lowest* room number among free rooms.  

2️⃣ **UsedRooms** (min-heap of `(free_time, room)`):  
- Contains rooms currently in use, ordered by when they become free.  
- Lets us find which room becomes free the earliest for delay.  

---

**Algorithm steps:**

1. Initialize all rooms as unused.
2. Sort meetings by their start time.
3. For each meeting:
   - Free any rooms whose end time ≤ meeting's start.  
     → Move them back to `unusedRooms`.
   - If `unusedRooms` not empty:  
     → Assign this meeting to the lowest-numbered room without delay.
   - Else:  
     → Delay meeting to the soonest free room, adjust its time.  
4. Track meeting count for each room.
5. Return the room with highest meeting count (smallest number in tie).

✅ This exactly follows the problem rules without shortcuts.

---

### 🧠 Time & Space Complexity:
- **Time:** O(M log N)  
  - M = number of meetings  
  - Each meeting pushes/pops from heaps of size N.
- **Space:** O(N)  
  - Tracking two heaps and counts for N rooms.

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> usedRooms;
        priority_queue<int, vector<int>, greater<>> unusedRooms;
        for (int i = 0; i < n; i++) {
            unusedRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            // Free up any rooms that have finished before this meeting's start
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if (!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [roomAvailabilityTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({roomAvailabilityTime + (end - start), room});
                meetingCount[room]++;
            }
        }

        int maxMeetingCount = 0, maxMeetingCountRoom = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetingCount) {
                maxMeetingCount = meetingCount[i];
                maxMeetingCountRoom = i;
            }
        }
        return maxMeetingCountRoom;
    }
};
```
