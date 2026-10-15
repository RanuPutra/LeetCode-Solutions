# 1306. Jump Game III

**Difficulty:** Medium  
**Topics:** Array, Depth-First Search, Breadth-First Search  
**LeetCode Link:** [1306. Jump Game III](https://leetcode.com/problems/jump-game-iii/)

---

## Problem Description

Given an array of non-negative integers `arr`, you are initially positioned at `start` index of the array. When you are at index `i`, you can jump to `i + arr[i]` or `i - arr[i]`, check if you can reach any index with value `0`.

Notice that you can not jump outside of the array at any time.

---

## Examples

### Example 1:

**Input:** `arr = [4,2,3,0,3,1,2], start = 5`  
**Output:** `true`  
**Explanation:**  
All possible ways to reach index 3 with value 0 are:
- `index 5 -> index 4 -> index 1 -> index 3`
- `index 5 -> index 6 -> index 4 -> index 1 -> index 3`

---

### Example 2:

**Input:** `arr = [4,2,3,0,3,1,2], start = 0`  
**Output:** `true`  
**Explanation:**  
One possible way to reach index 3 with value 0 is:
- `index 0 -> index 4 -> index 1 -> index 3`

---

### Example 3:

**Input:** `arr = [3,0,2,1,2], start = 2`  
**Output:** `false`  
**Explanation:**  
There is no way to reach index 1 with value 0.

---

## Constraints

- $1 \le \text{arr.length} \le 5 \times 10^4$
- $0 \le \text{arr}[i] < \text{arr.length}$
- $0 \le \text{start} < \text{arr.length}$

---

## Solution Approach

### Breadth-First Search (BFS):
The problem can be modeled as finding whether a target node (`arr[i] == 0`) is reachable from node `start` in a directed graph where each index $i$ has edges to $i + \text{arr}[i]$ and $i - \text{arr}[i]$ (provided they fall within array bounds $[0, n - 1]$).

1. **Queue & Visited Array:**
   - Maintain a `queue<int> q` for BFS traversal and a boolean array `visited` of size $n$ to avoid infinite loops caused by cycles.
2. **Traversal:**
   - Push `start` into `q` and mark `visited[start] = true`.
   - While `q` is not empty:
     - Pop current index `curr`.
     - If `arr[curr] == 0`, return `true`.
     - Check forward jump `curr + arr[curr]`: if within bounds and not visited, mark visited and push to `q`.
     - Check backward jump `curr - arr[curr]`: if within bounds and not visited, mark visited and push to `q`.
3. If the queue is exhausted without finding a 0, return `false`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = \text{arr.length}$. Each index is visited at most once.
- **Space Complexity:** $\mathcal{O}(N)$ for the `visited` array and queue.
