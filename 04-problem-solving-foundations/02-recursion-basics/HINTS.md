# Staged recursion hints

Draw the smallest case before opening a hint. Do not execute unsafe infinite
recursion or invalid indexing just to obtain a failure.

## 1. Frame ledger

First: state the helper contract and solve the base by hand.

Next: Do not skip factorial(1); this particular helper stops only at0.

Check: 5 calls, deepest5 frames, final24. Add one different boundary and explain why the recursion stops.

## 2. Ascending versus descending output

First: state the helper contract and solve the base by hand.

Next: Keep the base silent so the output contains only1..n.

Check: n=3 produces3,2,1 before calls or1,2,3 on return. Add one different boundary and explain why the recursion stops.

## 3. Sum odd numbers

First: state the helper contract and solve the base by hand.

Next: Remove the final odd term2*n-1, and use0 for the empty sum.

Check: n=4 ->1+3+5+7=16. Add one different boundary and explain why the recursion stops.

## 4. Digit count

First: state the helper contract and solve the base by hand.

Next: Use n<10 as the one-digit base rather than returning0 for every n==0.

Check: 0 ->1;1000 ->4. Add one different boundary and explain why the recursion stops.

## 5. Count a selected digit

First: state the helper contract and solve the base by hand.

Next: Handle the last one-digit state explicitly so padding is not counted.

Check: 10020,target0 ->3;0,target0 ->1. Add one different boundary and explain why the recursion stops.

## 6. Instrument fast power

First: state the helper contract and solve the base by hand.

Next: Save the half result; count the base call too.

Check: exponent13 visits13,6,3,1,0:5 entries. Add one different boundary and explain why the recursion stops.

## 7. GCD trace

First: state the helper contract and solve the base by hand.

Next: Each pair is(a,b); b=0 executes only the base return.

Check: (21,13)->(13,8)->(8,5)->(5,3)->(3,2)->(2,1)->(1,0):7 frames. Add one different boundary and explain why the recursion stops.

## 8. Normalized palindrome

First: state the helper contract and solve the base by hand.

Next: Normalize safely with unsigned-char cctype arguments, and include the normalization allocation in the memory ledger.

Check: Never odd or even ->true. Add one different boundary and explain why the recursion stops.

## 9. Reverse only a subrange

First: state the helper contract and solve the base by hand.

Next: Use the same half-open helper; validate the wrapper bounds first.

Check: abcde ->adcbe;[2,2) leaves it unchanged. Add one different boundary and explain why the recursion stops.

## 10. Recursive sortedness

First: state the helper contract and solve the base by hand.

Next: Compare neighbors then solve the remaining suffix; choose a base before neighbor access.

Check: 1,1,3 ->true;1,3,2 ->false. Add one different boundary and explain why the recursion stops.

## 11. First matching index

First: state the helper contract and solve the base by hand.

Next: Inspect the current element before recurring to later positions; this bridges the next search unit.

Check: 4,7,4,target4 ->0;empty ->-1. Add one different boundary and explain why the recursion stops.

## 12. Tail call safety

First: state the helper contract and solve the base by hand.

Next: C++ does not guarantee tail-call elimination; do not test by intentionally exhausting the stack.

Check: sum1..100=5050; the loop needs constant extra state. Add one different boundary and explain why the recursion stops.

## 13. Balanced range product

First: state the helper contract and solve the base by hand.

Next: Use a singleton base, disjoint halves and a multiplication identity; compare against an independent loop.

Check: 2,-3,0 ->0;empty ->1. Add one different boundary and explain why the recursion stops.

## 14. Hanoi with a different destination

First: state the helper contract and solve the base by hand.

Next: Rename source/spare/destination consistently rather than changing only the printed labels.

Check: 7 moves; the first move is disk1 A->B. Add one different boundary and explain why the recursion stops.


