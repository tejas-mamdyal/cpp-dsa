# Binary search and answer feasibility: understand the state

Binary search is a proof about a partitioned domain. For minimum feasible capacity, define F(x), prove false-then-true monotonicity, and choose bounds containing the answer. With low<high, use lower-mid; true sets high=mid, false sets low=mid+1. For maximum feasible distance, use upper-mid and last-true updates so two remaining candidates cannot stall.

The predicate needs its own proof. Greedy ordered packing finishes each group at least as far as any feasible packing, so it uses the fewest groups for a capacity. Reject tasks exceeding capacity inside the helper. Exactly k nonempty groups additionally requires k<=n; nonnegative groups can be subdivided without increasing maximum load.

Rates use integer ceilings; bouquets require consecutive runs rather than a global count. Real searches approximate a boundary with fixed iterations and tolerance; floating equality is not an exact certificate. Rotated and peak searches use structural invariants rather than capacity monotonicity. Duplicates may erase directional evidence and produce linear worst-case search.

Core:01-07,09,11,12. Reinforcement:10,14. Challenge:08,13. Read 01/02 before 03,07,14 and 09 before 10/11. Median partitions search the shorter array; cross-boundary ordering plus balanced sizes identifies the median. Empty halves use long long sentinels beyond the bounded int domain.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

