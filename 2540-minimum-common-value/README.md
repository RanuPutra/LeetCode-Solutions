# 2540. Minimum Common Value

**Difficulty:** Easy  
**Topics:** Array, Hash Table, Two Pointers, Binary Search  
**LeetCode Link:** [2540. Minimum Common Value](https://leetcode.com/problems/minimum-common-value/)

---

## Problem Description

Given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, return the **minimum integer common to both arrays**. If there is no common integer amongst `nums1` and `nums2`, return `-1`.

Note that an integer is said to be common to `nums1` and `nums2` if both arrays have at least one occurrence of that integer.

---

## Examples

### Example 1:

**Input:** `nums1 = [1,2,3], nums2 = [2,4]`  
**Output:** `2`  
**Explanation:** The smallest element common to both arrays is 2, so we return 2.

---

### Example 2:

**Input:** `nums1 = [1,2,3,6], nums2 = [2,3,4,5]`  
**Output:** `2`  
**Explanation:** There are two common elements in the array: 2 and 3, out of which 2 is the smallest, so 2 is returned.

---

## Constraints

- $1 \le \text{nums1.length}, \text{nums2.length} \le 10^5$
- $1 \le \text{nums1}[i], \text{nums2}[j] \le 10^9$
- Both `nums1` and `nums2` are sorted in non-decreasing order.

---

## Solution Approach

### Two Pointers:
Since both arrays are already sorted in non-decreasing order, we can use two pointers `i` and `j` initialized at the beginning of `nums1` and `nums2` respectively:
1. Compare `nums1[i]` and `nums2[j]`:
   - If `nums1[i] == nums2[j]`: Since we start from the beginning of sorted arrays, this is guaranteed to be the minimum common value. Return it immediately.
   - If `nums1[i] < nums2[j]`: Increment `i++` to find a larger value.
   - If `nums1[i] > nums2[j]`: Increment `j++` to find a larger value.
2. If either pointer exceeds array bounds without a match, return `-1`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + M)$, where $N = \text{nums1.length}$ and $M = \text{nums2.length}$. In the worst case, each element is visited at most once.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
