# Subset,knapsack and coin states

Phase 7 unit 3: 12 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[Previous-item states enforce single use](01_zero_one_knapsack.cpp)|
|02|[Scan capacities downward to preserve the previous item layer](02_compressed_zero_one.cpp)|
|03|[Scan capacities upward when item reuse is intentional](03_unbounded_knapsack.cpp)|
|04|[Use boolean states for exact target reachability](04_subset_feasibility.cpp)|
|05|[Recover selected indices from the item-by-sum table](05_subset_reconstruction.cpp)|
|06|[Count both choices even when a zero leaves the sum unchanged](06_subset_counts_with_zeros.cpp)|
|07|[Reduce an equal two-way split to one half-sum state](07_equal_partition.cpp)|
|08|[Search reachable sums closest to half the total](08_minimum_partition_difference.cpp)|
|09|[Convert plus/minus labels into a subset-count equation](09_target_sign_assignments.cpp)|
|10|[Use an impossible sentinel for an exact minimum count](10_minimum_coins.cpp)|
|11|[Coin-first loops count unordered multisets](11_coin_combinations.cpp)|
|12|[Amount-first loops count ordered final-coin choices](12_coin_sequences.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

