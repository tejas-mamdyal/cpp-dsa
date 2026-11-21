# Shortest paths and algorithm selection: reasoning before code

Bellman-Ford propagates routes through at most one additional edge per logical pass;an improvement after V-1 passes implies a reachable negative cycle. Distinguish a cycle anywhere from a cycle reachable from the requested source,and distinguish affected destinations from unaffected ones. Floyd-Warshall adds allowed intermediate vertices one at a time;finite path reconstruction must reject pairs influenced by negative cycles. Store parents or next hops when a route is required.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

