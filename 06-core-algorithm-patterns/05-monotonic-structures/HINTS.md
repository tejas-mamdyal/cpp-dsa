# Monotonic stacks and deques: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. Greater distances

1. Store indices and subtract; equal values do not satisfy the query.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 2. Previous greater

1. Scan left to right, popping <= candidates.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 3. Circular indices

1. Scan twice, push once, and retain original modulo indices.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. Span oracle

1. Stop at first strictly greater previous value.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. Histogram baseline

1. Include empty data, zeros, and equal-height bars.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Binary rectangle witness

1. Histogram height and width plus current row determine its coordinates.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. Tie ownership

1. There are 6 intervals; distance products must total 6.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Direct maximum contributions

1. Reverse inequalities while preserving asymmetric tie ownership.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Window minimum

1. Expire indices; pop no-smaller values at the back.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Spread witness

1. Save indices on strict improvement; deques supply current extrema.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Signed shortest oracle

1. Use positive targets with negative values and impossible cases.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. Length-bounded maximum

1. At end r, eligible prefixes lie in[r-R, r-L]; maintain their minimum with expiry and dominance.
2. Trace the state on a tiny input, then compare against a direct baseline.

