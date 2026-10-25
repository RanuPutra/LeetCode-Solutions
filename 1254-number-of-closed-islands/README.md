# 1254. Number of Closed Islands

**Difficulty:** Medium  
**Topics:** Array, Depth-First Search, Breadth-First Search, Matrix, Union Find  
**LeetCode Link:** [1254. Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)

---

## Problem Description

Given a 2D `grid` consists of `0`s (land) and `1`s (water). An island is a maximal 4-directionally connected group of `0`s and a **closed island** is an island totally (all left, top, right, bottom) surrounded by `1`s.

Return the number of *closed islands*.

---

## Examples

### Example 1:

![Example 1](https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png)

**Input:** `grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]`  
**Output:** `2`  
**Explanation:**  
Islands in gray are closed because they are completely surrounded by water (group of 1s).

---

### Example 2:

![Example 2](https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png)

**Input:** `grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]`  
**Output:** `1`

---

### Example 3:

**Input:** `grid = [[1,1,1,1,1,1,1],[1,0,0,0,0,0,1],[1,0,1,1,1,0,1],[1,0,1,0,1,0,1],[1,0,1,1,1,0,1],[1,0,0,0,0,0,1],[1,1,1,1,1,1,1]]`  
**Output:** `2`

---

## Constraints

- $1 \le \text{grid.length}, \text{grid}[0]\text{.length} \le 100$
- $0 \le \text{grid}[i][j] \le 1$

---

## Solution Approach

### Boundary Flood Fill + Connected Component Counting:
1. **Understanding Closed Islands:**
   - A piece of land (`0`) is part of a closed island if none of its connected cells touch the boundary of the grid ($r = 0$, $r = m-1$, $c = 0$, or $c = n-1$).
   - Any island touching the boundary can never be surrounded by water on all four sides.
2. **Phase 1: Eliminate Boundary-Connected Lands:**
   - Iterate along all four boundaries of the matrix.
   - Whenever a land cell (`0`) is found on the boundary, perform Depth-First Search (DFS) / Breadth-First Search (BFS) to mark and convert all reachable land cells to water (`1`).
3. **Phase 2: Count Remaining Inner Islands:**
   - Traverse the inner cells of the grid ($1 \le r < m - 1$ and $1 \le c < n - 1$).
   - Whenever an unvisited land cell (`0`) is encountered, it is guaranteed to belong to a completely enclosed island.
   - Increment the answer counter and run DFS/BFS to mark the entire component as visited (`1`).

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(m \times n)$, where $m$ and $n$ are the number of rows and columns of `grid`. Every cell is visited a constant number of times.
- **Space Complexity:** $\mathcal{O}(m \times n)$ in the worst case due to the recursion call stack during DFS.
