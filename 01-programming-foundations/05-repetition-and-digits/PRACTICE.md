# Independent practice

Try without the worked source. Unless specified otherwise, accept only the stated
domain. From unit04 onward, reject malformed/out-of-domain input with an error
message and exit1. Before unit04, document the valid-input assumption instead.
A slash in a sample below separates output lines; it is not a printed character.

## 1. Sum of evens

Read n0..1000. Output sum of even integers from1 through n.

**Sample:** Input6 ->12

## 2. Digit frequency

Read n0..1000000000 and target digit0..9. Count occurrences, treating zero as one digit.

**Sample:** Input1000 0 ->3

## 3. Largest digit

Read n0..1000000000. Output largest decimal digit.

**Sample:** Input407 ->7

## 4. Integer power

Read base-10..10 and exponent0..18. Output repeated-multiplication power, defining0^0=1.

**Sample:** Input-2 3 ->-8

## 5. Arithmetic sequence

Read first-100..100, difference-10..10 and count0..20. Print exactly count terms, one per line.

**Sample:** Input2 3 4 ->2 /5 /8 /11

## 6. Geometric sequence

Read first-10..10, ratio-3..3, count0..10. Print exactly count terms, one per line.

**Sample:** Input2 3 3 ->2 /6 /18

## 7. Sentinel average

Read up to1000 marks0..100 terminated by-1. Print mean to two decimals, or no data when sentinel is first. Missing sentinel is invalid.

**Sample:** Input50 100 -1 ->75.00

## 8. Menu repetition

Read commands1 (print hello),2 (print bye),0 (quit). Reject unknown commands and EOF before quit; accept at most100 commands.

**Sample:** Input1 2 0 ->hello /bye

