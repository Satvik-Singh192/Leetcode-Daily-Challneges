class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        int global_min = INT_MAX;
        for (int x : basket1) {
            freq[x]++;
            global_min = min(global_min, x);
        }
        for (int x : basket2) {
            freq[x]--;
            global_min = min(global_min, x);
        }

        vector<int> to_swap;
        for (auto& [fruit, count] : freq) {
            if (count % 2 != 0)
                return -1;
            for (int i = 0; i < abs(count) / 2; ++i)
                to_swap.push_back(fruit);
        }
        int n = to_swap.size();
        vector<int> smallest_half(n / 2);
        partial_sort_copy(to_swap.begin(), to_swap.end(), smallest_half.begin(),
                          smallest_half.end());

        long long cost = 0;
        for (int i = 0; i < n / 2; ++i) {
            cost += min(smallest_half[i], 2 * global_min);
        }
        return cost;
    }
};