# Mixed strings,search and state exploration: reasoning before code

Distinguish byte strings from human-language text;these exercises deliberately use bounded ASCII. Anagrams count multiplicities;subsequences preserve order but need not be contiguous;partitions cover every position exactly once. A witness must be checked against the original input. Search states must include all information needed to decide legal continuations. Backtracking restores mutations before exploring siblings. A visited cell belongs to the current word-search route,whereas BFS visitation belongs to the whole search frontier. Choose the smallest adequate state rather than memorizing a problem name.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

