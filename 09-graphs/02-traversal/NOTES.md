# Traversal,components and implicit graph search: reasoning before code

DFS explores one route before siblings;BFS processes layers using a FIFO queue. Mark BFS vertices when enqueued,not when removed,to avoid repeated work. A global visited array is appropriate for reachability/components,unlike backtracking paths where flags must be undone.

For directed cycles,unseen/active/finished states distinguish an ancestor back edge from an edge into a completed branch. Undirected multigraphs require parent edge IDs,not only parent vertices. Bipartite colors assign opposite sides across each edge;an odd cycle or loop makes that impossible. Grid cells are implicit vertices,and multiple starting cells form one shared BFS frontier.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

