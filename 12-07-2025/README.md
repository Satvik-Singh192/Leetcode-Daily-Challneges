## Problem: [1900. The Earliest and Latest Rounds Where Players Compete](https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/)

- **Status:** ✅ Solved  
- **Difficulty:** Hard  
- **Tags:** DP, Memoization, Simulation, Game Theory  

---

### ✅ Intuition:

The problem is to determine the earliest and latest round in which two strong players can meet in a knockout-style tournament. Since all other players are weak and their match outcomes can be freely chosen, we can control how fast or slow the strong players meet.

- For the **earliest** round, we want to push them together.
- For the **latest** round, we want to keep them apart.

The key insight is that the matchups are always between players at positions `i` and `n - i + 1`, so two players with positions `f` and `s` will meet in round `r` **if** `f + s == n + 1`. Otherwise, they both survive, and we control who else survives to manipulate their positions in the next round.

---

### ✅ Explanation of the Solution:

We define a recursive function `dfs(n, f, s)` where:
- `n` = number of players remaining in the current round
- `f` and `s` = positions (1-indexed) of the two strong players

#### Key Transformations:
1. Always ensure `f < s` by swapping.
2. If `f + s > n + 1`, flip the lineup (using symmetry):  
   `(f, s) → (n + 1 - s, n + 1 - f)`

#### Base Case:
If `f + s == n + 1`, the players face each other this round ⇒ return `(1, 1)`.

#### Recursive Step:
We simulate all ways of allowing players between and before `f` and `s` to advance:
- Let `i` be how many weaker players survive before `f`
- Let `j` be how many survive between `f` and `s`

In the next round:
- new `f` = `i + 1`
- new `s` = `i + j + 2`
- new total players = `(n + 1) / 2`

We take the **minimum** and **maximum** round over all valid (i, j) combinations.

---

### 🧠 Time & Space Complexity:

- **Time:** `O(n^4 log n)`  
  - Each state `dfs(n, f, s)` is `O(n^2)` (due to i,j loops), and `n` halves each round.
- **Space:** `O(n^2 log n)`  
  - For memoization table storing computed `(n, f, s)` results.

---

### 💡 Solution (C++):

```cpp
class Solution {
public:
    map<tuple<int, int, int>, pair<int, int>> memo;

    pair<int, int> dfs(int n, int f, int s) {
        if (f > s) swap(f, s);
        if (f + s == n + 1) return {1, 1};
        if (f + s > n + 1) return dfs(n, n + 1 - s, n + 1 - f);

        auto key = make_tuple(n, f, s);
        if (memo.count(key)) return memo[key];

        int nextN = (n + 1) / 2;
        int minRound = INT_MAX;
        int maxRound = 0;

        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < s - f - 1; ++j) {
                int newF = i + 1;
                int newS = i + j + 2;
                auto [er, lr] = dfs(nextN, newF, newS);
                minRound = min(minRound, er + 1);
                maxRound = max(maxRound, lr + 1);
            }
        }

        return memo[key] = {minRound, maxRound};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};
```
### ✅ Why This Works:

- **Uses symmetry to reduce redundant states.**  
  By recognizing that the lineup can be flipped or positions swapped without changing the problem, the solution cuts down the number of unique states it needs to handle.  

- **Models flexible match outcomes by enumerating surviving weaker players.**  
  Because weak players' results can be freely chosen, the DP explicitly tries all ways of arranging them to push the strong players closer or farther apart.  

- **Efficient recursive solution with memoization avoids recomputation.**  
  Top-down memoization ensures each state `(n, f, s)` is solved only once, making the approach practical despite many choices.  

- **Fully handles edge cases like middle players and odd player counts.**  
  The transitions correctly account for automatic advancement of middle players in odd-sized rounds, ensuring the simulation remains faithful to the tournament rules.

---

### 🔑 Key Takeaways:

- **In tournament-style problems, model states as (number of players, positions of interest).**  
  Track only the essential information needed to determine outcomes in the recursive state.  

- **Use symmetry and ordering to reduce the number of distinct DP states.**  
  By normalizing positions (e.g., always making `f < s`), you eliminate equivalent states and simplify your code.  

- **When you can control outcomes, explore all valid transitions using enumeration.**  
  Make full use of any flexibility in the problem (like choosing winners) to design the state transitions that achieve your goal (earliest/latest).  

- **Combine recursive thinking with memoization to manage exponential choices efficiently.**  
  Even when many branching choices exist, caching results turns a naive exponential algorithm into something tractable.
