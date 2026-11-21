# Borders,hash filters,palindrome radii and suffix indexes: reasoning before code

Borders describe prefixes that also occur as suffixes;KMP follows shorter border links after mismatches without rewinding text. Z stores matching-prefix lengths at every starting position. Exact substring search and whole-word period detection have different endpoint conventions,especially for empty patterns.

Polynomial hashes are filters with possible collisions;verify candidate text when correctness must be deterministic. Manacher separates odd and even centers and reuses mirrored radii only inside the known palindrome boundary. Suffix arrays sort starting positions,then LCP exposes overlap between adjacent suffixes. A suffix automaton groups substring end-position classes;length ranges and suffix links explain its compressed representation before construction. Aho-Corasick extends a previously taught trie with failure/output links before scanning multiple patterns. Optional source references are listed in REFERENCES.md;all necessary explanations and tests are local.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

