# Independent practice

Use the corresponding lesson bounds. For each task provide the full input/output contract,a simple baseline,state definition,trace,proof,costs and normal/boundary/counterexample checks. Attempt without copying worked source.

## 1. Exercise 1

Flood the reversed graph in decreasing original finish order. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Validate mutual reachability against all-pairs traversal.

## 2. Exercise 2

Collapse SCC identities and deduplicate intercomponent arcs. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Deduplicate condensation arcs and verify acyclicity.

## 3. Exercise 3

A child unable to escape above its entering edge reveals a bridge. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include a parallel edge pair that must not be a bridge.

## 4. Exercise 4

Removing a vertex differs from removing its entering edge. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Separate the DFS-root child rule from the ordinary lowlink rule.

## 5. Exercise 5

Join all edges except identified bridges. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Remove every identified bridge and compare the remaining groups.

## 6. Exercise 6

Consume every edge once with a used-ID Hierholzer stack. Domain:Undirected multigraph with loops, V<=30; empty graph returns an empty route; zero-edge nonempty graph returns one vertex. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify the returned route consumes each edge ID exactly once.

## 7. Exercise 7

Require matching incoming/outgoing balance except two endpoints. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include a disconnected balanced directed component.

## 8. Exercise 8

Reroute an old match to free a desired right endpoint. Domain:Bipartite graph represented by L left adjacency rows into right IDs 0..R-1, L, R<=30. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Enumerate all tiny matchings and compare maximum size.

## 9. Exercise 9

Follow alternating reachability from unmatched left vertices. Domain:At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed; indices/ranges satisfy the stated domain. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Verify every edge is covered and cover size equals matching size.

## 10. Exercise 10

Augment along a BFS route and retain reverse cancellation capacity. Domain:Square nonnegative capacity matrix, V 2..30, capacities<=1000; source!=sink; parallel capacities are combined. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Compare maximum flow against all source-side cuts on four vertices.

## 11. Exercise 11

Exhaust a layered residual network before rebuilding levels. Domain:Directed capacities 0..1000, V 2..30; loops/parallel arcs allowed; call flow on a freshly built network with distinct source/sink. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Include parallel arcs,reverse arcs and self-loops.

## 12. Exercise 12

Residual reachability certifies the returned maximum flow. Domain:Nonnegative capacity matrix, V 2..30; distinct source/sink. Unless a different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. Independent extension:Return the actual source-side cut and its capacity.

