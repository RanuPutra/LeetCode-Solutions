# 0032. Longest Valid Parentheses

**Difficulty:** Hard  
**Topics:** String, Dynamic Programming, Stack  
**LeetCode Link:** [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

---

## Problem Description

Given a string containing just the characters `'('` and `')'`, return the length of the **longest valid (well-formed) parentheses substring**.

---

## Examples

### Example 1:

**Input:** `s = "(()"`  
**Output:** `2`  
**Explanation:** The longest valid parentheses substring is `"()"`.

---

### Example 2:

**Input:** `s = ")()())"`  
**Output:** `4`  
**Explanation:** The longest valid parentheses substring is `"()()"`.

---

### Example 3:

**Input:** `s = ""`  
**Output:** `0`

---

## Constraints

- $0 \le s.length \le 3 \times 10^4$
- `s[i]` is `'('` or `')'`.

---

## Solution Approach

### Stack of Indices Boundary Technique:
Instead of pushing characters onto the stack, we push **indices** of characters to easily track substring lengths:

1. **Base Boundary Initialization:**
   Initialize `stack<int> st` and push `-1` as an initial boundary marker.

2. **Iteration:**
   - If `s[i] == '('`: push index `i` onto the stack.
   - If `s[i] == ')'`:
     - Pop the top index from the stack.
     - If the stack becomes empty: the current `')'` has no matching `'('`. Push `i` onto the stack as the new boundary marker.
     - If the stack is not empty: calculate the valid substring length as `i - st.top()` and update `maxLen = max(maxLen, i - st.top())`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. We scan the string once and perform $\mathcal{O}(1)$ stack operations per character.
- **Space Complexity:** $\mathcal{O}(N)$ in worst case to store character indices in the stack.
