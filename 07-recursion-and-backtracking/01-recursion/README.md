# Decision trees and restored state

Phase 5 unit 1 is released: 12 worked programs and 12 independent exercises. This expands recursion learned in Phase 3 into backtracking; it does not repeat factorial and recursive arithmetic. Complete Phase 4 first, then read [the notes](NOTES.md).

Core route: 01-08 and 11. Reinforcement: 09-10. Verification challenge: 12. Read numerically on the first pass: copied state precedes shared state, subsets precede constrained choices, and full enumeration precedes early success.

|Order|Worked program|
|---|---|
|01|[Draw a binary decision tree before collecting results](01_binary_decisions.cpp)|
|02|[Replace copied branches with one restored path](02_shared_path_restore.cpp)|
|03|[Choose exclude or include for each input position](03_subsets_choose_undo.cpp)|
|04|[Subsequence choices preserve order and position identity](04_subsequence_positions.cpp)|
|05|[Separate total calls from maximum active depth](05_calls_leaves_and_depth.cpp)|
|06|[Prune only when too few positions remain](06_fixed_size_combinations.cpp)|
|07|[Signed values forbid an unproved sum cutoff](07_signed_subset_sum.cpp)|
|08|[Early success still owes the caller an undo](08_first_solution_restoration.cpp)|
|09|[Reject invalid prefixes before creating complete strings](09_balanced_parentheses.cpp)|
|10|[A level may offer more than two choices](10_keypad_cartesian_product.cpp)|
|11|[Permutation state includes both path and availability](11_permutations_used_flags.cpp)|
|12|[Compare recursion against independent bit-mask enumeration](12_independent_subset_oracle.cpp)|

Every source is standalone C++17 with commented state, hand trace, proof, costs, pitfalls and meaningful choose/explore/undo comments. Keep assertions enabled. No input is required; a successful run prints `checks passed`.

Attempt [practice](PRACTICE.md) independently before [staged hints](HINTS.md), then complete debugging and [the checkpoint](CHECKPOINT.md). Continue through [the Phase 5 plan](../PHASE5_PLAN.md); subsequent units remain under expansion.


