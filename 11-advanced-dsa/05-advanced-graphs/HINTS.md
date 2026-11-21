# Staged hints

Use the first hint after an independent attempt;read the second only after recording a trace and a specific difficulty.

## 1. Exercise 1

1. First DFS saves exits; second DFS on reversed arcs assigns one component ID at a time in reverse exit order.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 2. Exercise 2

1. Each SCC becomes one vertex; only arcs between different IDs remain, and duplicates are removed.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 3. Exercise 3

1. discovery records DFS entry times; low[u] is the earliest discovery reachable from subtree u through tree edges plus one back edge.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 4. Exercise 4

1. A nonroot u separates a DFS child when low[child]>=discovery[u]; root separates components only when it has more than one DFS child.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 5. Exercise 5

1. Delete bridge IDs conceptually, then use DSU on every remaining edge to identify 2-edge-connected groups.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 6. Exercise 6

1. Stack follows unused edges; when a vertex has none left, append it to the reversed final route.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 7. Exercise 7

1. A trail start may have out-in 1, end in-out 1; all others balance. Each adjacency entry is one directed edge to consume.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 8. Exercise 8

1. owner[v] stores the left vertex matched to right v; each new left root seeks an alternating augmenting route using a fresh left-visited array.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 9. Exercise 9

1. ZL, ZR are vertices reachable by unmatched left-to-right edges and matched right-to-left edges; cover is(Left minus ZL) union ZR.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 10. Exercise 10

1. Residual[u][v] is additional permitted flow; augmenting subtracts the bottleneck forward and adds it backward to permit undoing a prior choice.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 11. Exercise 11

1. BFS levels keep only forward one-level residual arcs; next[u] remembers exhausted edge candidates during one blocking-flow phase.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 12. Exercise 12

1. At termination, the source-reachable residual vertices form one side of the cut; preserve original capacities separately to compute its value.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

