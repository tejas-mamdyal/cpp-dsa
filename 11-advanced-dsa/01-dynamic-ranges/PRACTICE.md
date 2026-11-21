# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Preserve value ordering while compressing sparse coordinates. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include duplicate negative coordinates and invert every assigned rank.

## 2. Exercise 2

Update and query additive lowbit blocks. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Initialize from a nonzero array,then perform alternating signed updates.

## 3. Exercise 3

Subtract two prefix aggregates to answer a range. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Specify empty-range behavior and compare every interval to a direct scan.

## 4. Exercise 4

Store a difference array inside Fenwick blocks. Domain:Initially zero array, length<=30; valid half-open updates and point indices. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return a concrete kth occurrence and reject ranks outside the total count.

## 5. Exercise 5

Use weighted difference prefixes to sum updated values. Domain:Initially zero length<=30 array; half-open range adds and sum queries. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return the actual inversion pairs on a tiny input as an oracle.

## 6. Exercise 6

Search Fenwick blocks for the kth counted item. Domain:Nonnegative count array<=30; rank 1-based; out-of-range rank returns absence. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Preserve original values after point assignment and test all-negative data.

## 7. Exercise 7

Query smaller suffix ranks before inserting the current value. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Add a witness interval to the maximum-subarray answer.

## 8. Exercise 8

Combine disjoint interval sums in an iterative tree. Domain:Array length<=30; valid point assignments and half-open sum queries, including empty. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compose nested updates whose total cancels to zero.

## 9. Exercise 9

Use infinity as the identity for a minimum summary. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Assign zero after a nonzero assignment to a strict subrange.

## 10. Exercise 10

Store enough boundary information to combine adjacent optima. Domain:Nonempty queried half-open interval in a bounded signed array; empty query returns absence. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Reject querying a nonempty range of an empty structure.

## 11. Exercise 11

Defer child updates while keeping parent sums current. Domain:Initially zero array, n 0..30; half-open signed range additions and sums. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare every range to a direct minimum scan.

## 12. Exercise 12

A pending assignment needs a presence flag distinct from its value. Domain:Initially zero array, n 0..30; valid half-open assignments and sum queries. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare every range to a direct gcd scan.

