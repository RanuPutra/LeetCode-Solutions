# 1541. Minimum Insertions to Balance a Parentheses String

**Difficulty:** Medium  
**Topics:** String, Stack, Greedy  
**LeetCode Link:** [1541. Minimum Insertions to Balance a Parentheses String](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

---

## Problem Description

Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is balanced if:
1. Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
2. Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

For example, `"()"`, `"())(())))"` and `"(())())))"` are balanced; `")()"`, `"() implementation"` and `"(()))"` are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return the **minimum number of insertions** needed to make `s` balanced.

---

## Examples

### Example 1:

**Input:** `s = "(()))"`  
**Output:** `1`  
**Explanation:** The second `'('` has two matching `'))'`, but the first `'('` has only one `')'` matching. We need to add one more `')'` at the end of the string to form `"(())))"` which is balanced.

---

### Example 2:

**Input:** `s = "())"`  
**Output:** `0`  
**Explanation:** The string is already balanced.

---

### Example 3:

**Input:** `s = "))())("`  
**Output:** `3`  
**Explanation:** Add `'('` to match the first `'))'`, add `'))'` to match the last `'('`.

---

## Constraints

- $1 \le s.length \le 10^5$
- `s` consists of `'('` and `')'` only.

---

## Solution Approach

### Greedy Single-Pass Counter (`needed_closing`):
Each open parenthesis `'('` requires **two consecutive** closing parentheses `'))'`.

1. **State Variables:**
   - `ans`: Cumulative insertion operations required.
   - `needed_closing`: Number of `')'` needed to balance all open `'('` encountered.
2. **Character Processing:**
   - **Case `c == '('`:**
     - If `needed_closing` is odd (`needed_closing % 2 == 1`), it means a previous `'('` is waiting for a second `')'`. Before opening a new `'('`, insert one `')'` (`ans++`, `needed_closing--`).
     - Each new `'('` needs two `')'` $\to$ `needed_closing += 2`.
   - **Case `c == ')'`:**
     - Decrement `needed_closing--`.
     - If `needed_closing < 0` (unmatched closing bracket): insert one `'('` (`ans++`), which then requires one more `')'` $\to$ `needed_closing = 1`.
3. **Final Cleanup:**
   - Return `ans + needed_closing` (inserting any remaining `needed_closing` brackets at the end).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$. Single linear pass through the string.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
