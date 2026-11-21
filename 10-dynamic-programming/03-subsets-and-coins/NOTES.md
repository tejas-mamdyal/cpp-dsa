# Subset,knapsack and coin states: reasoning before code

Item position and remaining capacity form a state only after deciding whether each item is single-use or reusable. A0/1 table reads the previous item row;its compressed version scans capacity downward. Unbounded reuse scans upward so the current item can be used again. Initialization must distinguish exact fill from at-most capacity.

Boolean feasibility,counting and optimum value use different combination operations. Zero-valued items double subset counts without changing sum. Equal partition assumes nonnegative values in this indexed-sum implementation. Coin-first counting ignores sequence order;amount-first counting includes it. Reconstruction needs saved choices or the full table,not merely a final boolean.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

