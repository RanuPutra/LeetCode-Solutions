# 3498. Reverse Degree of a String

**Difficulty:** Easy  
**Topics:** String, Math, Simulation  
**LeetCode Link:** [3498. Reverse Degree of a String](https://leetcode.com/problems/reverse-degree-of-a-string/)

---

## Problem Description

Given a string `s`, calculate its **reverse degree**.

The reverse degree is calculated as follows:
1. For each character in the string, multiply its position in the reversed alphabet (`'a'` = 26, `'b'` = 25, ..., `'z'` = 1) with its 1-indexed position in the string.
2. Sum these products for all characters in the string.

Return the reverse degree of `s`.

---

## Examples

### Example 1:

**Input:** `s = "abc"`  
**Output:** `148`  
**Explanation:**

| Letter | Index in Reversed Alphabet | Index in String (1-indexed) | Product |
| :---: | :---: | :---: | :---: |
| `'a'` | 26 | 1 | $26 \times 1 = 26$ |
| `'b'` | 25 | 2 | $25 \times 2 = 50$ |
| `'c'` | 24 | 3 | $24 \times 3 = 72$ |

Total reverse degree = $26 + 50 + 72 = 148$.

---

### Example 2:

**Input:** `s = "zaza"`  
**Output:** `160`  
**Explanation:**

| Letter | Index in Reversed Alphabet | Index in String (1-indexed) | Product |
| :---: | :---: | :---: | :---: |
| `'z'` | 1 | 1 | $1 \times 1 = 1$ |
| `'a'` | 26 | 2 | $26 \times 2 = 52$ |
| `'z'` | 1 | 3 | $1 \times 3 = 3$ |
| `'a'` | 26 | 4 | $26 \times 4 = 104$ |

Total reverse degree = $1 + 52 + 3 + 104 = 160$.

---

## Constraints

- $1 \le s.length \le 1000$
- `s` contains only lowercase English letters.

---

## Solution Approach

1. **Reversed Alphabet Position Calculation:**
   The position in the reversed alphabet for character `c` is given by:
   $$\text{reversedAlphabetPos} = 26 - (c - \text{'a'})$$

2. **String Position (1-indexed):**
   For 0-indexed loop index `i`, the string position is:
   $$\text{stringPos} = i + 1$$

3. **Accumulation:**
   Iterate through each character of `s`, compute $\text{reversedAlphabetPos} \times \text{stringPos}$, and accumulate the sum.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$, where $N = s.length$, iterating over the string once.
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space.
