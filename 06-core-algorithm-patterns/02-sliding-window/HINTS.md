# Sliding windows: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. Minimum fixed sum

1. Initialize from a real first window; negative values are permitted.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 2. First negative per window

1. Start with O(nk) scanning; after unit 05, use a deque of negative indices.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 3. Two zero budget

1. Track zeros and shrink while above two.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. Exactly three distinct

1. Subtract two at-most counts; test repeated identical values.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. Unique-byte reconstruction

1. Last positions may advance left but never move it backward.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Pattern presence

1. Use 26-count equality and document the changed empty-pattern convention.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. Category cover

1. Track satisfied required categories, then shrink while all remain present.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Binary target count

1. Difference of at-most sums handles zero runs; compare against all ranges.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Card endpoints witness

1. Enumerate k+1 splits and exchange one endpoint on each step.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Signed failure trace

1. Adding a negative value could restore validity, so discarding 5 permanently was unjustified.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Replacement window

1. Cost=length-maximum frequency; recompute 26 counts for a direct proof.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. At-most count

1. Each valid right endpoint contributes right-left+1 starts; use long long.
2. Trace the state on a tiny input, then compare against a direct baseline.

