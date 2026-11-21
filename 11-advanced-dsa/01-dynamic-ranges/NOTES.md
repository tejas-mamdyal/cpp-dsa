# Coordinate compression,Fenwick and segment summaries: reasoning before code

Order-preserving compression replaces values by ranks,not by their physical distances. Fenwick stores additive prefix blocks ending at each1-based index;unsigned lowbit identifies block length. Point changes and prefix differences require additive invertibility. Difference arrays turn range additions into point updates;two weighted difference trees support range sums.

Segment trees combine disjoint intervals with an associative summary. Choose the identity and empty-range policy explicitly. Lazy propagation records operations already reflected in a node aggregate but not yet applied to children. Additive tags accumulate;assignment tags override and need a separate presence marker so assigning0 remains meaningful. Sparse tables answer overlapping-block queries only for idempotent operations such as min or gcd.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

