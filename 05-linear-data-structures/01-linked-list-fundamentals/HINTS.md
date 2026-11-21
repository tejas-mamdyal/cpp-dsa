# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: No allocation is needed for empty data.

Check head stays null;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Do not use the old observer afterward.

Check live count returns to baseline;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Tail is an observer,not another owner.

Check 1->2->3->null;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: Deleted storage cannot identify the remaining suffix.

Check save next while the current node is live;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Default pointer copying is shallow.

Check two owners must not delete one allocation set;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Both allocation sets need their own cleanup.

Check original remains unchanged;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Sum the growing traversal lengths.

Check quadratic versus linear construction;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Do not return a silently partial list on allocation failure.

Check partial nodes are reclaimed;add one different boundary or failure case.


