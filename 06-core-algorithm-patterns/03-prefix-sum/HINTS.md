# Prefix, suffix and difference arrays: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. Vowel range counts

1. Use a leading-zero prefix count and subtract two entries.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 2. Signed target oracle

1. Query prefix-target before inserting current prefix; seed zero frequency.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 3. Balanced parity

1. Map categories to+1/-1 and keep earliest balance positions.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. Divisibility

1. Normalize the remainder before indexing and count earlier equal remainders.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. All equilibrium indices

1. Subtract the current value from total-left; current belongs to neither side.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Product zeros

1. An empty-side product is 1; bound magnitudes to prevent overflow.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. Batch additions

1. An n+1 difference vector accommodates r+1==n.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Rectangle totals

1. Draw the double-subtracted overlap and add it back once.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Rectangle painting

1. Cancel at end row/end column and integrate in both dimensions.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Disjoint windows

1. Try both width orders; best-left must be a real window even when negative.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Zero-sum witness

1. Store earlier prefix positions; query before insertion forbids empty self-matches.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. Palindrome permutations

1. At most one odd frequency is allowed; aabb qualifies though it is not itself a palindrome.
2. Trace the state on a tiny input, then compare against a direct baseline.

