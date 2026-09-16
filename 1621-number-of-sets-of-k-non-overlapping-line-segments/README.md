# 1621. Number of Sets of K Non-Overlapping Line Segments

**Difficulty:** Medium  
**Topics:** Math, Dynamic Programming, Combinatorics  
**LeetCode Link:** [1621. Number of Sets of K Non-Overlapping Line Segments](https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/)

---

## Problem Description

Given `n` points on a 1D plane (numbered `0` to `n - 1`), find the number of ways to choose `k` non-overlapping line segments such that each segment covers two or more points. 

Two line segments are considered **non-overlapping** if they do not share any common points, except possibly their endpoints (i.e. they can touch at an endpoint). The segments do not need to cover all `n` points.

Return the number of ways to choose `k` non-overlapping line segments. Since the answer may be very large, return it **modulo $10^9 + 7$**.

---

## Examples

### Example 1:

**Input:** `n = 4, k = 2`  
**Output:** `5`  
**Explanation:** The 5 combinations of 2 line segments are:
- `{(0, 2), (2, 3)}`
- `{(0, 1), (1, 3)}`
- `{(0, 1), (2, 3)}`
- `{(1, 2), (2, 3)}`
- `{(0, 1), (1, 2)}`

---

### Example 2:

**Input:** `n = 3, k = 1`  
**Output:** `3`  
**Explanation:** The 3 combinations of 1 line segment are:
- `{(0, 1)}`
- `{(0, 2)}`
- `{(1, 2)}`

---

### Example 3:

**Input:** `n = 30, k = 7`  
**Output:** `796297179`

---

## Constraints

- $2 \le n \le 1000$
- $1 \le k \le n - 1$

---

## Solution Approach

### Combinatorial Reduction (Stars and Bars):

1. **Model as Gaps and Segment Lengths:**
   The total span across $n$ points is $n - 1$ units. Suppose we select $k$ segments. Let $L_1, L_2, \dots, L_k \ge 1$ be the lengths of the segments, and $G_0, G_1, \dots, G_k \ge 0$ be the gap lengths between/around the segments:
   $$G_0 + L_1 + G_1 + L_2 + \dots + L_k + G_k = n - 1$$

2. **Transform to Non-Negative Variables:**
   Since each segment length $L_i \ge 1$, substitute $L_i' = L_i - 1 \ge 0$:
   $$G_0 + L_1' + G_1 + L_2' + \dots + L_k' + G_k = n - 1 - k$$

3. **Stars and Bars Formula:**
   This is a system of $2k + 1$ non-negative variables summing to $n - 1 - k$. The number of non-negative integer solutions is given by:
   $$\binom{(n - 1 - k) + (2k + 1) - 1}{(2k + 1) - 1} = \binom{n + k - 1}{2k}$$

4. **Modular Arithmetic:**
   We compute $\binom{n + k - 1}{2k} \pmod{10^9 + 7}$ using modular inverse via Fermat's Little Theorem ($a^{p-2} \equiv a^{-1} \pmod p$).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(k \log \text{MOD})$ to compute the combination $\binom{n+k-1}{2k} \pmod{10^9+7}$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
