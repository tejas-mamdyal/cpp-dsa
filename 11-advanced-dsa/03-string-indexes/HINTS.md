# Staged hints

Use the first hint after an independent attempt;read the second only after recording a trace and a specific difficulty.

## 1. Exercise 1

1. pi[i] is the length of the longest proper prefix also a suffix of pattern[0..i]; a mismatch at candidate length j falls back to pi[j-1].
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 2. Exercise 2

1. j is the matched pattern-prefix length at the current text suffix; prefix links preserve the next possible continuation after failure or complete match.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 3. Exercise 3

1. z[i] is the longest common prefix of the whole text and suffix i;[l, r) is the farthest-right already known matching-prefix window.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 4. Exercise 4

1. The final longest border suggests candidate n-pi[n-1]; it is a full repeating unit only if it divides n.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 5. Exercise 5

1. prefix[i] hashes first i bytes with multiply-by 31 then add; powers[len] shifts a preceding prefix into the same position for subtraction.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 6. Exercise 6

1. The hash is a fast rejection filter; only exact substring comparison can emit a match.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 7. Exercise 7

1. radius[i] includes the center character, so its maximum odd palindrome length is 2*radius[i]-1;[left, right] is the inclusive rightmost palindrome.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 8. Exercise 8

1. radius[i] counts matching pairs around the gap before i; its palindrome length is 2*radius[i].
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 9. Exercise 9

1. Each center radius counts all smaller palindromes with the same center; track longest start/length while summing radii.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 10. Exercise 10

1. rank[i] orders the current fixed-length suffix prefix; sort pairs of its first and second half ranks, then assign new equivalence ranks.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 11. Exercise 11

1. lcp[rank] is common-prefix length with the previous suffix in suffix order; lcp 0=0. Reuse common-1 after advancing the original start index.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 12. Exercise 12

1. A suffix of length n-start contributes all its prefixes except the lcp with its previous lexicographic neighbor.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

