# LeetCode Daily Challenge Solution

## [2014. Longest Subsequence Repeated k Times](https://leetcode.com/problems/longest-subsequence-repeated-k-times/)

**Status**: Solved with guidance 🧠  
**Difficulty**: Hard  
**Topics**: String, Backtracking, DFS, Greedy

### Intuition
1. **Character Frequency Filter** - Only characters appearing ≥k times can be part of the solution
2. **Lexicographical Priority** - Need the lexicographically largest valid subsequence
3. **Subsequence Validation** - Must efficiently check if candidate can be repeated k times

### Approach
1. **Preprocessing**:
   - Remove characters with frequency < k
   - Sort valid characters in reverse order (z→a)
   - Calculate max possible length: `floor(n/k)`

2. **DFS with Backtracking**:
   - Build candidates incrementally
   - Prune invalid paths using:
     - Length checks
     - Immediate validation via `repeatK`
   - Prioritize larger characters first

3. **Validation (`repeatK`)**:
   - Greedy O(N) check using pointer chasing
   - Count complete matches of candidate in string

### The Part I Struggled With
After filtering the string, I couldn't figure out how to:
1. Avoid brute-forcing all possible subsequences
2. Efficiently validate candidates
3. Ensure lexicographical order

#### Key Lessons Learned
| Problem Aspect       | Solution Approach                  | Future Applications                 |
|----------------------|------------------------------------|-------------------------------------|
| Candidate Generation | Reverse-order DFS (z→a)            | Any lex-order constrained problem   |
| Validation           | Greedy pointer chasing (`repeatK`) | Subsequence/repetition validation   |
| Pruning              | Early termination on length/value  | Backtracking with constraints       |

### Complexity
- **Time**: O(26^(n/k) * N) - Worst-case with pruning
- **Space**: O(N) - Filtered string + recursion stack

### Solution Code
See [C++ implementation](./Longest_Subsequence_Repeated_k_Times.cpp)

### Comparative Analysis
| Method | Pros                          | Cons                          |
|--------|-------------------------------|-------------------------------|
| DFS    | Natural lex-order, less memory | Deep recursion stack         |
| BFS    | Level-order traversal          | Needs explicit sorting       |

### Pitfalls to Avoid
1. Not filtering characters first
2. Forgetting lexicographical requirement
3. Implementing `repeatK` in O(N²) time
4. Missing edge cases (k=1, all chars identical)

### Reflection
- Mastered reverse-order backtracking
- Learned O(N) subsequence validation trick
- Improved ability to transform problems into DFS templates