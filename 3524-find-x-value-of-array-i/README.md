# 3524. Find X Value of Array I

**Difficulty:** Medium  
**Topics:** Array, Dynamic Programming, Math, Subarray  
**LeetCode Link:** [3524. Find X Value of Array I](https://leetcode.com/problems/find-x-value-of-array-i/)

---

## Problem Description

You are given an array of positive integers `nums`, and a positive integer `k`.

You are allowed to perform an operation once on `nums`, where in each operation you can remove any non-overlapping prefix and suffix from `nums` such that `nums` remains non-empty.

You need to find the **x-value** of `nums`, which is the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of `x` when divided by `k`.

Return an array `result` of size `k` where `result[x]` is the `x`-value of `nums` for $0 \le x \le k - 1$.

A **prefix** of an array is a subarray that starts from the beginning of the array and extends to any point within it.  
A **suffix** of an array is a subarray that starts at any point within the array and extends to the end of the array.  
Note that the prefix and suffix to be chosen for the operation can be empty.

---

## Examples

### Example 1:

**Input:** `nums = [1,2,3,4,5], k = 3`  
**Output:** `[9,2,4]`  
**Explanation:**  
Removing a prefix and suffix leaving a non-empty subarray is equivalent to selecting any contiguous non-empty subarray `nums[i..j]`.
- For $x = 0$, there are $9$ subarrays whose product modulo $3$ equals $0$.
- For $x = 1$, there are $2$ subarrays whose product modulo $3$ equals $1$.
- For $x = 2$, there are $4$ subarrays whose product modulo $3$ equals $2$.

---

### Example 2:

**Input:** `nums = [1,2,4,8,16,32], k = 4`  
**Output:** `[18,1,2,0]`

---

### Example 3:

**Input:** `nums = [1,1,2,1,1], k = 2`  
**Output:** `[9,6]`

---

## Constraints

- $1 \le \text{nums}[i] \le 10^9$
- $1 \le \text{nums.length} \le 10^5$
- $1 \le k \le 5$

---

## Solution Approach

### Subarray Equivalent Problem:
Removing a non-overlapping prefix and suffix such that the remaining array is non-empty is mathematically equivalent to choosing a **contiguous non-empty subarray** `nums[i..j]`.

### Dynamic Programming (Modulo Frequency DP):
Since $k \le 5$ is extremely small, we can track the product remainder of all subarrays ending at the current element:

1. Let `dp[r]` be the number of non-empty subarrays ending at index $i-1$ whose product modulo $k$ equals $r$.
2. For the current element `num` with `mod_val = num % k`:
   - Start a new single-element subarray: `next_dp[mod_val] += 1`.
   - Extend existing subarrays ending at the previous element: for each remainder $r$, transition to `new_rem = (r * mod_val) % k` and add `dp[r]` to `next_dp[new_rem]`.
3. Add `next_dp[r]` to the global `result[r]` counter for all $0 \le r < k$.
4. Update `dp = next_dp`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \cdot k)$, where $N = \text{nums.length}$. Since $k \le 5$, this runs in linear time $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(k)$ auxiliary space for the `dp` vector.
