# 1190. Reverse Substrings Between Each Pair of Parentheses

**Difficulty:** Medium  
**Topics:** String, Stack  
**LeetCode Link:** [1190. Reverse Substrings Between Each Pair of Parentheses](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

---

## Problem Description

You are given a string `s` that consists of lowercase English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should **not** contain any brackets.

---

## Examples

### Example 1:

**Input:** `s = "(abcd)"`  
**Output:** `"dcba"`

---

### Example 2:

**Input:** `s = "(u(love)i)"`  
**Output:** `"iloveu"`  
**Explanation:**  
1. Reverse `"love"` $\to$ `"evol"`, string becomes `"(uevoli)"`.
2. Reverse `"uevoli"` $\to$ `"iloveu"`.

---

### Example 3:

**Input:** `s = "(ed(et(oc))el)"`  
**Output:** `"leetcode"`  
**Explanation:**  
1. Reverse `"oc"` $\to$ `"co"`, string becomes `"(ed(etco)el)"`.
2. Reverse `"etco"` $\to$ `"octe"`, string becomes `"(edocteel)"`.
3. Reverse `"edocteel"` $\to$ `"leetcode"`.

---

## Constraints

- $1 \le s.length \le 2000$
- `s` only contains lowercase English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

---

## Solution Approach

### Stack Simulation:
Use a `vector<char>` as a stack to process characters sequentially:
1. Iterate over each character `c` in `s`:
   - If `c` is not `')'`, push it onto the stack.
   - If `c` is `')'`:
     - Pop characters from the stack until reaching `'('` and store them in a temporary string `temp` (popping automatically reverses the inner string order).
     - Pop the matching `'('`.
     - Push all characters from `temp` back onto the stack.
2. After processing all characters, construct the final string from the remaining characters in the stack.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N^2)$ in worst case (e.g. nested brackets like `((((a))))`), where $N = s.length \le 2000$. Given $N \le 2000$, $\mathcal{O}(N^2) \approx 4 \times 10^6$ operations, which executes in a few milliseconds.
- **Space Complexity:** $\mathcal{O}(N)$ to store characters in the stack and temporary buffers.
