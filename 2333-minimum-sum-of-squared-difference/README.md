# 2333. Minimum Sum of Squared Difference

**Difficulty:** Medium  
**Topics:** Array, Math, Greedy, Sorting, Heap (Priority Queue)  
**LeetCode Link:** [2333. Minimum Sum of Squared Difference](https://leetcode.com/problems/minimum-sum-of-squared-difference/)

---

## Problem Description

You are given two positive 0-indexed integer arrays `nums1` and `nums2`, both of length `n`.

The **sum of squared difference** of arrays `nums1` and `nums2` is defined as the sum of `(nums1[i] - nums2[i])^2` for each $0 \le i < n$.

You are also given two positive integers `k1` and `k2`. You can modify any element of `nums1` by $+1$ or $-1$ at most `k1` times, and any element of `nums2` by $+1$ or $-1$ at most `k2` times.

Return the **minimum sum of squared difference** after modifying array `nums1` at most `k1` times and `nums2` at most `k2` times.

*Note:* You are allowed to modify the array elements to become negative integers.

---

## Examples

### Example 1:

**Input:** `nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0`  
**Output:** `579`  
**Explanation:**  
Sum of squared difference: $(1-2)^2 + (2-10)^2 + (3-20)^2 + (4-19)^2 = 1 + 64 + 289 + 225 = 579$.

---

### Example 2:

**Input:** `nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1`  
**Output:** `43`  
**Explanation:**  
- Increase `nums1[0]` once ($1 \to 2$).
- Increase `nums2[2]` once ($6 \to 7$).
Minimum sum of squared difference: $(2-5)^2 + (4-8)^2 + (10-7)^2 + (12-9)^2 = 9 + 16 + 9 + 9 = 43$.

---

## Constraints

- $n == \text{nums1.length} == \text{nums2.length}$
- $1 \le n \le 10^5$
- $0 \le \text{nums1}[i], \text{nums2}[i] \le 10^5$
- $0 \le k_1, k_2 \le 10^9$

---

## Solution Approach

### Key Insights:
1. **Total Operation Budget:**
   Modifying `nums1[i]` by $\pm 1$ or `nums2[i]` by $\pm 1$ can both reduce $| \text{nums1}[i] - \text{nums2}[i] |$ by $1$. Thus, we have a total operation budget $k = k_1 + k_2$.

2. **Greedy Reduction (Bucket / Frequency Array):**
   To minimize the sum of squares $\sum d_i^2$, we should always reduce the **largest absolute differences** first:
   - Compute initial absolute differences $d_i = |\text{nums1}[i] - \text{nums2}[i]|$ and find $\text{max\_diff} = \max(d_i)$.
   - Build a frequency array `count[v]` storing how many elements have difference `v`.
   - Iterate $v$ from $\text{max\_diff}$ down to $1$:
     - Shift up to `take = min(count[v], k)` elements from difference $v$ to $v - 1$.
     - Decrement $k \gets k - \text{take}$.
   - Sum $\text{count}[v] \times v^2$ for all remaining differences.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + M)$, where $N = \text{nums1.length}$ and $M = \max(|\text{nums1}[i] - \text{nums2}[i]|) \le 10^5$. Linear time processing.
- **Space Complexity:** $\mathcal{O}(M)$ for the frequency bucket array.
