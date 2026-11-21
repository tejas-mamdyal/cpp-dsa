# Staged hints

Attempt a hand trace before opening the hint.

## 1. Hint

First identify the state invariant and smallest legal input.

Next: Toggle a boolean for each removed lowest bit.

Check 7 odd;3 even;add one different boundary or failure case.

## 2. Hint

First identify the state invariant and smallest legal input.

Next: Use optional rather than a valid index as a sentinel.

Check zero absent;16 index4;add one different boundary or failure case.

## 3. Hint

First identify the state invariant and smallest legal input.

Next: XOR cancellation is not a general frequency validator.

Check triples are outside the paired contract;add one different boundary or failure case.

## 4. Hint

First identify the state invariant and smallest legal input.

Next: XOR is symmetric and self-XOR is zero.

Check distance10,12 is2;add one different boundary or failure case.

## 5. Hint

First identify the state invariant and smallest legal input.

Next: Trace the selected binary positions101.

Check 5,4,1,0;add one different boundary or failure case.

## 6. Hint

First identify the state invariant and smallest legal input.

Next: Each position belongs to half the masks.

Check n*2^(n-1) for n>0;add one different boundary or failure case.

## 7. Hint

First identify the state invariant and smallest legal input.

Next: Cancel the prefix before left only when left>0.

Check 1 and4;add one different boundary or failure case.

## 8. Hint

First identify the state invariant and smallest legal input.

Next: Arithmetic wrap and shift contracts are separate rules.

Check count must be smaller than width;add one different boundary or failure case.


