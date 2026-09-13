# 835. Image Overlap

**Difficulty:** Medium  
**Topics:** Array, Matrix  
**LeetCode Link:** [835. Image Overlap](https://leetcode.com/problems/image-overlap/)

---

## Problem Description

You are given two images, `img1` and `img2`, represented as binary, square matrices of size `n x n`. A binary matrix has only `0`s and `1`s as values.

We translate one image however we choose by sliding all the `1` bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a `1` in both images.

Note also that a translation does not include any kind of rotation. Any `1` bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.

---

## Examples

### Example 1:

**Input:**
```text
img1 = [
  [1,1,0],
  [0,1,0],
  [0,1,0]
]

img2 = [
  [0,0,0],
  [0,1,1],
  [0,0,1]
]
```

**Output:** `3`

**Explanation:** We translate `img1` right by 1 unit and down by 1 unit. The number of positions that have a 1 in both images is 3.

---

### Example 2:

**Input:**
```text
img1 = [[1]], img2 = [[1]]
```

**Output:** `1`

---

### Example 3:

**Input:**
```text
img1 = [[0]], img2 = [[0]]
```

**Output:** `0`

---

## Constraints

- `n == img1.length == img1[i].length`
- `n == img2.length == img2[i].length`
- `1 <= n <= 30`
- `img1[i][j]` is either `0` or `1`.
- `img2[i][j]` is either `0` or `1`.

---

## Solution Approach

1. **Extract 1 Coordinates**: Collect all $(r, c)$ pair coordinates where `img1[r][c] == 1` and `img2[r][c] == 1`.
2. **Coordinate Difference (Shift Vector)**: For every pair $(p_1, p_2)$, calculate the shift vector: $\Delta r = r_2 - r_1$, $\Delta c = c_2 - c_1$.
3. **Shift Frequency Map**: Count occurrences of each $(\Delta r, \Delta c)$ shift.
4. **Result**: The shift vector with the maximum count represents the maximum overlap.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(V_1 \times V_2 + N^2)$, where $V_1, V_2 \le N^2$ are the counts of `1`s in `img1` and `img2`. Worst-case is $\mathcal{O}(N^4) \approx 8.1 \times 10^5$ operations for $N=30$.
- **Space Complexity:** $\mathcal{O}(N^2)$ to store coordinates and shift frequency grid.
