# Euler intervals,binary lifting,rerooting and heavy paths: reasoning before code

A DFS entry order makes every rooted subtree one contiguous half-open interval. Entry/exit ranks answer ancestor queries and let earlier range structures handle subtree updates. Binary lifting stores2^j-th ancestors;doubling composes two half jumps. LCA lifts depth differences,then raises both nodes without crossing their first common ancestor.

Rerooting derives how a whole-tree answer changes when moving across one edge;do not recompute all source traversals unless using a small oracle. Heavy-light chooses a largest child and visits it first. Every light edge crosses into a subtree at most half the former size,so a path uses logarithmically many chains. Node-valued and edge-valued path sums differ at the LCA:an edge belongs to its deeper endpoint,and the LCA incoming edge is excluded.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

Rooted constructors require a nonempty connected undirected tree and root0 unless a source explicitly states otherwise. A root0 requires vertex0 to exist. Arbitrary cyclic/disconnected graphs are outside these tree contracts;use graph traversal components instead.

