# 0921. Minimum Add to Make Parentheses Valid

**Difficulty:** Medium  
**Topics:** String, Stack, Greedy  
**LeetCode Link:** [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

---

## Problem Description

A parentheses string is valid if and only if:
- It is the empty string,
- It can be written as $AB$ (concatenation of valid strings $A$ and $B$), or
- It can be written as $(A)$, where $A$ is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

Return the **minimum number of moves** required to make `s` valid.

---

## Examples

### Example 1:

**Input:** `s = "()"`  
**Output:** `1`

---

### Example 2:

**Input:** `s = "((("`  
**Output:** `3`

---

## Constraints

- $1 \le s.length \le 1000$
- `s[i]` is either `'('` or `')'`.

---

## Solution Approach

### Single-Pass Greedy Counter:
We track two variables while iterating through the string `s`:
1. `open_needed`: The count of unmatched opening brackets `'('` encountered so far.
2. `add_needed`: The count of closing brackets `')'` that lack a corresponding opening bracket.

### Traversal Logic:
- If `c == '('`: increment `open_needed++`.
- If `c == ')'`:
  - If `open_needed > 0`: match it with a previously open bracket by decrementing `open_needed--`.
  - Else: increment `add_needed++` (since this `')'` needs a preceding `'('`).

### Result:
The total minimum insertions required is `open_needed + add_needed`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. We perform a single pass over the string.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
