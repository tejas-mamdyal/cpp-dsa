# Decision trees: staged hints

Read hint1 first;use hint2 only after recording an independent attempt. These give reasoning directions rather than complete code.

## 1. Ternary strings

1. Make one branch per alphabet symbol.
2. One shared path needs exactly one pop for each push.

## 2. Copied versus shared state

1. The by-value version needs no undo because each child owns its prefix.
2. Explain O(n^2) copied active-prefix storage versus O(n) shared path.

## 3. Exact subset order

1. Both methods have identical multisets but different traversal orders.
2. List all eight leaves by hand before writing assertions.

## 4. Subsequence multiplicity

1. Generate eight positional results.
2. Sort a copy and count changes to find seven distinct strings;do not silently remove duplicates from the original contract.

## 5. Instrumentation

1. Leaves are3^n and active frames are n+1.
2. Sum level counts1+3+...+3^n for calls;do not confuse cumulative calls with simultaneous depth.

## 6. Choose k indices

1. Use strictly increasing positions to prevent permutation duplicates.
2. Equal values may still yield equal-looking results;position identity remains part of the specification.

## 7. Signed witness count

1. Check only complete leaves unless you prove a stronger cutoff.
2. [5,-4] at target1 disproves sum>target pruning;[0,0] at target0 has four positional solutions.

## 8. Restoration on success

1. Copy a successful witness before unwinding.
2. Undo your own mutation before every early return,including successful ones.

## 9. Bounded parentheses depth

1. Current depth=opened-closed.
2. Opening is legal only below D;closing is legal only after an unmatched opening. Handle n=0,D=0.

## 10. Custom mapping

1. This generalizes keypad Cartesian products.
2. Zero lists have one empty combination;one empty list has no complete combination.

## 11. Permutation oracle

1. The library algorithm is already taught in Phase2.
2. Preserve one empty permutation;sort both result collections before comparing complete multisets.

## 12. Break the count-only test

1. Its result count is right but its contents are wrong for nonzero input.
2. Compare sorted multisets with independent bit masks;keep this broken demonstration separate from canonical helper code.

