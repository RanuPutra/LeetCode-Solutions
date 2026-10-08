# 1021. Remove Outermost Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**LeetCode Link:** [1021. Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)

---

## Problem Description

A valid parentheses string is either empty `""`, `"(" + A + ")"`, or `A + B`, where `A` and `B` are valid parentheses strings, and `+` represents string concatenation.

A valid parentheses string `s` is **primitive** if it is nonempty, and there does not exist a way to split it into `s = A + B`, with `A` and `B` nonempty valid parentheses strings.

Given a valid parentheses string `s`, consider its primitive decomposition: $s = P_1 + P_2 + \dots + P_k$, where $P_i$ are primitive valid parentheses strings.

Return `s` after removing the outermost parentheses of every primitive string in the primitive decomposition of `s`.

---

## Examples

### Example 1:

**Input:** `s = "(()())(())"`  
**Output:** `"()()()"`  
**Explanation:**  
The input string is `"(()())(())"`, with primitive decomposition `"(()())" + "(())"`.  
After removing outer parentheses of each part: `"()()"` + `"()"` = `"()()()"`.

---

### Example 2:

**Input:** `s = "(()())(())(()(()))"`  
**Output:** `"()()()()(())"`  
**Explanation:**  
The input string is `"(()())(())(()(()))"`, with primitive decomposition `"(()())" + "(())" + "(()(()))"`.  
After removing outer parentheses of each part: `"()()"` + `"()"` + `"()(())"` = `"()()()()(())"`.

---

### Example 3:

**Input:** `s = "()()"`  
**Output:** `""`  
**Explanation:**  
The input string is `"()()"`, with primitive decomposition `"()"` + `"()"`.  
After removing outer parentheses of each part: `""` + `""` = `""`.

---

## Constraints

- $1 \le s.length \le 10^5$
- `s[i]` is either `'('` or `')'`.
- `s` is a valid parentheses string.

---

## Solution Approach

### Single-Pass Open Counter Tracking:
Maintain a counter `opened` tracking the number of active open parentheses:

1. **When `c == '('`:**
   - If `opened > 0`, it is an **inner** open parenthesis, append `c` to `res`.
   - Increment `opened++`.
2. **When `c == ')'`:**
   - Decrement `opened--`.
   - If `opened > 0`, it is an **inner** close parenthesis, append `c` to `res`.
3. The outermost open `(` (where `opened` rises from `0` to `1`) and outermost close `)` (where `opened` drops from `1` to `0`) are ignored!

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. We iterate through the string once.
- **Space Complexity:** $\mathcal{O}(N)$ for building the output string `res`.
