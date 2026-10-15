# 2913. Subarrays Distinct Element Sum of Squares I

**Difficulty:** Easy  
**Topics:** Array, Hash Table  
**LeetCode Link:** [2913. Subarrays Distinct Element Sum of Squares I](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)

---

## Problem Description

You are given a 0-indexed integer array `nums`.

The **distinct count** of a subarray of `nums` is defined as:
Let `nums[i..j]` be a subarray of `nums` consisting of all indices from `i` to `j` such that $0 \le i \le j < \text{nums.length}$. Then the number of distinct values in `nums[i..j]` is called the distinct count of `nums[i..j]`.

Return the **sum of the squares of distinct counts** of all subarrays of `nums`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

---

## Examples

### Example 1:

**Input:** `nums = [1,2,1]`  
**Output:** `15`  
**Explanation:**  
Six possible subarrays:
- `[1]`: 1 distinct value
- `[2]`: 1 distinct value
- `[1]`: 1 distinct value
- `[1,2]`: 2 distinct values
- `[2,1]`: 2 distinct values
- `[1,2,1]`: 2 distinct values

The sum of the squares of the distinct counts is:
$$1^2 + 1^2 + 1^2 + 2^2 + 2^2 + 2^2 = 1 + 1 + 1 + 4 + 4 + 4 = 15$$

---

### Example 2:

**Input:** `nums = [1,1]`  
**Output:** `3`  
**Explanation:**  
Three possible subarrays:
- `[1]`: 1 distinct value
- `[1]`: 1 distinct value
- `[1,1]`: 1 distinct value

The sum of the squares of the distinct counts is:
$$1^2 + 1^2 + 1^2 = 3$$

---

## Constraints

- $1 \le \text{nums.length} \le 100$
- $1 \le \text{nums}[i] \le 100$

---

## Solution Approach

### Nested Loop with Hash Set:
Since the constraints are very small ($N \le 100$), we can enumerate all possible subarrays directly:
1. Fix the starting index `i` from $0$ to $N - 1$.
2. Maintain an `unordered_set<int> distinctElements` for each starting index.
3. Iterate the ending index `j` from `i` to $N - 1$:
   - Insert `nums[j]` into the set.
   - The number of distinct elements in `nums[i..j]` is `distinctElements.size()`.
   - Add $\text{count}^2$ to `totalSum`.
4. Return `totalSum`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$, where $N = \text{nums.length} \le 100$. Generating and updating sets for all pairs $(i, j)$ takes $\sim \frac{100 \times 101}{2} \approx 5050$ iterations, which runs instantaneously.
- **Space Complexity:** $\mathcal{O}(N)$ to store unique elements in the set for each subarray.
