# 1096. Brace Expansion II

**Difficulty:** Hard  
**Topics:** String, Backtracking, Stack, Breadth-First Search  
**LeetCode Link:** [1096. Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/)

---

## Problem Description

Under the grammar given below, strings can represent a set of lowercase words. Let $R(\text{expr})$ denote the set of words the expression represents.

The grammar can best be understood through simple examples:
- **Single letters** represent a singleton set containing that word:
  - $R(\text{"a"}) = \{\text{"a"}\}$
  - $R(\text{"w"}) = \{\text{"w"}\}$
- **Comma-delimited lists** represent the union of possibilities:
  - $R(\text{"\{a,b,c\}"}) = \{\text{"a","b","c"}\}$
  - $R(\text{"\{\{a,b\},\{b,c\}\}"}) = \{\text{"a","b","c"}\}$
- **Concatenation of expressions** represents the Cartesian product of possible concatenations:
  - $R(\text{"\{a,b\}\{c,d\}"}) = \{\text{"ac","ad","bc","bd"}\}$
  - $R(\text{"a\{b,c\}\{d,e\}f\{g,h\}"}) = \{\text{"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}\}$

Formally, the three rules of the grammar are:
1. For every lowercase letter $x$, $R(x) = \{x\}$.
2. For expressions $e_1, e_2, \dots, e_k$ with $k \ge 2$, $R(\{e_1, e_2, \dots\}) = R(e_1) \cup R(e_2) \cup \dots$
3. For expressions $e_1$ and $e_2$, $R(e_1 + e_2) = \{a + b \text{ for } (a, b) \in R(e_1) \times R(e_2)\}$, where $+$ denotes string concatenation.

Given an expression representing a set of words, return the **sorted list of unique words** that the expression represents.

---

## Examples

### Example 1:

**Input:** `expression = "{a,b}{c,{d,e}}"`  
**Output:** `["ac","ad","ae","bc","bd","be"]`

---

### Example 2:

**Input:** `expression = "{{a,z},a{b,c},{ab,z}}"`  
**Output:** `["a","ab","ac","z"]`  
**Explanation:** Each distinct word is written only once in sorted order.

---

## Constraints

- $1 \le \text{expression.length} \le 60$
- `expression[i]` consists of `'{'`, `'}'`, `','`, or lowercase English letters.
- The given expression represents a valid set of words under the grammar.

---

## Solution Approach

### Stack-Based Expression Evaluation (Shunting-Yard / Infix Parsing):

We can treat this grammar as an arithmetic expression where:
- `,` acts as an addition operator `+` (Set Union).
- Concatenation acts as a multiplication operator `*` (Cartesian Product).
- Operator precedence: Multiplication `*` (Concatenation) has higher precedence than Addition `+` (Union `,`).

### Parsing Steps:
1. **Operator Stack & Operand Stack:**
   - `operands` stack stores sets of strings (`set<string>`).
   - `ops` stack stores operators (`*`, `+`, `{`).
2. **Implicit Concatenation Detection:**
   - Insert an implicit multiplication operator `*` when an operand or `{` follows a letter or `}`.
3. **Operations:**
   - `multiply(set1, set2)`: Computes Cartesian product $S_1 \times S_2 = \{s_1 + s_2 \mid s_1 \in S_1, s_2 \in S_2\}$.
   - `unite(set1, set2)`: Computes set union $S_1 \cup S_2$.
4. **Result:**
   - Using `std::set` automatically removes duplicates and maintains lexicographical sorting.

---

## Complexity Analysis

- **Time Complexity:** $\mathcal{O}(2^M \cdot L)$, where $M$ is the number of nested sets and $L$ is the max word length. Given expression length $\le 60$, the set operations complete well within execution limits.
- **Space Complexity:** $\mathcal{O}(2^M \cdot L)$ to store unique intermediate sets in memory.
