# [2200. Find All K-Distant Indices in an Array](https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/)

## Approach
- One-pass solution using sliding window technique
- Maintains a right boundary `r` to prevent index duplication
- For each `key` found, captures all valid indices within ±`k` range

## Key Insight
The clever use of the `r` pointer to:
1. Skip already processed indices
2. Efficiently merge overlapping ranges
3. Maintain O(n) time complexity

## Time Complexity
O(n) - Single pass through the array with constant-time range operations 