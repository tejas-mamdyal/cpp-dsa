# Unit checkpoint:20 points

Work without worked solutions. Aim for16/20 and no unexplained invalid access or
overflow. Each task is worth5: result/implementation2, derivation1, boundary1,
and an explicit correctness/memory argument1.

1. Derive the cost of two independent loops followed by an i<j pair loop. Include
   n=0 and1, state the selected count and identify the dominant term.
2. Write a bounded powers-of3 counter. Explain its stopping condition, integer
   safety, zero behavior and logarithmic count; trace n=28.
3. Implement a minimum helper with an empty-input policy. Explain initialization,
   maintenance and termination. Include singleton, duplicate and all-negative tests.
4. Compare pairwise and hash duplicate detection. State expected/worst-case time,
   space and a reproducible exhaustive small-input oracle strategy. Explain why
   passing a finite test set does not prove universal correctness.

Review guide: pair count n*(n-1)/2; powers at28 are1,3,9,27; the minimum state
represents the processed prefix; hashing is expected linear overall but can be
quadratic under collisions. Revisit NOTES.md for any missing assumption.

