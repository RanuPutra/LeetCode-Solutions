# 0301. Remove Invalid Parentheses

**Difficulty:** Hard  
**Topics:** String, Backtracking, Breadth-First Search  
**LeetCode Link:** [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

---

## Problem Description

Given a string `s` that contains parentheses and letters, remove the **minimum number of invalid parentheses** to make the input string valid.

Return a list of **unique strings** that are valid with the minimum number of removals. You may return the answer in any order.

---

## Examples

### Example 1:

**Input:** `s = "()())()"`  
**Output:** `["(())()","()()()"]`

---

### Example 2:

**Input:** `s = "(a)())()"`  
**Output:** `["(a())()","(a)()()"]`

---

### Example 3:

**Input:** `s = ")("`  
**Output:** `[""]`

---

## Constraints

- $1 \le s.length \le 25$
- `s` consists of lowercase English letters and parentheses `'('` and `')'`.
- There will be at most 20 parentheses in `s`.

---

## Solution Approach

### Breadth-First Search (BFS) Level-Order Exploration:
BFS guarantees that the first valid string(s) encountered will have the **minimum number of removals** (minimum tree depth):

1. **Queue & Visited Set:**
   - Initialize `queue<string> q` with original string `s` and `unordered_set<string> visited` to prevent processing duplicate strings.
2. **Level-by-Level Validation:**
   - Pop `current` string from queue and check if `isValid(current)`.
   - Once a valid string is found, set a flag `found = true`.
   - When `found == true`, stop generating child strings for deeper levels. All valid strings at the current BFS level are appended to `result`.
3. **Child Generation (1-Character Removal):**
   - If no valid string has been found yet at this level, generate all possible strings by removing one parenthesis (`'('` or `')'`) from `current`.
   - Add new strings to `visited` set and `q` if not seen before.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(2^N \cdot N)$, where $N = s.length \le 25$. In the worst case, BFS explores combinations of removals. Early level-stop and visited set pruning keep actual operations small and fast.
- **Space Complexity:** $\mathcal{O}(2^N)$ for storing states in the BFS queue and `visited` set.
