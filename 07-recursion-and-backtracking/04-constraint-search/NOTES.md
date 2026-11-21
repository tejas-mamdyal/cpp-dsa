# Reasoning before code

Constraint search chooses a variable, value and completion. Prune a partial violation only when later decisions cannot repair it. Queens track columns and diagonal identities. Sudoku validates fixed clues before exploring blanks; success may deliberately retain a solved board while failure restores all tentative values. State that output contract explicitly.

Minimum remaining values chooses the blank with fewest legal options. It changes search order, not the set of solutions or exponential worst-case complexity. A graph here means vertices with pairwise edges; the symmetric adjacency matrix states which pairs constrain one another. This model is introduced before coloring and Hamiltonian routes, without assuming later traversal algorithms. Self-loops prevent proper coloring. Labeled color renamings count as different assignments.

Cryptarithmetic injects letters into distinct digits and forbids leading zero for multi-digit words. Tiny indivisible knapsack uses explicit item choices rather than Phase 4 fractional density. Complete column permutations provide an independent queen oracle.

Core:01-04,06,11,12. Reinforcement:05,07,09. Challenge:08,10. Read 03 before 04/05 and 06 before 07/09. Keep search bounds small; heuristics do not guarantee polynomial runtime.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

