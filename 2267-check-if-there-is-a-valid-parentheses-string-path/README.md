# 2267. Check if There Is a Valid Parentheses String Path

**Difficulty:** Hard  
**Topics:** Array, Dynamic Programming, Backtracking, Matrix, Breadth-First Search  
**LeetCode Link:** [2267. Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)

---

## Problem Description

A parentheses string is a non-empty string consisting only of `'('` and `')'`. It is valid if:
- It is `()`.
- It can be written as $AB$ (concatenation of valid parentheses strings $A$ and $B$).
- It can be written as $(A)$, where $A$ is a valid parentheses string.

You are given an $m \times n$ matrix `grid` of parentheses. A **valid parentheses string path** in the grid satisfies:
1. Starts from upper-left cell $(0, 0)$.
2. Ends at bottom-right cell $(m - 1, n - 1)$.
3. Only moves right or down.
4. The resulting string formed by the path is a valid parentheses string.

Return `true` if there exists a valid parentheses string path, otherwise return `false`.

---

## Examples

### Example 1:

**Input:** `grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]`  
**Output:** `true`  
**Explanation:** Possible valid paths include `"()(())"` and `"((()))"`.

---

### Example 2:

**Input:** `grid = [[")",")"],["(","("]]`  
**Output:** `false`  
**Explanation:** The two possible paths form `"))("` and `")(("`, neither of which is valid.

---

## Constraints

- $m == \text{grid.length}$
- $n == \text{grid}[i].length$
- $1 \le m, n \le 100$
- `grid[i][j]` is either `'('` or `')'`.

---

## Solution Approach

### BFS / DP State Space Exploration with Pruning:

1. **Early Pruning Conditions:**
   - Total path length from $(0, 0)$ to $(m-1, n-1)$ is $m + n - 1$. A valid parentheses string must have **even length**. If $(m + n - 1) \pmod 2 \neq 0$, return `false`.
   - The starting cell must be `'('` and the ending cell must be `')'`.

2. **State Representation:**
   Track states $(r, c, \text{bal})$, where:
   - $(r, c)$ is the current grid cell.
   - $\text{bal}$ is the prefix parentheses balance ($+1$ for `'('`, $-1$ for `')'`).
   - A path prefix is valid if $\text{bal} \ge 0$ at all steps and $\text{bal} \le \frac{m + n - 1}{2}$.

3. **3D Visited Matrix:**
   Use `visited[r][c][bal]` to avoid re-evaluating the same cell $(r, c)$ with identical balance.

4. **BFS Traversal:**
   Starting from $(0, 0, 1)$, expand right $(r, c+1)$ and down $(r+1, c)$. If cell $(m-1, n-1)$ is reached with $\text{bal} == 0$, return `true`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \cdot n \cdot (m + n))$, since there are at most $m \times n \times \frac{m+n}{2}$ unique states visited once. For $m, n \le 100$, operations total $\approx 100 \times 100 \times 100 = 10^6$, which easily runs under Time Limit.
- **Space Complexity:** $\mathcal{O}(m \cdot n \cdot (m + n))$ to store the 3D visited boolean array.
