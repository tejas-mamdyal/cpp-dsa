# Independent practice

Try without the worked source. Unless specified otherwise, accept only the stated
domain. From unit04 onward, reject malformed/out-of-domain input with an error
message and exit1. Before unit04, document the valid-input assumption instead.
A slash in a sample below separates output lines; it is not a printed character.

## 1. Fix a boundary

A loop for sum1..n uses i<n. Find smallest failing n, repair and retest. Domain n0..100.

**Sample:** n1 should give1

## 2. Fix progress

A while(i<=n) loop prints i but never updates i. Repair it for n0..10.

**Sample:** n2 should print1 /2

## 3. Fix branch order

A grade classifier checks mark>=40 before mark>=90. Repair A/pass/fail classification.

**Sample:** mark95 should print A

## 4. Fix average

A three-mark average stores(a+b+c)/3 in double. Repair and test fractional output.

**Sample:** 1 2 2 should give1.67

## 5. Fix initialization

A maximum over n>=1 signed values initializes best=0. Repair it without arrays.

**Sample:** -8 -2 -4 should give-2

## 6. Fix the sentinel

A loop adds a value before checking for-1. Repair sentinel sum.

**Sample:** 5 -1 should give5

## 7. Design regression tests

Specify valid, boundary and malformed-input tests for a division program that accepts integers[-100,100] and rejects divisor0.

**Sample:** 8 2 ->4;8 0 ->error

## 8. Independent oracle

Compare a loop implementation of sum of squares with n*(n+1)*(2*n+1)/6 for n0..100. Output checks passed after assertions succeed.

**Sample:** For n3 both results14

