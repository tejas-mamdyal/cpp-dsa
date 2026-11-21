# Phase 5 final assessment

Allow 180 minutes. Close worked sources and hints. Use C++17 and the stated bounded contracts. Total 100 points;pass at 80 with at least half the correctness and proof points on every implementation. Record hints used and retry those parts later without copying.

1. **20 points:** return unique single-use target combinations from a positive repeated-value array of length<=12. Prove same-depth duplicate suppression and compare against a deduplicated mask oracle.
2. **15 points:** solve or reject a4x4 Sudoku while preserving input on failure. Validate dimensions and clues;show an invalid complete board and an unsatisfiable valid-clue case.
3. **20 points:** implement null-marked tree roundtrip plus edge diameter. Compare full shape/value equality and verify diameter against all-pairs distances on small generated trees.
4. **15 points:** implement strict-BST deletion for all three structural cases. Model interleaved operations with a set,include integer endpoint keys,and explain borrowed-pointer invalidation.
5. **10 points:** return medians after a short stream including negatives and duplicates. State both heap invariants and compare with sorted prefixes.
6. **10 points:** implement limited lexical suggestions and erasure in an owned trie. Include empty word,shared prefixes,missing prefix and limit0.
7. **10 points:** extend one project independently:print expression trees with unambiguous parentheses,or add transactional dictionary save/load. Specify behavior first and demonstrate malformed-input handling and preserved state.

For each implementation allocate half its points to correct behavior,one quarter to proof/ownership/state reasoning,and the remaining quarter to contracts,costs and meaningful tests. Round only the final score. Hardcoded samples earn no implementation points. Expected reasoning directions are in the unit hints;use them only after submission and self-scoring.

Oral review:why can a signed-sum branch not be cut at sum>target? Why does a tree path return one arm while scoring two? Why is BST height not always logarithmic? Why does deleting a trie word not imply deleting its prefix node? What do finite model checks establish,and what still needs a proof?

