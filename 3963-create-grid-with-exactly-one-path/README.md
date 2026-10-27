# 3963. Create Grid With Exactly One Path

**Difficulty:** Easy  
**Topics:** Array, Matrix  
**LeetCode Link:** [3963. Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/)

---

## Problem Description

You are given two integers `m` and `n`, representing the number of rows and columns of a grid.

Construct any `m x n` grid consisting only of the characters `.` and `#`, where:
- `.` represents a free cell.
- `#` represents an obstacle cell.

A valid path is a sequence of free cells that:
- Starts at the top-left cell `(0, 0)`.
- Ends at the bottom-right cell `(m - 1, n - 1)`.
- Moves only:
  - **Right**, from `(i, j)` to `(i, j + 1)`, or
  - **Down**, from `(i, j)` to `(i + 1, j)`.

Return **any** grid such that there is **exactly one** valid path from the top-left cell to the bottom-right cell.

---

## Examples

### Example 1:

**Input:** `m = 2, n = 3`  
**Output:** `["..#","#.."]`  
**Explanation:**  
The only valid path is: `(0,0) → (0,1) → (1,1) → (1,2)`

---

### Example 2:

**Input:** `m = 3, n = 3`  
**Output:** `["..#","#..","##."]`  
**Explanation:**  
The only valid path is: `(0,0) → (0,1) → (1,1) → (1,2) → (2,2)`

---

### Example 3:

**Input:** `m = 1, n = 4`  
**Output:** `["...."]`  
**Explanation:**  
The only valid path is: `(0,0) → (0,1) → (0,2) → (0,3)`

---

## Constraints

- $1 \le m, n \le 25$

---

## Solution Approach

### Constructive Algorithm (L-Shaped Path):
1. **Initialize Obstacles:**
   - Initialize the entire grid of size $m \times n$ filled with obstacle cells `'#'`.
2. **Carve a Unique Path:**
   - Set all cells in the **first row** ($i = 0, j \in [0, n - 1]$) to free cells `'.'`.
   - Set all cells in the **last column** ($i \in [0, m - 1], j = n - 1$) to free cells `'.'`.
3. **Uniqueness:**
   - Any path from $(0, 0)$ must travel all the way right along row $0$ because all downward cells $(i, j)$ with $i > 0, j < n - 1$ are blocked (`'#'`).
   - Once at $(0, n - 1)$, the path cannot move right (it is at the boundary), so it must travel straight down column $n - 1$ to $(m - 1, n - 1)$.
   - There are zero branching options at every step, guaranteeing **exactly one valid path**.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \times n)$ to construct the grid strings.
- **Space Complexity:** $\mathcal{O}(m \times n)$ auxiliary space to store and return the grid.
