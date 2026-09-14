# 836. Rectangle Overlap

**Difficulty:** Easy  
**Topics:** Math, Geometry  
**LeetCode Link:** [836. Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

---

## Problem Description

An axis-aligned rectangle is represented as a list `[x1, y1, x2, y2]`, where `(x1, y1)` is the coordinate of its bottom-left corner, and `(x2, y2)` is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two axis-aligned rectangles `rec1` and `rec2`, return `true` if they overlap, otherwise return `false`.

---

## Examples

### Example 1:

**Input:**
```text
rec1 = [0,0,2,2], rec2 = [1,1,3,3]
```

**Output:** `true`

---

### Example 2:

**Input:**
```text
rec1 = [0,0,1,1], rec2 = [1,0,2,1]
```

**Output:** `false`

---

### Example 3:

**Input:**
```text
rec1 = [0,0,1,1], rec2 = [2,2,3,3]
```

**Output:** `false`

---

## Constraints

- `rec1.length == 4`
- `rec2.length == 4`
- $-10^9 \le \text{rec1}[i], \text{rec2}[i] \le 10^9$
- `rec1` and `rec2` represent a valid rectangle with a non-zero area.

---

## Solution Approach

Instead of calculating the area of intersection directly, it is easier to check the conditions where two rectangles **do not** overlap:
1. `rec1` is completely to the **left** of `rec2`: `rec1[2] <= rec2[0]`
2. `rec1` is completely to the **right** of `rec2`: `rec1[0] >= rec2[2]`
3. `rec1` is completely **below** `rec2`: `rec1[3] <= rec2[1]`
4. `rec1` is completely **above** `rec2`: `rec1[1] >= rec2[3]`

If none of these separation conditions hold, then the rectangles **must overlap**.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — constant number of comparisons.
- **Space Complexity:** $\mathcal{O}(1)$ — auxiliary space used is constant.
