# Child summaries and acyclic memoized dependencies: reasoning before code

Root an undirected tree with a parent parameter;the valid-tree precondition makes excluding the parent sufficient. A state at u describes only its rooted subtree. Inclusion/exclusion boundaries determine which child states are compatible. Return every state the parent needs rather than a locally best value that hides a constraint.

Tree knapsack combines independent child choices under a budget,while requiring selected branches to remain connected to their root. DAG memoization follows directed dependencies and may reuse a vertex across several predecessor calls. Strictly increasing matrix moves are acyclic without an explicit topological sort. Catalan counting chooses left/right subtree sizes;adding a height bound introduces another necessary dimension.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

