# Disjoint sets and minimum spanning forests

Phase 6 unit 5: 15 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[Represent each component by a parent root](01_parent_forest_baseline.cpp)|
|02|[Compress root paths and link smaller components underneath larger](02_compression_and_size.cpp)|
|03|[Decrement component count only for a successful merge](03_dsu_component_count.cpp)|
|04|[An edge within one current set closes an undirected cycle](04_redundant_connection.cpp)|
|05|[Require connectivity and exactly the necessary acyclic edges](05_is_undirected_tree.cpp)|
|06|[Choose the next lightest edge crossing current components](06_kruskal_forest.cpp)|
|07|[Reject a disconnected forest when a single spanning tree was requested](07_spanning_tree_or_absence.cpp)|
|08|[Grow one component at a time across its cheapest frontier edge](08_prim_forest.cpp)|
|09|[Compare two independent greedy frontier orders](09_forest_cross_check.cpp)|
|10|[Use matrix connectivity to join undirected groups](10_province_matrix.cpp)|
|11|[Join account identities sharing a contact key](11_accounts_merge.cpp)|
|12|[Activate cells before unioning their active neighbors](12_incremental_islands.cpp)|
|13|[Count spare edges and remaining components separately](13_network_rewiring.cpp)|
|14|[Model shared rows and columns as a bipartite DSU graph](14_remove_stones.cpp)|
|15|[Turn a known deletion batch into reversed additions](15_reverse_edge_deletions.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

