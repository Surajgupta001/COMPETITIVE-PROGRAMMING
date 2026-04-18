# Grid Construction with Counting and Parity

> A deep dive into **geometry → counting → algebra → factorization**

This README explains how to solve a grid construction problem by converting geometric constraints into algebraic equations. The goal is to understand **why** the formulas work, not just memorize them.

---

## Problem Statement

**Given:**

- $p$ unit-length segments
- $q$ L-shaped pieces (each formed by two unit segments joined at a right angle)

**Goal:** Determine if we can use **all** pieces to construct an $n \times m$ grid (for some positive integers $n, m$).

- If yes: output any valid pair $(n, m)$
- If no: output $-1$

---

## The Key Insight: What Are We Counting?

The solution hinges on **correctly identifying what to count**. There are two distinct interpretations:

### Interpretation 1: All Unit Segments in the Grid Drawing

If we draw a full $n \times m$ grid and count **every unit segment** (all edges in the drawing):

$$m(n+1) + n(m+1) = 2nm + n + m$$

**Breakdown:**

- $(n+1)$ horizontal lines, each with $m$ segments → $m(n+1)$
- $(m+1)$ vertical lines, each with $n$ segments → $n(m+1)$

_Example: For a $2 \times 3$ grid, we have $3 \times 2 + 2 \times 4 = 6 + 8 = 14$ segments._

### Interpretation 2: Internal Shared Edges Between Cells

If we count **only the internal edges** connecting adjacent cells:

$$n(m-1) + m(n-1) = 2nm - n - m$$

**Breakdown:**

- $n$ rows, each with $(m-1)$ horizontal connections → $n(m-1)$
- $m$ columns, each with $(n-1)$ vertical connections → $m(n-1)$

_Example: For a $2 \times 3$ grid, we have $2 \times 2 + 3 \times 1 = 4 + 3 = 7$ internal edges._

### Why These Signs Differ

| Aspect                         | Full Grid | Internal Only |
| ------------------------------ | --------- | ------------- |
| **Includes outer boundaries?** | ✓ Yes     | ✗ No          |
| **More segments?**             | ✓ Yes     | ✗ No          |
| **Formula sign**               | $+n+m$    | $-n-m$        |
| **Count for $2 \times 3$**     | $14$      | $7$           |

**The sign difference depends entirely on what you're counting!**

---

## Available Segment Count

Each L-shaped piece consists of exactly **2 unit segments** joined at a right angle.

**Total available segments:**
$$S = p + 2q$$

This total must match the required grid quantity from either Interpretation 1 or 2.

---

## Mathematical Solutions

Let $S = p + 2q$ (total available segments). We need to determine which interpretation applies, then factor.

### Case 1: Full Grid Drawing

**Setup:**
$$S = 2nm + n + m$$

**Rearrange to product form:**
$$(2n+1)(2m+1) = 2S + 1$$

**Algorithm:**

1. Compute $T = 2S + 1$
2. Find all factor pairs $(a, b)$ where $a \cdot b = T$ and both are odd
3. For each pair, recover: $n = \frac{a-1}{2}$, $m = \frac{b-1}{2}$
4. If any valid factors exist, output $(n, m)$; otherwise output $-1$

---

### Case 2: Internal Adjacencies Only

**Setup:**
$$S = 2nm - n - m$$

**Rearrange to product form:**
$$(2n-1)(2m-1) = 2S + 1$$

**Algorithm:**

1. Compute $T = 2S + 1$
2. Find all factor pairs $(a, b)$ where $a \cdot b = T$ and both are odd
3. For each pair, recover: $n = \frac{a+1}{2}$, $m = \frac{b+1}{2}$
4. If any valid factors exist, output $(n, m)$; otherwise output $-1$

**Key Observation:** Both cases produce the **same odd number** $T = 2S + 1$, but the recovery formulas differ!

---

## Core Pattern

This problem follows a classic competitive programming pattern:

1. **Convert** the geometry into a counting equation.
2. **Rearrange** the equation into a product form.
3. **Check** whether the required number has a suitable odd factorization.
4. **Recover** $n$ and $m$ from those factors.
5. **Validate** if no valid factorization exists, return $-1$.

**Key Insight:** The real trick is **not construction itself** — it's turning a geometry problem into algebra.

---

## Why Factorization Works

The equations are **bilinear** in $n$ and $m$. Adding or subtracting a constant transforms them into product form:

$$2nm + n + m = \frac{(2n+1)(2m+1) - 1}{2}$$

$$2nm - n - m = \frac{(2n-1)(2m-1) - 1}{2}$$

This algebraic identity is why factorization appears naturally in the solution!

---

## ⚠️ Critical Distinction

A common mistake is mixing these two interpretations:

|                 | Full Grid              | Internal Only                  |
| --------------- | ---------------------- | ------------------------------ |
| **Counts**      | All edges in drawing   | Only connections between cells |
| **Formula**     | $2nm + n + m$          | $2nm - n - m$                  |
| **Factor form** | $(2n+1)(2m+1) = 2S+1$  | $(2n-1)(2m-1) = 2S+1$          |
| **Recovery**    | $n=(a-1)/2, m=(b-1)/2$ | $n=(a+1)/2, m=(b+1)/2$         |

**Always confirm which interpretation applies before solving!**

---

## Complete Solution Template

### Decision Tree

```
Input: p segments, q L-shaped pieces (2 segments each)
Compute: S = p + 2q
Compute: T = 2S + 1

Step 1: Determine problem type
   ├─ All grid segments? → Use Case 1 formulas
   └─ Internal adjacencies only? → Use Case 2 formulas

Step 2: Factor T
   └─ Find all odd divisors: (a, b) where a·b = T

Step 3: Recover dimensions
   ├─ Case 1: n = (a-1)/2, m = (b-1)/2
   └─ Case 2: n = (a+1)/2, m = (b+1)/2

Step 4: Validate and output
   ├─ If n > 0 and m > 0 → Output (n, m)
   └─ Otherwise → Output -1
```

---

## The Complete Thought Flow

$$\boxed{\text{Geometry}} \xrightarrow{\text{count}} \boxed{\text{Equation}} \xrightarrow{\text{algebra}} \boxed{\text{Product Form}} \xrightarrow{\text{factor}} \boxed{\text{Solution}}$$

---

## Key Takeaways

✓ **Understand what you're counting** — Full grid or internal edges?  
✓ **Translate to algebra** — Get an equation in $n$ and $m$  
✓ **Rearrange as a product** — $(2n±1)(2m±1) = 2S + 1$  
✓ **Factor the odd number** — Find all factor pairs  
✓ **Recover $n$ and $m$** — Use the appropriate recovery formula  
✓ **Validate and output** — Check if $n, m > 0$; else return $-1$

---

## Practice Tips

- **Verify your interpretation** by working through a small example (e.g., $n=2, m=3$)
- **Test both formulas** if the first doesn't yield valid factors
- **Factor efficiently** by iterating only up to $\sqrt{T}$
- **Handle edge cases** like $T=1$ (no valid factors) or composite $T$ with limited factors
- **Double-check recovery** — make sure $n, m$ are positive integers

---

## Implementation Checklist

- [ ] Parse input $p$ and $q$
- [ ] Compute $S = p + 2q$
- [ ] Compute $T = 2S + 1$
- [ ] Find all odd factor pairs of $T$
- [ ] For each pair $(a, b)$:
  - [ ] Compute candidate $n$ and $m$ using the correct formula
  - [ ] Verify $n > 0$ and $m > 0$
  - [ ] If valid, output and exit
- [ ] If no valid pair found, output $-1$
