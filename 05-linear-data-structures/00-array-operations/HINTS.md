# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Normalize without negating an unbounded minimum integer.

Check [1,2,3],left1 ->[2,3,1];add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Write retained values then resize once.

Check [-1,3,0,-2] ->[3,0];add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Validate position and size before shifting.

Check capacity5,size5 unchanged;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: Fill backward and retain every occurrence.

Check [1,2] plus[2,2] ->[1,2,2,2];add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Count the candidate in a verification pass.

Check [1,2,3] has none;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Compare dimensions/cell counts before allocation.

Check same6 row-major cells;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Separate discovery markers from the write pass.

Check one original zero must not mark unrelated rows;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: The current one-space contract does not silently cover both.

Check normalize or preserve exactly;add one different boundary or failure case.


