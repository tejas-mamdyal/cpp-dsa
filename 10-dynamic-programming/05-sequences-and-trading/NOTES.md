# Ordered subsequences and transaction states: reasoning before code

A subsequence ending at position i is different from an optimum anywhere through i. LIS compares all smaller predecessors;counting additionally sums equal-optimum predecessor multiplicities. Reconstruct with predecessor indices. Tails compression stores the smallest ending value attainable for each length,not necessarily one actual output sequence.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

