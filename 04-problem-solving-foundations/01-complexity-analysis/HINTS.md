# Staged hints

Attempt and hand trace before opening a hint.

## 1. Three sequential scans

First: identify the loop boundary/state and smallest input.

Next: Add5+5+5; fixed factors do not change the growth class.

Check: 15 selected visits; Theta(n+1). Explain the general case instead of stopping at the sample.

## 2. Unequal dimensions

First: identify the loop boundary/state and smallest input.

Next: Keep n and m independent; the outer loop still runs for m=0.

Check: n=3,m=4 gives12; n=3,m=0 gives0 inner visits. Explain the general case instead of stopping at the sample.

## 3. Inclusive triangular loop

First: identify the loop boundary/state and smallest input.

Next: Each row now includes its diagonal position.

Check: n=4 gives10; formula n*(n+1)/2. Explain the general case instead of stopping at the sample.

## 4. Two stopping conditions

First: identify the loop boundary/state and smallest input.

Next: Trace the integer values; do not round a floating logarithm.

Check: 13 gives4 versus3;16 gives5 versus4. Explain the general case instead of stopping at the sample.

## 5. Safe powers

First: identify the loop boundary/state and smallest input.

Next: Use a sufficiently wide type or guard multiplication before updating.

Check: n=28 visits1,3,9,27:4. Explain the general case instead of stopping at the sample.

## 6. Shared inner progress

First: identify the loop boundary/state and smallest input.

Next: An inner loop can finish all its progress during the first outer iteration.

Check: n=8 gives3 halving updates; total work Theta(n+log(n+1)+1). Explain the general case instead of stopping at the sample.

## 7. Search workload

First: identify the loop boundary/state and smallest input.

Next: Condition on success and failure before averaging.

Check: n=4:0.5*2.5+0.5*4=3.25. Explain the general case instead of stopping at the sample.

## 8. Memory ledger

First: identify the loop boundary/state and smallest input.

Next: Count simultaneously live allocations and state whether output is excluded from auxiliary space.

Check: copy retains O(n) elements; the view adds only a handle. Explain the general case instead of stopping at the sample.

## 9. Minimum invariant

First: identify the loop boundary/state and smallest input.

Next: Initialize from a real first element; test empty before accessing it.

Check: [-3,-8,2] ->-8; empty reports absence. Explain the general case instead of stopping at the sample.

## 10. Growth by one

First: identify the loop boundary/state and smallest input.

Next: Each growth copies every previous element, so sum an arithmetic progression.

Check: n=5 moves0+1+2+3+4=10; Theta(n*n). Explain the general case instead of stopping at the sample.

## 11. Budget filtering

First: identify the loop boundary/state and smallest input.

Next: Compute the logarithmic level count with integer bounds; these are modeled operations, not seconds.

Check: 100000 and1700000 fit;10000000000 does not. Explain the general case instead of stopping at the sample.

## 12. Oracle variation

First: identify the loop boundary/state and smallest input.

Next: Use different strategies and compare both absence and the returned value, not just a success boolean.

Check: 1+3+9+27+81=121 vectors. Explain the general case instead of stopping at the sample.


