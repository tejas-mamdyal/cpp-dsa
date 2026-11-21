# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Find first>key and verify its predecessor.

Check [1,2,2,4],2 ->index2;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Use the first>=key boundary.

Check [1,2,2],2 ->index1;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Subtract upper(low) from lower(high);handle low>=high.

Check [1,2,2,3,4],1..4 ->3;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: The end sentinel is a valid boundary answer.

Check n8 ->boundaries8 and0;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Use floor root then check exactness without overflow.

Check 26 ->6;25 ->5;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Flattening does not satisfy binary search preconditions.

Check [1,4;2,5];add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Use a half-open empty-range base and return the child answer.

Check [1,3,3],3 ->1;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Count a specific operation and include empty input.

Check absent key in31 values;add one different boundary or failure case.


