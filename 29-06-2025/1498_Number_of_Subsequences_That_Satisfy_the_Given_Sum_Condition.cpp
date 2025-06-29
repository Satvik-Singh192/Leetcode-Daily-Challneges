#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int i, int high, int target) {
        int low = i;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[i] + nums[mid] <= target) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> pow2(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int ans = 0;
        int last = n - 1;  
        
        for (int i = 0; i < n; i++) {
            int j = helper(nums, i, last, target);
            if (j == -1) break;
            
            ans = (ans + pow2[j - i]) % MOD;
            last = j;
        }
        
        return ans;
    }
};
