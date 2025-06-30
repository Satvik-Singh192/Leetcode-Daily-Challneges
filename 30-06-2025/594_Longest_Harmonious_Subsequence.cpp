class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        int ans = 0;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            auto next_it = hash.find(it->first + 1);
            if (next_it != hash.end()) {
                ans = max(ans, it->second + next_it->second);
            }
        }

        return ans;
    }
};
