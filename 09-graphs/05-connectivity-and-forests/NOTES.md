# Disjoint sets and minimum spanning forests: reasoning before code

DSU represents a partition,not graph routes. Union by size links the smaller root below the larger;the height grows only when component size at least doubles. Path compression redirects visited parent pointers to the root. Together they give amortized inverse-Ackermann operation cost;the uncompressed size-only bound is logarithmic.

Kruskal accepts the lightest edge connecting different components. Prim repeatedly accepts the lightest cut edge into its growing component. The cut exchange property proves both. A disconnected graph has a minimum spanning forest,not one spanning tree;report components explicitly or reject a requested MST. Negative edges,loops and parallel edges need defined handling. Offline deletion can be reversed into additions when the entire query batch is known.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

