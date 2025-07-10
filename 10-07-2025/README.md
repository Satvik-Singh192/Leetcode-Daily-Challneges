## Problem: [3440. Reschedule Meetings for Maximum Free Time II](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii)

- **Status:** ☠️ Copied solution (but deeply understood)
- **Difficulty:** Medium
- **Tags:** Greedy, Prefix Max, Interval Scheduling

---

### ✅ Intuition:
My idea was to find all the "breaks" between meetings and try to merge two consecutive breaks by moving a meeting in between them somewhere else.  

My plan was:
- Store all breaks in a vector.
- For each *middle* break, try to connect it with its neighbors by moving a meeting elsewhere.  
- Use a hashmap to see if there exists any other break large enough to fit the meeting I want to move.

But I got stuck because:
- I couldn't figure out how to quickly (in O(n)) tell whether there was a non-adjacent break large enough for my meeting.  
- My logic ended up checking too many breaks repeatedly, making it potentially O(n²) and buggy.  

---

### ✅ Explanation of the Solution:
**Key idea (editorial approach):**  
For each meeting i, there are two cases:

1️⃣ *Best Case (Case 1)*:  
- If I can move meeting i into some **non-adjacent** free interval big enough to hold it.  
- Then its adjacent breaks on both sides plus the meeting itself merge into one giant free time.  
- New free time: `right_i - left_i`.

2️⃣ *Always possible (Case 2)*:  
- If I can't move it away, I can at least move it **between** its adjacent breaks to minimize blocking them.  
- New free time: `right_i - left_i - meeting_length`.

✅ Trick:
- To check for **Case 1**, I need the biggest non-adjacent break on the **left** and **right** of i.  
- Instead of recalculating for every i (which would be O(n²)), I *carry* the running max while scanning.  
- For left → right pass:
  - `t1` = max of all breaks strictly before i - 1 (i.e. non-adjacent breaks on the left).
- For right → left pass:
  - `t2` = max of all breaks strictly after i + 1 (non-adjacent on the right).

✅ Why this works:
- When checking meeting i, `t1` and `t2` contain only **non-adjacent** breaks.  
- Updating them after checking i ensures they exclude adjacent breaks for the current i.  
- This gives O(n) time with O(1) space (no extra arrays needed).  

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
  - Single pass left to right and right to left.
  - Each meeting processed in O(1) time.  
- **Space:** O(1)  
  - Only a few scalar variables (no arrays or hash maps).

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            int left1 = i == 0 ? 0 : endTime[i - 1];
            int right1 = i == n - 1 ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1) {
                res = max(res, right1 - left1);
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));
            res = max(res, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
            int right2 = i == 0 ? eventTime : startTime[n - i];
            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                res = max(res, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
        }
        return res;
    }
};
```
### ✅ Things I Learnt Today:
- Maintaining a **prefix/suffix max** can avoid extra arrays.  
- You can exclude adjacent intervals by **delaying** your updates until *after* checking.  
- “Non-adjacent break” doesn't mean checking all breaks every time—it can be done with **one variable** while scanning.  
- Editorial tricks often transform an **O(n²)** naive idea into an **O(n)** solution by smartly *carrying forward* the answer.  

---

### 📌 Things for Future:
- Practice more **greedy interval** problems.  
- Learn to spot where **prefix/suffix aggregates** can replace nested loops.  
- Get comfortable doing **“one-pass” scans** with invariants.  
- Review similar problems:
  - **Maximum Consecutive Ones with Flips**
  - **Partition Labels**
  - **Merge Intervals** variations
