# 0020. Valid Parentheses

**Difficulty:** Easy  
**Topics:** String, Stack  
**LeetCode Link:** [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

---

## Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

---

## Examples

### Example 1:

**Input:** `s = "()"`  
**Output:** `true`

---

### Example 2:

**Input:** `s = "()[]{}"`  
**Output:** `true`

---

### Example 3:

**Input:** `s = "(]"`  
**Output:** `false`

---

### Example 4:

**Input:** `s = "([])"`  
**Output:** `true`

---

### Example 5:

**Input:** `s = "([)]"`  
**Output:** `false`

---

## Constraints

- $1 \le s.length \le 10^4$
- `s` consists of parentheses only `'()[]{}'`.

---

## Solution Approach

### Stack Data Structure (LIFO Matching):
1. Use a `std::stack<char>` to keep track of opening brackets:
   - When encountering an opening bracket (`'('`, `'{'`, `'['`), push it onto the stack.
   - When encountering a closing bracket (`')'`, `'}'`, `']'`):
     - If the stack is empty, return `false` (closing bracket without matching opening bracket).
     - Check if the top of the stack matches the expected opening bracket. If it matches, pop it; otherwise, return `false`.
2. After processing all characters, return `true` if and only if the stack is completely empty.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. We iterate through the string once, performing $\mathcal{O}(1)$ stack operations for each character.
- **Space Complexity:** $\mathcal{O}(N)$ in the worst case where all characters are opening brackets stored on the stack.
