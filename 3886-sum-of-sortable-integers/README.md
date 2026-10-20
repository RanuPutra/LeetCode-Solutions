# 3886. Sum of Sortable Integers

**Difficulty:** Hard  
**Topics:** Array, Math, Number Theory  
**LeetCode Link:** [3886. Sum of Sortable Integers](https://leetcode.com/problems/sum-of-sortable-integers/)

---

## Problem Description

You are given an integer array `nums` of length `n`.

An integer `k` is called **sortable** if `k` divides `n` and you can sort `nums` in non-decreasing order by sequentially performing the following operations:
1. Partition `nums` into consecutive subarrays of length `k`.
2. Cyclically rotate each subarray independently any number of times to the left or to the right.

Return an integer denoting the **sum of all possible sortable integers $k$**.

---

## Examples

### Example 1:

**Input:** `nums = [3,1,2]`  
**Output:** `3`  
**Explanation:**  
For $n = 3$, possible divisors are 1 and 3.
- For $k = 1$: each subarray has one element. No rotation can sort the array.
- For $k = 3$: the single subarray `[3, 1, 2]` can be rotated once to produce `[1, 2, 3]`, which is sorted.
Only $k = 3$ is sortable. Hence, the answer is $3$.

---

### Example 2:

**Input:** `nums = [7,6,5]`  
**Output:** `0`  
**Explanation:**  
For $n = 3$, possible divisors are 1 and 3. Neither $k = 1$ nor $k = 3$ can be rotated into non-decreasing order. Hence, the answer is $0$.

---

### Example 3:

**Input:** `nums = [5,8]`  
**Output:** `3`  
**Explanation:**  
For $n = 2$, possible divisors are 1 and 2. Since `[5, 8]` is already sorted, every divisor is sortable. Hence, the answer is $1 + 2 = 3$.

---

## Constraints

- $1 \le n == \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^5$

---

## Solution Approach

### Divisor Search & Block Verification:
1. **Find Divisors:**
   Since $k$ must divide $n$, iterate $k$ from $1$ up to $\lfloor\sqrt{n}\rfloor$. For each divisor pair $(k, n / k)$, test if the divisor is sortable.

2. **Block-by-Block Rotatability Check:**
   For a fixed $k$, partition `nums` into blocks of size $k$:
   - **Internal Cyclical Order:** A block of length $k$ can be cyclically rotated into non-decreasing order if and only if there is at most **one** cyclic descent:
     $$\sum_{j=0}^{k-1} [nums[i+j] > nums[i + (j+1)\%k]] \le 1$$
   - **Inter-Block Monotonicity:** The minimum element of block $b$ must be greater than or equal to the maximum element of block $b - 1$ ($\min(B_b) \ge \max(B_{b-1})$).

3. If all blocks satisfy both criteria, $k$ is sortable and added to `total_sum`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(d(n) \cdot n)$, where $d(n)$ is the number of divisors of $n$. For $n \le 10^5$, $\max d(n) = 128$, and the total operations across all divisors $\sum_{k|n} n = n \cdot d(n)$ easily passes in time.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
