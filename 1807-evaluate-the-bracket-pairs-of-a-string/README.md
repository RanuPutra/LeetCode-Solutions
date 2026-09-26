# 1807. Evaluate the Bracket Pairs of a String

**Difficulty:** Medium  
**Topics:** Array, Hash Table, String  
**LeetCode Link:** [1807. Evaluate the Bracket Pairs of a String](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)

---

## Problem Description

You are given a string `s` that contains some bracket pairs, with each pair containing a non-empty key.

For example, in the string `"(name)is(age)yearsold"`, there are two bracket pairs that contain the keys `"name"` and `"age"`.

You know the values of a wide range of keys. This is represented by a 2D string array `knowledge` where each `knowledge[i] = [key_i, value_i]` indicates that key `key_i` has a value of `value_i`.

You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair containing some key `key_i`, you will:
- Replace `key_i` and the bracket pair with the key's corresponding `value_i`.
- If you do not know the value of the key, replace `key_i` and the bracket pair with a question mark `"?"`.

Each key will appear at most once in `knowledge`. There will not be any nested brackets in `s`.

Return the resulting string after evaluating all of the bracket pairs.

---

## Examples

### Example 1:

**Input:** `s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]`  
**Output:** `"bobistwoyearsold"`  
**Explanation:**  
- The key `"name"` has a value of `"bob"`, so replace `"(name)"` with `"bob"`.
- The key `"age"` has a value of `"two"`, so replace `"(age)"` with `"two"`.

---

### Example 2:

**Input:** `s = "hi(name)", knowledge = [["a","b"]]`  
**Output:** `"hi?"`  
**Explanation:**  
As you do not know the value of the key `"name"`, replace `"(name)"` with `"?"`.

---

### Example 3:

**Input:** `s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]`  
**Output:** `"yesyesyesaaa"`  
**Explanation:**  
The key `"a"` has a value of `"yes"`, so replace all occurrences of `"(a)"` with `"yes"`. Notice that the `"a"`s not in a bracket pair are not evaluated.

---

## Constraints

- $1 \le s.length \le 10^5$
- $0 \le knowledge.length \le 10^5$
- $knowledge[i].length == 2$
- $1 \le key_i.length, value_i.length \le 10$
- `s` consists of lowercase English letters and round brackets `'('` and `')'`.
- Every open bracket `'('` in `s` has a corresponding close bracket `')'`.
- The key in each bracket pair of `s` is non-empty.
- There are no nested bracket pairs in `s`.
- $key_i$ and $value_i$ consist of lowercase English letters.
- Each $key_i$ in `knowledge` is unique.

---

## Solution Approach

1. **Hash Table Lookup:**
   Construct an `unordered_map<string, string>` from `knowledge` for $\mathcal{O}(1)$ average lookup time per key.

2. **Single-Pass Parsing:**
   Iterate character-by-character through `s` using a boolean flag `inside_bracket` and string `current_key`:
   - When encountering `'('`: set `inside_bracket = true` and reset `current_key = ""`.
   - When encountering `')'`: set `inside_bracket = false`, look up `current_key` in the hash map:
     - If found: append `dict[current_key]` to `result`.
     - If not found: append `'?'` to `result`.
   - Otherwise:
     - If `inside_bracket`: append character to `current_key`.
     - Else: append character directly to `result`.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N + K \cdot L)$, where $N = s.length$, $K = knowledge.length$, and $L$ is max key/value length. Building the hash map takes $\mathcal{O}(K \cdot L)$ time, and iterating through `s` takes $\mathcal{O}(N)$ time. Overall linear time.
- **Space Complexity:** $\mathcal{O}(K \cdot L + N)$ to store the hash map and output string.
