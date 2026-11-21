# Independent complexity practice

Write solutions without opening the worked source. State the counted operation,
size/domain bounds, correctness argument and input/output/working memory. Code
exercises use bounded ints; never execute an enormous predicted quadratic workload.

## 1. Three sequential scans

For n=5 count three complete scans, then express the total for general n.

Example/result: 15 selected visits; Theta(n+1).

## 2. Unequal dimensions

Count inner visits and total control work for n rows,m columns, including m=0.

Example/result: n=3,m=4 gives12; n=3,m=0 gives0 inner visits.

## 3. Inclusive triangular loop

Count pairs with i<=j rather than i<j for n indices.

Example/result: n=4 gives10; formula n*(n+1)/2.

## 4. Two stopping conditions

Compare repeated halving with >0 versus >1 for n=0,1,13,16.

Example/result: 13 gives4 versus3;16 gives5 versus4.

## 5. Safe powers

Count powers of3 not exceeding n for n in0..1000000000 without integer overflow.

Example/result: n=28 visits1,3,9,27:4.

## 6. Shared inner progress

Move remaining=n outside the n-iteration loop and never reset it. Derive total updates and total work.

Example/result: n=8 gives3 halving updates; total work Theta(n+log(n+1)+1).

## 7. Search workload

Compute expected comparisons when successful positions are uniform and miss probability is one half.

Example/result: n=4:0.5*2.5+0.5*4=3.25.

## 8. Memory ledger

Compare a returned copy, a by-value parameter, a const-reference view and an in-place update.

Example/result: copy retains O(n) elements; the view adds only a handle.

## 9. Minimum invariant

Write a minimum helper with an explicit empty policy and an initialization/maintenance/termination argument.

Example/result: [-3,-8,2] ->-8; empty reports absence.

## 10. Growth by one

Model a dynamic array whose capacity grows by1 rather than doubling. Count moves for n pushes.

Example/result: n=5 moves0+1+2+3+4=10; Theta(n*n).

## 11. Budget filtering

Given n=100000 and budget10000000 compare modeled n,n*ceil(log2(n)),n*n counts.

Example/result: 100000 and1700000 fit;10000000000 does not.

## 12. Oracle variation

Implement slow/fast first-repeat detection, define what first means, and exhaust lengths0..4 over0,1,2.

Example/result: 1+3+9+27+81=121 vectors.


