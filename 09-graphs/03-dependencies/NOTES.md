# Directed dependencies and DAG applications: reasoning before code

A topological order places every directed prerequisite before its dependent. It exists exactly when the directed graph is acyclic. Kahn removes indegree-zero vertices;DFS reverses finishing order but must also reject active back edges. Validate an order against every arc rather than comparing one arbitrary expected sequence.

A DAG permits forward accumulation because all incoming dependencies are complete before a vertex is processed. This unit explicitly defines path counts,earliest finish and distance states before using them;general DP design is expanded in Phase7. Multiple valid schedules require tie rules or enumeration. Safe-state elimination reverses edges and repeatedly removes terminal-safe vertices.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

