# [2040. Kth Smallest Product of Two Sorted Arrays](https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/)

## My Learning Journey

### Initial Mistakes
1. **Over-Simplified Index Mapping**  
   - Assumed products followed linear order based on indices  
   - Tried calculating position using:  
     ```factor = n2/k, rem = n2%k```  
   - **Why it failed**:  
     - Products can have duplicates (e.g., 2×3 = 3×2)  
     - Negatives create non-monotonic sequences  

2. **Neglected Negative Number Behavior**  
   - Didn't account for sign-flipping when:  
     - Multiplying two negatives (becomes positive)  
     - Multiplying negative with positive  
   - **Example Failure**:  
     For `nums1 = [-3,-2], nums2 = [1,2]`, k=3  
     Expected: -4 (from -2×2)  
     Got: -6 (incorrect)  

3. **Zero Handling Oversight**  
   - Missed special case when `nums1` or `nums2` contains zero  
   - Products involving zero don't follow regular patterns  

### Key Lessons Learned
1. **Binary Search on Value Space**  
   - Instead of brute-forcing products, search for the k-th value directly  
   - Set search range using min/max possible products  

2. **Efficient Counting with Binary Search**  
   - For each candidate value `mid`:  
     - Count valid pairs in O(n log n) using `upper_bound`/`lower_bound`  
     - Handle positives/negatives/zeros separately  

3. **Critical Observations**  
   - Product distribution is non-linear but monotonic in count  
   - Negative multiplication reverses inequality directions  
   - Zero products require special counting logic  

### How This Changed My Approach
- Shifted from index arithmetic to value-space searching  
- Learned to leverage sorted property for efficient counting  
- Now always consider edge cases (negatives/zeros) first in similar problems  
