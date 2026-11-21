# From recursive states to memoization,tables and compressed storage: reasoning before code

Dynamic programming solves overlapping subproblems by defining a state,deriving its transitions,and storing answers instead of recomputing them. Begin with the recursive recurrence and draw repeated calls. Memoization is demand-driven recursion with a cache;tabulation evaluates dependencies first in a chosen order. Compression discards values only after proving no future transition needs them.

For each program write what dp[index] means,its base cases,invalid states,dependency directions and returned answer before coding. Counting,minimum cost and maximum value need different initialization identities. An impossible state is not the same as a valid0 answer. Empty-choice policies and numeric bounds are part of correctness,not implementation details.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

