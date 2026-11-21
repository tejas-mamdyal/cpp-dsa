# Prefix and interval states for text: reasoning before code

For two strings,dp[i][j] usually describes their first i and j characters;empty prefixes provide essential base rows. Matching final characters extends a diagonal predecessor;otherwise the problem determines which deletion,replacement or skip transitions are legal. Subsequence permits gaps;substring requires contiguous matching and resets to0 after mismatch.

Save full tables for reconstruction and tie policies. Rolling rows must preserve the old diagonal before overwriting it. Distinct-subsequence counts are positional and require descending target updates when compressed. Palindrome states explicitly use substring intervals:shorter intervals must be known before longer ones. Wildcard star means arbitrary text length,whereas regex star repeats its preceding atom;their grammars are not interchangeable.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

