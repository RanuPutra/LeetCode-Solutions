# 1569. Number of Ways to Reorder Array to Get Same BST

**Difficulty:** Hard  
**Topics:** Array, Math, Divide and Conquer, Dynamic Programming, Tree, Binary Search Tree, Combinatorics, Binary Tree  
**LeetCode Link:** [1569. Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

---

## Problem Description

Given an array `nums` that represents a permutation of integers from `1` to `n`. We are going to construct a binary search tree (BST) by inserting the elements of `nums` in order into an initially empty BST. Find the number of different ways to reorder `nums` so that the constructed BST is identical to that formed from the original array `nums`.

- For example, given `nums = [2,1,3]`, we have `2` as the root, `1` as a left child, and `3` as a right child. The array `[2,3,1]` also yields the same BST, but `[3,2,1]` yields a different BST.

Return the **number of ways to reorder `nums`** such that the BST formed is identical to the original BST formed from `nums`.

Since the answer may be very large, return it **modulo $10^9 + 7$**.

---

## Examples

### Example 1:

**Input:** `nums = [2,1,3]`  
**Output:** `1`  
**Explanation:** We can reorder `nums` to be `[2,3,1]` which will yield the same BST. There are no other ways to reorder `nums` which will yield the same BST.

---

### Example 2:

**Input:** `nums = [3,4,5,1,2]`  
**Output:** `5`  
**Explanation:** The following 5 arrays will yield the same BST: 
- `[3,1,2,4,5]`
- `[3,1,4,2,5]`
- `[3,1,4,5,2]`
- `[3,4,1,2,5]`
- `[3,4,1,5,2]`

---

### Example 3:

**Input:** `nums = [1,2,3]`  
**Output:** `0`  
**Explanation:** There are no other orderings of `nums` that will yield the same BST.

---

## Constraints

- $1 \le \text{nums.length} \le 1000$
- $1 \le \text{nums}[i] \le \text{nums.length}$
- All integers in `nums` are distinct.

---

## Solution Approach

### Divide and Conquer + Combinatorics:
1. **Root Element:**
   The first element `nums[0]` must remain at the very front to ensure the root of the BST does not change.
2. **Subtree Partitioning:**
   - Any element smaller than `nums[0]` belongs to the left subtree (`left`).
   - Any element larger than `nums[0]` belongs to the right subtree (`right`).
   - The relative order within `left` and `right` determines the structure of the left and right subtrees independently.
3. **Interleaving Left and Right Sequences:**
   - Elements from the left and right subtrees can be interleaved in any way as long as their individual relative internal order is preserved.
   - The number of ways to interleave them is given by the binomial coefficient:
     $$\binom{|left| + |right|}{|left|} = \binom{|left| + |right|}{|right|}$$
4. **Recurrence:**
   $$\text{ways}(nums) = \binom{|left| + |right|}{|left|} \times \text{ways}(left) \times \text{ways}(right) \pmod{10^9 + 7}$$
5. **Base Cases:**
   - If $|nums| \le 2$, $\text{ways}(nums) = 1$.
6. **Result:**
   - We must subtract 1 because the original ordering does not count as a *reordering*: $(\text{ways}(nums) - 1) \pmod{10^9 + 7}$.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$ to precompute Pascal's triangle and partition arrays recursively. Given $N \le 1000$, $N^2 \approx 10^6$ operations, which runs well within time limits.
- **Space Complexity:** $\mathcal{O}(N^2)$ for Pascal's triangle combination table and recursion stack.
