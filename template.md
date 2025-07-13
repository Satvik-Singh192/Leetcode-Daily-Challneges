## Problem: [2410. Maximum Matching of Players With Trainers](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/)

- **Status:** ✅ Solved  
- **Difficulty:** Medium  
- **Tags:** Greedy, Sorting, Two Pointers  

---

### ✅ Intuition:
I realized the problem is about pairing players and trainers under the constraint that a player’s ability ≤ trainer’s capacity. My first thought was that if I always assign the weakest player who can be trained by the weakest available trainer, I’d maximize the number of pairs.

That led me to sort both lists and try to match them in order.

---

### ✅ Explanation of the Solution:
**Step by step:**
1. **Sort** both the `players` and `trainers` arrays in ascending order.  
   - This ensures that weaker players/trainers are considered first.  
2. Use **two pointers**:  
   - `player_index` for the players list.  
   - Loop through each trainer.  
3. For each trainer, if the current player’s ability ≤ trainer’s capacity, we count this as a match and move to the next player.  
4. Stop early if all players are matched.  
5. Return the total number of matches.  

**Why it works:**  
By always using the smallest valid trainer for the current player, we don’t “waste” stronger trainers on weaker players. This greedy approach ensures the maximum number of matchings.

---

### 🧠 Time & Space Complexity:
- **Time:** O(n log n + m log m)  
  - Sorting both arrays dominates.  
  - Linear pass to match.  
- **Space:** O(1) extra (in-place sorting, constant variables)

---

### 💡 Solution (C++):
```cpp
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        int player_index = 0;
        int player_size = players.size();
        int trainer_size = trainers.size();
        for (int trainer_index = 0; trainer_index < trainer_size; trainer_index++) {
            if (player_index >= player_size) break;
            if (players[player_index] <= trainers[trainer_index]) {
                ans++;
                player_index++;
                continue;
            }
        }
        return ans;
    }
};
