# Reasoning before code

A partition chooses contiguous nonempty pieces covering the entire input. start marks the uncovered suffix; each legal end must advance it. Palindrome and dictionary partitions differ in their validity predicate. Minimum palindrome cuts is intentionally an exponential enumeration baseline here; DP is taught later.

A grid cell is a(row, column) pair. Four-direction neighbors change one coordinate by 1; check bounds before indexing. A simple route cannot repeat a cell. Its visited flags are path-local and must clear before sibling routes and early returns. Down/right-only routes cannot cycle because row+column strictly increases. These coordinate and adjacency ideas are explained here before general graph algorithms.

Positive equal-bucket search may reject capacity excess and equivalent empty buckets. Meet in the middle uniquely splits a subset into two halves. Keep half-sum multiplicities: equal sums can represent different positional choices. A sorted half supports equal_range counting or the two neighbors around lower_bound.

Core:01,03-06,09,11. Reinforcement:02,07,08,10. Challenge:12. Read 01 before 02,05 before 06-09, and Phase 3 binary boundaries before 11/12. Multiple-word search is a readable per-word baseline; trie optimization follows trie fundamentals.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

