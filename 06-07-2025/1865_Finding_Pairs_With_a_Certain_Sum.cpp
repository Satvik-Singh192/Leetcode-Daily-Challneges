/*
 * 1865. Finding Pairs With a Certain Sum
 * Date: 06-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class FindSumPairs {
private:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int, int> hash;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->num1 = nums1;
        this->num2 = nums2;
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            hash[nums2[i]]++;
        }
    }

    void add(int index, int val) {
        hash[this->num2[index]]--;
        hash[this->num2[index] + val]++;
        this->num2[index] += val;
    }

    int count(int tot) {
        int t = 0;
        int n = this->num1.size();
        for (int i = 0; i < n; i++) {
            int first = this->num1[i];
            if (hash.count(tot - first)) {
                t += hash[tot - first];
            }
        }
        return t;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main() {
    // Test cases
    return 0;
}
