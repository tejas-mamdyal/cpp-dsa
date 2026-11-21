# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Implement stable descending insertion sort.

Example/result: [2A,1B,2C] ->[2A,2C,1B].

## 2. Task

Give tagged records demonstrating selection instability.

Example/result: [2A,2B,1C] can become[1C,2B,2A].

## 3. Task

Explain one reusable merge buffer across recursion.

Example/result: disjoint half-open ranges.

## 4. Task

Construct a last-pivot quick-sort worst case.

Example/result: already sorted input.

## 5. Task

Build and extract a max heap by hand.

Example/result: [3,1,4,2],first maximum4.

## 6. Task

Explain the radix negative-key restriction.

Example/result: negative digit index is invalid.

## 7. Task

Stable-count records with keys[-2,2] and payload serials.

Example/result: equal keys retain arrival order.

## 8. Task

Compare merge inversion count with pair enumeration.

Example/result: [2,2,1] has2 inversions.


