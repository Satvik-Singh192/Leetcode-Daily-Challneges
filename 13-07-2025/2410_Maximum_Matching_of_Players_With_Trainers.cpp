/*
 * 2410. Maximum Matching of Players With Trainers
 * Date: 13-07-2025
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0;
        int player_index=0;
        int player_size=players.size();
        int trainer_size=trainers.size();
        for(int trainer_index=0;trainer_index<trainer_size;trainer_index++){
            if(player_index>=player_size)break;
            if(players[player_index]<=trainers[trainer_index]){
                ans++;
                player_index++;
                continue;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // Test cases
    return 0;
}
