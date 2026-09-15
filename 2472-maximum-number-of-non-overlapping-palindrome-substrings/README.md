# 2472. Maximum Number of Non-overlapping Palindrome Substrings

**Difficulty:** Hard  
**Topics:** String, Dynamic Programming, Greedy, Two Pointers  
**LeetCode Link:** [2472. Maximum Number of Non-overlapping Palindrome Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

---

## Problem Description

You are given a string `s` and a positive integer `k`.

Select a set of non-overlapping substrings from the string `s` that satisfy the following conditions:
1. The length of each substring is at least `k`.
2. Each substring is a palindrome.

Return the *maximum number of substrings* in an optimal selection.

A **substring** is a contiguous sequence of characters within a string.

---

## Examples

### Example 1:

**Input:** `s = "abaccdbbd", k = 3`  
**Output:** `2`  
**Explanation:** We can select the substrings `s[0..2] = "aba"` and `s[5..8] = "dbbd"`. Both are palindromes and have length $\ge 3$. We cannot find a selection with more than two valid substrings.

---

### Example 2:

**Input:** `s = "adbcda", k = 2`  
**Output:** `0`  
**Explanation:** There is no palindrome substring of length at least 2 in the string.

---

## Constraints

- $1 \le k \le s.length \le 2000$
- `s` consists of lowercase English letters.

---

## Solution Approach

### Key Insight:
Any palindrome of length $\ge k$ contains a smaller palindrome of length either $k$ or $k + 1$ at its center:
- If a palindrome has length $L \ge k$, we can trim equal numbers of characters from both ends to obtain a palindrome of length $k$ (if $L$ and $k$ have the same parity) or $k + 1$ (if they have different parity).
- Therefore, we only ever need to search for valid palindromes of length **exactly $k$** or **exactly $k + 1$**.

### Dynamic Programming Formulation:
Let `dp[i]` be the maximum number of non-overlapping palindrome substrings of length $\ge k$ formed using a prefix of length `i` (i.e. `s[0...i-1]`).

For each position `i` from $1$ to $N$:
1. **Option 1 (Skip):** `dp[i] = dp[i - 1]`
2. **Option 2 (Palindrome of length $k$):** If `i >= k` and `s[i-k ... i-1]` is a palindrome, then `dp[i] = max(dp[i], dp[i - k] + 1)`.
3. **Option 3 (Palindrome of length $k+1$):** If `i >= k + 1` and `s[i-k-1 ... i-1]` is a palindrome, then `dp[i] = max(dp[i], dp[i - k - 1] + 1)`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N \cdot k)$, where $N = s.length$. For each index $i$, checking palindromes of lengths $k$ and $k+1$ takes $\mathcal{O}(k)$ time. Given $N \le 2000$, total operations are at most $\sim 4 \times 10^6$, which easily passes in C++.
- **Space Complexity:** $\mathcal{O}(N)$ for the `dp` array.
