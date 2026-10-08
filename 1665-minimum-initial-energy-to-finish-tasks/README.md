# 1665. Minimum Initial Energy to Finish Tasks

**Difficulty:** Hard  
**Topics:** Array, Greedy, Sorting  
**LeetCode Link:** [1665. Minimum Initial Energy to Finish Tasks](https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/)

---

## Problem Description

You are given an array `tasks` where `tasks[i] = [actual_i, minimum_i]`:
- `actual_i` is the actual amount of energy you spend to finish the $i$-th task.
- `minimum_i` is the minimum amount of energy you require to begin the $i$-th task.

For example, if the task is `[10, 12]` and your current energy is `11`, you cannot start this task. However, if your current energy is `13`, you can complete this task, and your energy will be `3` after finishing it.

You can finish the tasks in any order you like.

Return the **minimum initial amount of energy** you will need to finish all the tasks.

---

## Examples

### Example 1:

**Input:** `tasks = [[1,2],[2,4],[4,8]]`  
**Output:** `8`  
**Explanation:**  
Starting with 8 energy:
- Finish 3rd task `[4,8]`: energy becomes $8 - 4 = 4$.
- Finish 2nd task `[2,4]`: energy becomes $4 - 2 = 2$.
- Finish 1st task `[1,2]`: energy becomes $2 - 1 = 1$.

---

### Example 2:

**Input:** `tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]`  
**Output:** `32`  
**Explanation:**  
Starting with 32 energy, we finish tasks in order:
- 1st `[1,3]`: $32 - 1 = 31$
- 2nd `[2,4]`: $31 - 2 = 29$
- 3rd `[10,11]`: $29 - 10 = 19$
- 4th `[10,12]`: $19 - 10 = 9$
- 5th `[8,9]`: $9 - 8 = 1$

---

### Example 3:

**Input:** `tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]`  
**Output:** `27`

---

## Constraints

- $1 \le \text{tasks.length} \le 10^5$
- $\text{tasks}[i].length == 2$
- $1 \le \text{actual}_i \le \text{minimum}_i \le 10^4$

---

## Solution Approach

### Greedy Strategy (Sorting by Energy Saved):
To minimize the required starting energy, we should prioritize tasks that yield the largest difference between their minimum requirement and actual cost:
$$\text{saved}_i = \text{minimum}_i - \text{actual}_i$$

1. **Sort Tasks:**
   Sort `tasks` in **descending order** of $(\text{minimum}_i - \text{actual}_i)$. Tasks that leave the largest buffer of unused energy requirement should be completed first.
2. **Simulation:**
   - Track `res` (total initial energy required) and `cur` (current available energy).
   - For each task $(\text{actual}, \text{minimum})$:
     - If `cur < minimum`, increase `res` by $(\text{minimum} - \text{cur})$ and set `cur = minimum`.
     - Consume energy: `cur -= actual`.
3. Return `res`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \log N)$, where $N = \text{tasks.length}$, due to sorting the tasks array.
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(\log N)$ auxiliary space used by `std::sort`.
