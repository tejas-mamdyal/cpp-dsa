# Staged hints

Use the first hint after an independent attempt;read the second only after recording a trace and a specific difficulty.

## 1. Exercise 1

1. sorted holds distinct values; rank[i] identifies original a[i] in that order.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 2. Exercise 2

1. bit[i] stores the sum of the 1-based block(i-lowbit(i), i]; updates visit enclosing blocks, prefix query removes disjoint ending blocks.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 3. Exercise 3

1. range[left, right) equals prefix(right)-prefix(left), including empty intervals.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 4. Exercise 4

1. Difference[left]+=v and difference[right]-=v represent a half-open range update; prefix integrates to a point value.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 5. Exercise 5

1. A difference entry d[i] contributes(end-i)*d[i] to a length-end prefix, so store both d[i] and i*d[i].
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 6. Exercise 6

1. index is the longest accepted prefix whose frequency sum is below rank; try descending powers of two using stored Fenwick blocks.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 7. Exercise 7

1. Fenwick counts ranks strictly to the current position right; prefix(rank) counts smaller values, excluding equals.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 8. Exercise 8

1. Leaves hold values at a power-of-two base; each parent sums its two children; query consumes disjoint boundary blocks.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 9. Exercise 9

1. Every node stores its interval minimum; unused padded leaves use an identity larger than any candidate.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 10. Exercise 10

1. A range summary stores total sum, best nonempty prefix, suffix, and internal subarray; combining two ranges needs the crossing suffix+prefix option.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 11. Exercise 11

1. sum[p] already includes all updates covering its interval; lazy[p] is pending additive work for its children.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 12. Exercise 12

1. An optional assignment tag overrides all earlier assignments for its segment; engaged 0 means a real zero assignment, not no pending work.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

