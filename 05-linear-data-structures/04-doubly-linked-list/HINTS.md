# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Update the opposite endpoint when no neighbor remains.

Check both endpoints null;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: The old head.prev must point to the new node.

Check new head.prev null;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Validate ownership in a higher-level API if foreign handles are accepted.

Check unchecked unlink can corrupt another owner;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: Check backward links too.

Check original sequence/endpoints recovered;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Search is linear;wiring is constant-time.

Check 1,2,2,3;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Save next and use one centralized unlink rule.

Check tail moves to its predecessor;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Return before touching its null prev link.

Check same identity/live count;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: An observer is an API capability,not free search.

Check constant relink versus linear lookup;add one different boundary or failure case.


