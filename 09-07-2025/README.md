## Problem: [Reschedule Meetings for Maximum Free Time I](https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/)

- **Status:** ✅ Solved (with some hints)  
- **Difficulty:** Medium  
- **Tags:** Greedy, Sliding Window, Intervals  

---

### ✅ Intuition:
I started by realizing that the free time in the event is made up of the *gaps* between meetings. My first idea was that moving up to **k** meetings lets me "merge" **k+1** gaps into one big free interval.  

I planned to collect all the gaps (including before the first meeting and after the last), and then use a **sliding window of size k+1** over these gaps to find the maximum sum.  

At first, my code had an off-by-one bug in the window bounds. After fixing that, it passed all test cases on LeetCode.  

---

### ✅ Explanation of the Solution:
The goal is to maximize the longest continuous free interval after rescheduling up to k meetings.  

Key idea:
- Moving a meeting can remove *one* adjacent gap.  
- By moving up to **k** meetings, you can merge **k+1 consecutive breaks** into one big interval.  

Steps:
1. **Compute all gaps** between meetings, plus gaps before the first meeting and after the last.  
2. **Store them in a list** of "breaks."  
3. If there are ≤ k gaps in total, you can eliminate them all by moving ≤ k meetings. Just sum all breaks.  
4. Otherwise, **use a sliding window of size k+1** to find the maximum sum of any k+1 consecutive gaps.  

This works because rescheduling k meetings can collapse k+1 adjacent breaks into one.  

Edge considerations:
- Careful with window bounds to avoid out-of-range errors.
- Include gaps at start and end of the event.  

---

### 🧠 Time & Space Complexity:
- **Time:** O(n)  
  - Building the breaks list is O(n)
  - Sliding window over breaks is O(n)
- **Space:** O(n)  
  - For storing breaks

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> breaks;
        int prev = 0;
        int n = startTime.size();
        int current;

        for (int i = 0; i < n; i++) {
            current = startTime[i];
            breaks.emplace_back(current - prev);
            prev = endTime[i];
        }
        if (eventTime - endTime[n - 1] > 0) breaks.emplace_back(eventTime - endTime[n - 1]);

        int ans = 0;
        if (breaks.size() < k + 1) {
            for (auto x : breaks) ans += x;
            return ans;
        }

        int left = 0;
        int right = k;
        int m = breaks.size();

        for (int i = 0; i <= k; i++) ans += breaks[i];
        int sum = ans;

        while (right + 1 < m) {
            ans -= breaks[left++];
            ans += breaks[++right];
            if (ans > sum) sum = ans;
        }
        return sum;
    }
};
```
