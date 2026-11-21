# Euler intervals,binary lifting,rerooting and heavy paths

Phase 8 unit 4: 12 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[A preorder entry list stores every subtree contiguously](01_euler_subtree_intervals.cpp)|
|02|[Translate vertex updates into entry-position updates](02_subtree_fenwick.cpp)|
|03|[Use entry containment for constant-time ancestry](03_ancestor_interval_test.cpp)|
|04|[Compose two2^(j-1) jumps into one2^j jump](04_binary_ancestors.cpp)|
|05|[Raise both nodes without crossing their shared ancestor](05_binary_lifting_lca.cpp)|
|06|[Subtract twice the shared-root depth](06_tree_distance_queries.cpp)|
|07|[Moving across one edge changes two vertex groups oppositely](07_reroot_distance_sums.cpp)|
|08|[Replace vertex counts by additive vertex weights](08_weighted_reroot_scores.cpp)|
|09|[Choose vertices whose removal leaves no component larger than half](09_tree_centroids.cpp)|
|10|[Split a tree route into logarithmically many contiguous heavy chains](10_heavy_light_node_paths.cpp)|
|11|[Store an edge at its deeper endpoint and exclude the LCA slot](11_heavy_light_edge_paths.cpp)|
|12|[Compare updates and all-pair sums with direct BFS witnesses](12_heavy_path_oracle.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

