/*
 * 1353. Maximum Number of Events That Can Be Attended
 * Date: 07-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); 
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int res = 0;
        int day = 0;
        int i = 0, n = events.size();

        while (!minHeap.empty() || i < n) {
            if (minHeap.empty()) {
                day = events[i][0];
            }

            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();  
                res++;
                day++;
            }
        }

        return res;
    }
};


int main() {
    Solution sol;
    // Test cases
    return 0;
}
