# 0678. Valid Parenthesis String

**Difficulty:** Medium  
**Topics:** String, Dynamic Programming, Stack, Greedy  
**LeetCode Link:** [678. Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

---

## Problem Description

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:
1. Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
4. `'*'` could be treated as a single right parenthesis `')'`, a single left parenthesis `'('`, or an empty string `""`.

---

## Examples

### Example 1:

**Input:** `s = "()"`  
**Output:** `true`

---

### Example 2:

**Input:** `s = "(*)"`  
**Output:** `true`

---

### Example 3:

**Input:** `s = "(*))"`  
**Output:** `true`

---

### Example 4:

**Input:** `s = "("`  
**Output:** `false`

---

## Constraints

- $1 \le s.length \le 100$
- `s[i]` is `'('`, `')'` or `'*'`.

---

## Solution Approach

### Greedy Min/Max Open Count Tracking:
Instead of trying all 3 choices for every `'*'` (which leads to exponential $\mathcal{O}(3^N)$ branching), we track the range of possible open parenthesis counts $[ \text{minOpen}, \text{maxOpen} ]$:

1. **State Maintenance:**
   - `minOpen`: Minimum possible open parentheses remaining (treating `'*'` as `')'` when possible).
   - `maxOpen`: Maximum possible open parentheses remaining (treating `'*'` as `'('`).
2. **Transitions for character `c`:**
   - `'('`: Increment both `minOpen++` and `maxOpen++`.
   - `')'`: Decrement both `minOpen--` and `maxOpen--`.
   - `'*'`: `minOpen--` (if `'*'` $\to$ `')'`), `maxOpen++` (if `'*'` $\to$ `'('`).
3. **Pruning & Bounds:**
   - If `maxOpen < 0`: Too many closing brackets `')'`, string cannot be valid. Return `false`.
   - Clamp `minOpen = max(0, minOpen)`: `minOpen` cannot drop below 0 because we cannot have negative open parentheses before a matching position.
4. **Validation:**
   - Return `minOpen == 0` after completing the loop (verifying that 0 open parentheses is a reachable state).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. We iterate through the string once.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
