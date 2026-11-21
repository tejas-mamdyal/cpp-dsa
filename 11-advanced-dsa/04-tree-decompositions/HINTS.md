# Staged hints

Use the first hint after an independent attempt;read the second only after recording a trace and a specific difficulty.

## 1. Exercise 1

1. tin[u] is its entry rank; tout[u] is the first rank after all descendants; order lists each vertex once.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 2. Exercise 2

1. Fenwick position tin[u] stores vertex u value; subtree sum uses[tin[u], tout[u]).
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 3. Exercise 3

1. An ancestor interval contains every descendant entry rank; self ancestry is included by convention.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 4. Exercise 4

1. up[j][u] is the 2^j-th ancestor with root self-saturation internally; the public method rejects requests beyond actual depth.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 5. Exercise 5

1. Equalize depths, then consider jumps descending by powers; accept a jump only if the two ancestors remain different.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 6. Exercise 6

1. depth[u]+depth[v] includes the common root-to-LCA segment twice; remove it to obtain the connecting edge count.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 7. Exercise 7

1. First compute subtree sizes and root 0 distance sum; answer[u] then means sum of distances from u to every vertex in the whole tree.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 8. Exercise 8

1. answer[u]=sum weight[v]*distance(u, v); sub[u] sums original-root subtree weights.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 9. Exercise 9

1. For each candidate u, the removal components are each child subtree plus the outside parent-side remainder.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 10. Exercise 10

1. heavy[u] is a largest child; head and position map each heavy chain to contiguous Fenwick positions. Query climbs the deeper chain head until both endpoints share a chain.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 11. Exercise 11

1. value[u] is the edge from parent[u] to u; root slot is unused. Cross-chain segments include their head incoming edge, but the final same-chain segment excludes the LCA position.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 12. Exercise 12

1. Maintain an independent value vector; BFS parent routes identify the exact path without using heavy-chain positions.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

