# Shortest paths and algorithm selection

Phase 6 unit 4: 15 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[Reconstruct a shortest route from discovery parents](01_unweighted_route.cpp)|
|02|[Find the closest source in an unweighted graph](02_multiple_graph_sources.cpp)|
|03|[Finalize nonnegative distances with a minimum heap](03_dijkstra_distances.cpp)|
|04|[Update the predecessor only on a strict distance improvement](04_dijkstra_route.cpp)|
|05|[Place zero-cost improvements before one-cost improvements](05_zero_one_bfs.cpp)|
|06|[Detect reachable negative cycles through an extra relaxation pass](06_bellman_ford.cpp)|
|07|[Propagate the set of destinations without a finite shortest value](07_negative_cycle_destinations.cpp)|
|08|[A zero-cost super-source reaches every component](08_any_negative_cycle.cpp)|
|09|[Add allowed intermediate vertices one at a time](09_floyd_warshall.cpp)|
|10|[Store the first hop and reject negative-cycle-affected pairs](10_floyd_reconstruction.cpp)|
|11|[Require every requested destination to be reachable](11_network_delay.cpp)|
|12|[Relax with maximum edge effort instead of additive cost](12_minimax_grid_effort.cpp)|
|14|[Use a virtual free source for several starting points](14_multiple_weighted_sources.cpp)|
|15|[Refute settled-vertex greedy reasoning with a signed edge](15_negative_weight_counterexample.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

