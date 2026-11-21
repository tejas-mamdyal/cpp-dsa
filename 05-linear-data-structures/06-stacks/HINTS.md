# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Do not reserve a valid stored value as an error sentinel.

Check empty ->absence;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Check count before writing.

Check old top retained;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: Retain each prefix minimum independently.

Check minimum still1;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: LIFO order matters,not only totals.

Check ([)];add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Pop the right operand first.

Check 7 and5;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Track grammar state as well as precedence.

Check explicit invalid result;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Each push moves all earlier values.

Check n pushes can be quadratic total;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Total work and maximum live depth are separate quantities.

Check 1+2+...+n;add one different boundary or failure case.


