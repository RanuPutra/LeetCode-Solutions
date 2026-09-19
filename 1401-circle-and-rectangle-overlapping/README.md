# 1401. Circle and Rectangle Overlapping

**Difficulty:** Medium  
**Topics:** Math, Geometry  
**LeetCode Link:** [1401. Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

---

## Problem Description

You are given a circle represented as `(radius, xCenter, yCenter)` and an axis-aligned rectangle represented as `(x1, y1, x2, y2)`, where `(x1, y1)` are the coordinates of the bottom-left corner, and `(x2, y2)` are the coordinates of the top-right corner of the rectangle.

Return `true` if the circle and rectangle overlap, otherwise return `false`. In other words, check if there is any point `(xi, yi)` that belongs to both the circle and the rectangle at the same time.

---

## Examples

### Example 1:

**Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1`  
**Output:** `true`  
**Explanation:** Circle and rectangle share the point `(1,0)`.

---

### Example 2:

**Input:** `radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1`  
**Output:** `false`

---

### Example 3:

**Input:** `radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1`  
**Output:** `true`

---

## Constraints

- $1 \le \text{radius} \le 2000$
- $-10^4 \le \text{xCenter}, \text{yCenter} \le 10^4$
- $-10^4 \le x_1 < x_2 \le 10^4$
- $-10^4 \le y_1 < y_2 \le 10^4$

---

## Solution Approach

### Nearest Point Projection:

1. **Find Nearest Point on Rectangle:**
   To check if a circle and a rectangle intersect, find the point $(x_{\text{closest}}, y_{\text{closest}})$ inside or on the boundary of the rectangle that is closest to the circle's center $(x_{\text{center}}, y_{\text{center}})$:
   $$x_{\text{closest}} = \max(x_1, \min(x_{\text{center}}, x_2))$$
   $$y_{\text{closest}} = \max(y_1, \min(y_{\text{center}}, y_2))$$

2. **Distance Comparison:**
   Calculate the Euclidean distance between $(x_{\text{center}}, y_{\text{center}})$ and $(x_{\text{closest}}, y_{\text{closest}})$.
   To avoid floating point calculations, compare the squared distance with the squared radius:
   $$(x_{\text{center}} - x_{\text{closest}})^2 + (y_{\text{center}} - y_{\text{closest}})^2 \le \text{radius}^2$$

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(1)$ — constant arithmetic operations.
- **Space Complexity:** $\mathcal{O}(1)$ — auxiliary space used is constant.
