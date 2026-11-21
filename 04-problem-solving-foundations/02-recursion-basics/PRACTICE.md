# Independent recursion practice

Start from a blank file. Use small explicit bounds, keep assertions enabled for
teaching checks, and explain the base, progress, combination, time and live stack
space. Use an iterative or rule-based oracle when it adds independent evidence.

## 1. Frame ledger

Draw all active frames and pending products for factorial(4), using the n=0 base.

Example/result: 5 calls, deepest5 frames, final24.

## 2. Ascending versus descending output

Write both print-before-call and print-after-call variations for n in0..5.

Example/result: n=3 produces3,2,1 before calls or1,2,3 on return.

## 3. Sum odd numbers

Recursively sum the first n positive odd integers for0<=n<=20 and compare with n*n.

Example/result: n=4 ->1+3+5+7=16.

## 4. Digit count

Return the decimal digit count of a nonnegative bounded integer, treating0 as one digit.

Example/result: 0 ->1;1000 ->4.

## 5. Count a selected digit

Count occurrences of a chosen digit0..9, including the single digit of input0.

Example/result: 10020,target0 ->3;0,target0 ->1.

## 6. Instrument fast power

Count entries for one-call exponentiation by squaring and contrast two repeated half calls.

Example/result: exponent13 visits13,6,3,1,0:5 entries.

## 7. GCD trace

Trace gcd(21,13), including the base, and state why no remainder by0 occurs.

Example/result: (21,13)->(13,8)->(8,5)->(5,3)->(3,2)->(2,1)->(1,0):7 frames.

## 8. Normalized palindrome

Ignore ordinary spaces and English case, then use recursive symmetry checking.

Example/result: Never odd or even ->true.

## 9. Reverse only a subrange

Reverse [1,4) of abcde and define behavior for an empty subrange.

Example/result: abcde ->adcbe;[2,2) leaves it unchanged.

## 10. Recursive sortedness

Check whether a small vector is nondecreasing, including empty/singleton sequences.

Example/result: 1,1,3 ->true;1,3,2 ->false.

## 11. First matching index

Return the first index of a target or-1 in a bounded vector using recursion.

Example/result: 4,7,4,target4 ->0;empty ->-1.

## 12. Tail call safety

Convert an accumulator recursion to a loop and explain why a huge recursive input is not portable.

Example/result: sum1..100=5050; the loop needs constant extra state.

## 13. Balanced range product

Use divide-and-conquer for up to12 values in[-3,3], defining an empty product as1.

Example/result: 2,-3,0 ->0;empty ->1.

## 14. Hanoi with a different destination

Move3 disks from A to B, list the first legal move, and validate all moves with a peg simulator.

Example/result: 7 moves; the first move is disk1 A->B.


