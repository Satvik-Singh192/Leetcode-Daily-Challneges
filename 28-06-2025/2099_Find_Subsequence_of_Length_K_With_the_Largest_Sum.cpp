//best solution after learning few optimizations, refer to the ./README.md
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
