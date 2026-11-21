# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Locate/validate the predecessor before allocating.

Check only invalid position is rejected;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Keep the predecessor stationary after each deletion.

Check head becomes null;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Empty means both head and tail null.

Check new singleton has valid endpoints;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: Transferred inputs must not later delete the result.

Check one result owns all nodes;inputs null;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Do not overwrite an already owning output pointer.

Check two disjoint owners or unchanged failure;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Its physical successor is the victim.

Check supplied allocation survives with a different value;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: In-place data mutation does not imply constant auxiliary space.

Check both linear time;recursive stack linear;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Continue until carry is exhausted and preserve borrowed inputs.

Check 0,0,0,1;add one different boundary or failure case.


