# 3644. Maximum K to Sort a Permutation

**Difficulty:** Medium  
**Topics:** Array, Bit Manipulation  
**LeetCode Link:** [3644. Maximum K to Sort a Permutation](https://leetcode.com/problems/maximum-k-to-sort-a-permutation/)

---

## Problem Description

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the numbers in the range `[0..n - 1]`.

You may swap elements at indices `i` and `j` only if `nums[i] AND nums[j] == k`, where `AND` denotes the bitwise AND operation and `k` is a non-negative integer.

Return the **maximum value of $k$** such that the array can be sorted in non-decreasing order using any number of such swaps. If `nums` is already sorted, return `0`.

---

## Examples

### Example 1:

**Input:** `nums = [0,3,2,1]`  
**Output:** `1`  
**Explanation:**  
Choose $k = 1$. Swapping `nums[1] = 3` and `nums[3] = 1` is allowed since `nums[1] AND nums[3] == 1`, resulting in a sorted permutation: `[0, 1, 2, 3]`.

---

### Example 2:

**Input:** `nums = [0,1,3,2]`  
**Output:** `2`  
**Explanation:**  
Choose $k = 2$. Swapping `nums[2] = 3` and `nums[3] = 2` is allowed since `nums[2] AND nums[3] == 2`, resulting in a sorted permutation: `[0, 1, 2, 3]`.

---

### Example 3:

**Input:** `nums = [3,2,1,0]`  
**Output:** `0`  
**Explanation:**  
Only $k = 0$ allows sorting since no greater $k$ allows the required swaps where `nums[i] AND nums[j] == k`.

---

## Constraints

- $1 \le n == \text{nums.length} \le 10^5$
- $0 \le \text{nums}[i] \le n - 1$
- `nums` is a permutation of integers from $0$ to $n - 1$.

---

## Solution Approach

### Bitwise AND of Misplaced Elements:
1. **Misplaced Elements:**
   - Any element that is already in its correct position (`nums[i] == i`) does not need to move.
   - Any element that is misplaced (`nums[i] != i`) must participate in at least one swap to reach its target index.
2. **Swap Requirement:**
   - If two elements $u$ and $v$ are swapped, their bitwise AND must equal $k$ ($u \ \& \ v == k$).
   - This means that any bit set to `1` in $k$ must also be set to `1` in both $u$ and $v$.
   - Consequently, for every element that needs to be moved, $k$ must be a submask of that element.
3. **Maximizing $k$:**
   - To make $k$ as large as possible while allowing all misplaced elements to move, $k$ must consist of all common bits across all misplaced elements.
   - Therefore, $k$ is the cumulative bitwise AND of all elements where `nums[i] != i`.
   - If the array is already sorted (no misplaced elements), return `0` as specified.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(n)$, where $n$ is the length of `nums`. A single linear scan checks for misplaced elements and computes the bitwise AND.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
