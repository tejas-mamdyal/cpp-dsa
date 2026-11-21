# Greedy choices, intervals and sweeps: staged hints

Read the first hint before revealing the second. Write your own attempt before consulting either.

## 1. Schedule witness

1. Retain original indices while sorting by finish.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 2. Endpoint comparison

1. Decide whether coordinate 2 is shared and when a room is released.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 3. Remove versus move

1. Deletion count=n-maximum kept count.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 4. Closed insertion

1. Result[1,2],[3,10]; the endpoint 8 connects the latter components.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 5. Rooms oracle

1. Nonempty half-open integer intervals have their active segments captured by integer samples.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 6. Train tie change

1. [0,10] and[10,20] need 2 originally and 1 after changing the rule.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 7. Arrow witness

1. Use earliest uncovered ends and skip all closed intervals containing each arrow.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 8. Divisibility matters

1. Enumerate the 8 indivisible subsets; the fractional exchange proof cannot apply to them.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 9. Coin failure

1. Greedy uses 3 coins;6+6 uses 2.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 10. Jump route

1. Mark a predecessor on first reach; follow it backward after reaching the end.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 11. Union components

1. Ignore empty intervals; touching positive intervals form one component.
2. Trace the state on a tiny input, then compare against a direct baseline.

## 12. Greedy proof review

1. One long first interval blocks 3 short ones; earliest finish leaves at least as much future room.
2. Trace the state on a tiny input, then compare against a direct baseline.

