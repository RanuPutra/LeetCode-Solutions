# 3727. Maximum Alternating Sum of Squares

**Difficulty:** Medium  
**Topics:** Array, Math, Greedy, Sorting  
**LeetCode Link:** [3727. Maximum Alternating Sum of Squares](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)

---

## Problem Description

You are given an integer array `nums`. You may rearrange the elements in any order.

The **alternating score** of an array `arr` is defined as:
$$\text{score} = \text{arr}[0]^2 - \text{arr}[1]^2 + \text{arr}[2]^2 - \text{arr}[3]^2 + \dots$$

Return an integer denoting the **maximum possible alternating score** of `nums` after rearranging its elements.

---

## Examples

### Example 1:

**Input:** `nums = [1,2,3]`  
**Output:** `12`  
**Explanation:**  
A possible rearrangement for `nums` is `[2,1,3]`.  
$$\text{score} = 2^2 - 1^2 + 3^2 = 4 - 1 + 9 = 12$$

---

### Example 2:

**Input:** `nums = [1,-1,2,-2,3,-3]`  
**Output:** `16`  
**Explanation:**  
A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`.  
$$\text{score} = (-3)^2 - (-1)^2 + (-2)^2 - (1)^2 + (3)^2 - (2)^2 = 9 - 1 + 4 - 1 + 9 - 4 = 16$$

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-4 \times 10^4 \le \text{nums}[i] \le 4 \times 10^4$

---

## Solution Approach

### Greedy Strategy:
1. Regardless of the ordering, the alternating score sums the squares of $\lceil n / 2 \rceil$ elements with positive signs ($+$) and subtracts the squares of $\lfloor n / 2 \rfloor$ elements with negative signs ($-$).
2. To maximize the total sum:
   - Compute $x_i = \text{nums}[i]^2$ for all elements.
   - Sort the squared values in ascending order.
   - Assign negative signs to the $\lfloor n / 2 \rfloor$ smallest squares.
   - Assign positive signs to the remaining largest squares.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$, where $N = \text{nums.length}$, due to sorting the squares array.
- **Space Complexity:** $\mathcal{O}(N)$ to store the array of squared numbers.
