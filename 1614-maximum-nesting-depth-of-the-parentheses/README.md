# 1614. Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**LeetCode Link:** [1614. Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

---

## Problem Description

Given a valid parentheses string `s`, return the **nesting depth** of `s`. The nesting depth is the maximum number of nested parentheses.

---

## Examples

### Example 1:

**Input:** `s = "(1+(2*3)+((8)/4))+1"`  
**Output:** `3`  
**Explanation:** Digit `8` is inside 3 nested parentheses in the string.

---

### Example 2:

**Input:** `s = "(1)+((2))+(((3)))"`  
**Output:** `3`  
**Explanation:** Digit `3` is inside 3 nested parentheses in the string.

---

### Example 3:

**Input:** `s = "()(())((()()))"`  
**Output:** `3`

---

## Constraints

- $1 \le s.length \le 100$
- `s` consists of digits `0-9` and characters `'+'`, `'-'`, `'*'`, `'/'`, `'('`, and `')'`.
- It is guaranteed that parentheses expression `s` is a Valid Parentheses String (VPS).

---

## Solution Approach

### Single-Pass Counter Tracking:
Since the string `s` is guaranteed to be a valid parentheses string (VPS), we do not need a full stack data structure. A simple counter is sufficient:

1. Maintain `current_depth = 0` and `max_depth = 0`.
2. Iterate through each character `c` in `s`:
   - If `c == '('`: increment `current_depth` and update `max_depth = max(max_depth, current_depth)`.
   - If `c == ')'`: decrement `current_depth`.
3. Return `max_depth`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$, iterating over string `s` once.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
