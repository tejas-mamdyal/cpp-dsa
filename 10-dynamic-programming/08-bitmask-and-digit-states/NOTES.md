# Subset masks and bounded-digit states: reasoning before code

A bitmask records exactly which finite objects are already used. Adding an unused bit gives a larger mask,which provides a tabulation order. The mask may imply the next worker number,so avoid storing redundant dimensions. A route additionally needs its final vertex;reconstruction stores predecessor masks/vertices or explicit choices.

Digit DP walks a fixed-width decimal representation under a bound. tight means the chosen prefix equals the bound so far;only then is the current bound digit restrictive. Cache non-tight states because their future does not depend on the bound prefix. Leading zeros preserve numeric identity but may not count as actual digits;use a not-started state when adjacency or zero occurrences depend on representation. Inclusive ranges use count(R)-count(L-1),with negative prefixes defined as0.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

