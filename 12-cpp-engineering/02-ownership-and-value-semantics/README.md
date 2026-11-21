# Ownership,copy/move and exception-safe values

Phase 9 unit 2: 14 worked programs and 12 independent exercises. Complete earlier units first. Read [notes](NOTES.md),then numbered programs,then attempt [practice](PRACTICE.md) before [hints](HINTS.md). Keep assertions enabled. Every worked source is standalone C++17 and prints `checks passed` after its internal checks.

Core route: first two thirds of the numbered lessons. Reinforcement/challenge: remaining lessons;read their notes before attempting,then return before the final assessment. All lesson prerequisites still follow the full numeric reading sequence.

|Order|Worked program|
|---|---|
|01|[Let containers supply independent copy ownership](01_rule_of_zero.cpp)|
|02|[Allocate a separate resource when copying an owner](02_deep_copy_constructor.cpp)|
|03|[Prepare then swap to preserve the old value on allocation failure](03_copy_assignment_commit.cpp)|
|04|[Transfer ownership and inspect only a promised moved-from state](04_move_constructor.cpp)|
|05|[Release the previous resource before accepting a transferred owner](05_move_assignment.cpp)|
|06|[Make relocation guarantees visible to generic containers](06_noexcept_move_trait.cpp)|
|07|[Tie a non-memory resource obligation to scope lifetime](07_raii_scope_cleanup.cpp)|
|08|[Return a unique owner without manual cleanup branches](08_unique_ownership_factory.cpp)|
|09|[Observe shared lifetime without extending it accidentally](09_shared_and_weak_observers.cpp)|
|10|[Store explicit nonowning references to existing objects](10_reference_wrapper_observation.cpp)|
|11|[Give value comparison a coherent meaning](11_operator_equality.cpp)|
|12|[Build nonmutating arithmetic from a mutating primitive](12_operator_addition.cpp)|
|13|[Validate a replacement fully before committing it](13_transactional_validation.cpp)|
|14|[Check copies,moves,self-assignment and container growth together](14_lifetime_regression_suite.cpp)|

Complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the phase guide](../README.md).

