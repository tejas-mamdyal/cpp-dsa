# Graph models and representations: reasoning before code

A vertex is an indexed object;an edge relates two objects. Decide direction,weights,loops and repeated-edge policy before selecting storage. An undirected loop contributes two incidences to degree. A boolean matrix collapses parallel edges,whereas adjacency lists can preserve them. A weighted adjacency entry stores destination and weight,not a distance already solved.

Use0..n-1 internal indices;map external labels explicitly. Validate dimensions and endpoints before indexing. Implicit grids and product states describe neighbors without requiring every edge to be materialized. This unit only models transitions;BFS and DFS follow in the next unit.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

