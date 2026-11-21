# Reasoning before code

Sorting permits same-depth duplicate suppression when original order is irrelevant. For subsets, skip equal values only when i>start; equal values may still be chosen together deeper. For permutations, skip an equal predecessor only while that predecessor is unused. This canonical order selects one positional route per distinct value ordering.

Combination-sum candidates must be positive so remaining target decreases. Reuse stays at i; single use advances to i+1. Zero or negative candidates invalidate termination or cutoff proofs. Fixed-cardinality sums must finish need and target together. Descending iterative size updates prevent using a newly processed item twice; iterative subsets extend only the old collection size.

Gray code reflects the old half before adding a bit, so the join also changes one decision. Nondecreasing subsequences preserve input order: use local depth sets instead of sorting. Factorial blocks let a rank query skip complete permutation families.

Core:01-07,09,11. Reinforcement:08,12,13. Challenge:10,14. Read 01 before 02,05 before 06/07, and complete permutation enumeration before 14. Phase 3 bits precede Gray code; division/remainder precede factorial ranks.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

