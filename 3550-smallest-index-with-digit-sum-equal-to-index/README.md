# 3550. Smallest Index With Digit Sum Equal to Index

**Difficulty:** Easy  
**Topics:** Array, Math  
**LeetCode Link:** [3550. Smallest Index With Digit Sum Equal to Index](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

---

## Problem Description

You are given an integer array `nums`.

Return the **smallest index** `i` such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

---

## Examples

### Example 1:

**Input:** `nums = [1,3,2]`  
**Output:** `2`  
**Explanation:**  
For `nums[2] = 2`, the sum of digits is `2`, which is equal to index `i = 2`. Thus, the output is `2`.

---

### Example 2:

**Input:** `nums = [1,10,11]`  
**Output:** `1`  
**Explanation:**  
- For `nums[1] = 10`, the sum of digits is $1 + 0 = 1$, which is equal to index $i = 1$.
- For `nums[2] = 11`, the sum of digits is $1 + 1 = 2$, which is equal to index $i = 2$.

Since index `1` is the smallest satisfying index, the output is `1`.

---

### Example 3:

**Input:** `nums = [1,2,3]`  
**Output:** `-1`  
**Explanation:**  
No index satisfies the condition, so the output is `-1`.

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $0 \le \text{nums}[i] \le 1000$

---

## Solution Approach

1. **Linear Scan:**
   Iterate through the array starting from index $i = 0$ up to $N - 1$.
2. **Digit Sum Helper:**
   For each element `nums[i]`, compute its digit sum by repeatedly taking `n % 10` and dividing by $10$.
3. **Early Exit:**
   Since we iterate from index $0$ upwards, the first index $i$ where `getDigitSum(nums[i]) == i` is guaranteed to be the smallest index. Return $i$ immediately.
4. If the loop completes without finding a match, return `-1`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log_{10}(\text{max\_val}))$, where $N = \text{nums.length}$. Given $\text{nums}[i] \le 1000$, calculating digit sum takes at most 4 operations, so the overall complexity is $\mathcal{O}(N)$.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
