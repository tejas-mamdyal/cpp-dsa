# Strong components,low links,Euler routes,matching,flow and2-SAT: reasoning before code

Strongly connected components partition mutual directed reachability;contracting them produces a DAG. Undirected low-link values summarize how far a DFS subtree can escape through a back edge. Bridges compare low[child]>discovery[parent];articulation uses>= with a separate root-child-count rule. Parent edge IDs preserve parallel-edge correctness.

Euler routes consume every edge once rather than visiting every vertex once. Degree conditions are necessary,but final consumed-edge count also checks connectivity. Bipartite augmenting paths may undo previous matches;alternating reachability gives a minimum vertex cover after maximum matching. Flow uses forward residual capacity and reverse cancellation capacity.2-SAT maps each two-literal clause to implications,then uses SCC contradiction tests and a component-order assignment. These are specialist extensions after the core graph and tree course.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

