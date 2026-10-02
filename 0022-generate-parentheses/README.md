# 0022. Generate Parentheses

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming, Backtracking  
**LeetCode Link:** [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

---

## Problem Description

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

---

## Examples

### Example 1:

**Input:** `n = 3`  
**Output:** `["((()))","(()())","(())()","()(())","()()()"]`

---

### Example 2:

**Input:** `n = 1`  
**Output:** `["()"]`

---

## Constraints

- $1 \le n \le 8$

---

## Solution Approach

### Backtracking Strategy:
Instead of generating all $2^{2n}$ sequences of length $2n$ and validating them, we can build valid combinations directly by maintaining the count of open and closed brackets:

1. **Parameters:**
   - `open`: count of `'('` added so far.
   - `close`: count of `')'` added so far.
   - `max`: target number of pairs $n$.

2. **Rules for Backtracking:**
   - **Add `'('`:** Allowed whenever `open < max`.
   - **Add `')'`:** Allowed whenever `close < open` (ensuring we never close more brackets than have been opened).
   - **Base Case:** When `current.length() == max * 2`, a valid combination is formed, append it to `result`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right)$, bounded by the $n$-th Catalan number $C_n = \frac{1}{n+1}\binom{2n}{n}$. For $n \le 8$, $C_8 = 1430$ combinations.
- **Space Complexity:** $\mathcal{O}(n)$ for recursion stack depth and current string construction.
