# Kadane and interval optimization: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. All-negative audit

1. Initialize from real input; handle empty input by absence.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 2. Earliest maximum

1. Restart only for negative carried sum; save only strict improvement.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 3. Minimum reconstruction

1. Reverse comparisons and track the candidate start.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. Circular oracle

1. Use modulo indexing but never allow length above n.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. Product oracle

1. Bound magnitudes; include zero and negative singleton.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Rectangle witness

1. Save row band and reconstructed Kadane columns.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. At least k negatives

1. Answer -4; zero is not a legal initial candidate.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Length distinction

1. All-positive input makes longer intervals preferable.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Optional deletion

1. No deletion is allowed; deleting the only element is not.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Bad restarts

1. Use[2,3] and[-2] as separate regressions.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Bounded length

1. Enumerate eligible starts with prefix sums; unit 05 later optimizes this.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. One trade

1. Differences telescope to sell minus buy; no trade allows profit 0.
2. Trace the state on a tiny input, then compare against a direct baseline.

