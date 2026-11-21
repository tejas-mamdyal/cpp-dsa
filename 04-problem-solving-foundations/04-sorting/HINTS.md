# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Change the strict shift comparison,not tie handling.

Check [2A,1B,2C] ->[2A,2C,1B];add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: A distant swap can cross an equal record.

Check [2A,2B,1C] can become[1C,2B,2A];add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Children finish before the parent overwrites its own output interval.

Check disjoint half-open ranges;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: Partition sizes repeatedly become n-1 and0.

Check already sorted input;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Repair children before parents and shrink the active heap prefix.

Check [3,1,4,2],first maximum4;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Choose a signed transformation or separate sign groups first.

Check negative digit index is invalid;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Use offsets and disjoint prefix-count output positions.

Check equal keys retain arrival order;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Equal keys must not be counted as inversions.

Check [2,2,1] has2 inversions;add one different boundary or failure case.


