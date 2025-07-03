/*
 * 3304. Find the K-th Character in String Game I
 * Date: 2025-07-03
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
