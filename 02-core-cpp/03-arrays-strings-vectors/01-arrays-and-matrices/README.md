# Phase 2, unit 1: arrays and matrices

Prerequisites: Phase1 scalar types, conditions, loops, functions and validation.
Begin with [NOTES.md](NOTES.md). Arrays let a program retain multiple related
values for later passes; Phase1's streaming aggregates did not retain them.

## Core route

1. [Storage, indices and mutation](01_storage_and_indices.cpp)
2. [Initialization and active length](02_initialization.cpp)
3. [Bounded input and traversal](03_bounded_input.cpp)
4. [Safe indexed update](04_indexed_update.cpp)
5. [Sum and mean](05_sum_and_mean.cpp)
6. [Minimum/maximum with first positions](06_min_max_positions.cpp)
7. [First-match search](07_first_match.cpp)
8. [Reverse copy and preserved original](08_reverse_copy.cpp)
9. [Insertion by backward shifting](09_insert_with_shift.cpp)
10. [Deletion by forward shifting](10_erase_with_shift.cpp)

## Reinforcement: two-dimensional storage

11. [Matrix traversal](11_matrix_traversal.cpp)
12. [Row/column sums](12_row_and_column_sums.cpp)
13. [Transpose into separate storage](13_transpose_copy.cpp)
14. [Diagonal union without double counting](14_diagonal_sum.cpp)
15. [Elementwise matrix addition](15_matrix_addition.cpp)
16. [Flatten and restore](16_flatten_and_restore.cpp)

The first10 establish array fundamentals; complete11–16 before later matrix/vector
lessons. "Reinforcement" means a second application context, not material that can
be skipped when its later prerequisites are needed.

Each source includes input/output bounds, reasoning, a trace, complexity, pitfalls
and two follow-ups. Empty sequences are permitted where defined; matrix dimensions
are1..4. Invalid input reports an error and exits1. Results have no prompts.

From the repository root:

Input `3 4 -2 9` should produce `4 -2 9`. Input `0` produces one empty line.
Use [the Phase2 sequence](../../PHASE2_PLAN.md) to see what follows.

