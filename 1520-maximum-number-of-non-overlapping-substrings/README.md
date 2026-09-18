# 1520. Maximum Number of Non-Overlapping Substrings

**Difficulty:** Hard  
**Topics:** String, Greedy, Two Pointers  
**LeetCode Link:** [1520. Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

---

## Problem Description

Given a string `s` of lowercase letters, find the **maximum number of non-empty substrings** of `s` that meet the following conditions:
1. The substrings do not overlap (i.e. for any two substrings `s[i..j]` and `s[x..y]`, either $j < x$ or $i > y$).
2. A substring that contains a certain character `c` must also contain **all occurrences** of `c` in `s`.

Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with **minimum total length**.

You can return the substrings in any order.

---

## Examples

### Example 1:

**Input:** `s = "adefaddaccc"`  
**Output:** `["e","f","ccc"]`  
**Explanation:**  
The possible valid substrings meeting condition (2) are:
- `"adefaddaccc"`
- `"adefadda"`
- `"ef"`
- `"e"`
- `"f"`
- `"ccc"`

If we select `["e", "f", "ccc"]`, we get 3 non-overlapping valid substrings. No other valid choice gives more than 3 substrings.

---

### Example 2:

**Input:** `s = "abbaccd"`  
**Output:** `["d","bb","cc"]`  
**Explanation:**  
Both `["d", "bb", "cc"]` and `["d", "abba", "cc"]` give 3 substrings, but `["d", "bb", "cc"]` has smaller total length.

---

## Constraints

- $1 \le s.length \le 10^5$
- `s` contains only lowercase English letters.

---

## Solution Approach

1. **Find First and Last Occurrence:**
   Find the minimum `l[c]` and maximum `r[c]` indices for each character `c` present in `s`.

2. **Expand Valid Intervals:**
   For each character `i` (from 'a' to 'z'), attempt to form a valid substring starting at `l[i]`:
   - Expand `right = max(right, r[s[j]])` for every character `s[j]` inside `[left, right]`.
   - If any character inside `[left, right]` has its left occurrence before `left` (`l[s[j]] < left`), then an interval starting at `left` cannot be validly closed without including characters prior to `left`. Thus, discard it.
   - If valid, save `{right, left}` interval.

3. **Greedy Interval Scheduling:**
   - Sort the valid intervals by their end points (`right` index) in ascending order.
   - Process intervals greedily: select an interval if its start index `left > lastRight`.
   - Sorting by `right` index automatically maximizes the count of non-overlapping intervals while minimizing total length!

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + \Sigma^2)$, where $N = s.length$ and $\Sigma = 26$ is the alphabet size. Since $\Sigma = 26$, expanding intervals takes at most $26 \times 26$ steps, making the overall time complexity **$\mathcal{O}(N)$**.
- **Space Complexity:** $\mathcal{O}(\Sigma)$ to store character occurrences and valid intervals ($\mathcal{O}(1)$ space).
