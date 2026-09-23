# 1658. Minimum Operations to Reduce X to Zero

**Difficulty:** Medium  
**Topics:** Array, Hash Table, Sliding Window, Prefix Sum  
**LeetCode Link:** [1658. Minimum Operations to Reduce X to Zero](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

---

## Problem Description

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this modifies the array for future operations.

Return the **minimum number of operations** to reduce `x` to exactly `0` if it is possible, otherwise, return `-1`.

---

## Examples

### Example 1:

**Input:** `nums = [1,1,4,2,3], x = 5`  
**Output:** `2`  
**Explanation:** The optimal solution is to remove the last two elements (`3` and `2`) to reduce `x` to zero.

---

### Example 2:

**Input:** `nums = [5,6,7,8,9], x = 4`  
**Output:** `-1`  
**Explanation:** Total sum of elements is larger than `x` and no prefix/suffix sum equals `x`.

---

### Example 3:

**Input:** `nums = [3,2,20,1,1,3], x = 10`  
**Output:** `5`  
**Explanation:** The optimal solution is to remove the last 3 elements (`1, 1, 3`) and the first 2 elements (`3, 2`) for a total of 5 operations.

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^4$
- $1 \le x \le 10^9$

---

## Solution Approach

### Problem Inversion (Sliding Window):
Removing elements from the prefix and/or suffix to sum to $x$ is equivalent to finding the **longest contiguous subarray** whose sum equals $\text{target} = \text{total\_sum} - x$.

Once we find the maximum length `max_len` of such a subarray:
$$\text{min\_operations} = \text{nums.length} - \text{max\_len}$$

### Algorithm:
1. Calculate `total_sum` of all elements in `nums`.
2. Compute `target = total_sum - x`.
   - If `target < 0`, it is impossible to reach $x$, return `-1`.
   - If `target == 0`, we must remove all elements, return `nums.length`.
3. Use a two-pointer **Sliding Window** to maintain `current_sum`:
   - Expand `right` pointer and add `nums[right]` to `current_sum`.
   - While `current_sum > target`, shrink window by advancing `left` pointer.
   - When `current_sum == target`, update `max_len = max(max_len, right - left + 1)`.
4. Return `nums.length - max_len` if a valid subarray was found; otherwise `-1`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = \text{nums.length}$. Each element is processed at most twice by the `left` and `right` sliding window pointers.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
