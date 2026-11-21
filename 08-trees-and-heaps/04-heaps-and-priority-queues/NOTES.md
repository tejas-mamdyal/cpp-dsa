# Reasoning before code

A heap is a complete array-backed binary shape with a partial order, not a sorted array. Push repairs ancestors; pop repairs descendants. Vector growth occasionally reallocates, so distinguish that cost from logarithmic heap comparisons. Bottom-up build is linear because few nodes can travel many levels; repeated push is generally O(n log n).

Heap sort keeps an unsorted heap prefix and finalized ascending suffix. Restrict repair to that prefix. priority_queue pop returns nothing; read top before removal and never read an empty top. A comparator says its first argument comes later in the chosen priority. Define strict deterministic ties.

Top-k keeps the worst retained candidate at the root. Frequency and distance problems need explicit rank definitions. Sorted merging keeps one frontier per input. Owned-list merging transfers existing nodes; heap records only borrow. Rope merging has an exchange proof using deepest sibling weights. Running median balances lower max-heap and upper min-heap while preserving cross-partition order. A k-displaced sort requires its displacement promise.

Core:01-08,10-11. Reinforcement:09,12-13,15. Challenge:14,16. Array mapping and heap invariants precede operations; build precedes sort; standard queues precede custom comparators. Pair/tuple ranks are lexicographic, as taught in Phase 2.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

