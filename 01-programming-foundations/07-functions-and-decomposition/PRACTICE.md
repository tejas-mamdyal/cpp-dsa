# Independent practice

Try without the worked source. Unless specified otherwise, accept only the stated
domain. From unit04 onward, reject malformed/out-of-domain input with an error
message and exit1. Before unit04, document the valid-input assumption instead.
A slash in a sample below separates output lines; it is not a printed character.

## 1. Minimum helper

Implement minimum(a,b) and use it for two ints in[-100,100].

**Sample:** Input4 -2 ->-2

## 2. Digit product helper

Implement digitProduct(n) for n0..1000000000.

**Sample:** Input123 ->6; input0 ->0

## 3. Leap predicate

Implement isLeap(year) with year1..9999 and print0/1.

**Sample:** Input1900 ->0; input2000 ->1

## 4. Clamp helper

Implement clamp(value,low,high), values in[-100,100] and low<=high. Output the nearest value in[low,high].

**Sample:** Input20 0 10 ->10

## 5. Distance helper

Implement integer distance(a,b) for a,b in[-1000,1000]. Output nonnegative difference.

**Sample:** Input-3 4 ->7

## 6. Count divisors helper

Implement divisorCount(n) for1..1000. Print its result.

**Sample:** Input6 ->4

## 7. Composition task

Read n0..1000000. Use digitSum and isPrime helpers to print whether digit sum is prime.

**Sample:** Input29 ->prime

## 8. Value-copy explanation

Write a helper addFive(value). Print its returned result and the unchanged original input.

**Sample:** Input3 ->8 3

