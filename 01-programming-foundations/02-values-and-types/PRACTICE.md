# Independent practice

Try without the worked source. Unless specified otherwise, accept only the stated
domain. From unit04 onward, reject malformed/out-of-domain input with an error
message and exit1. Before unit04, document the valid-input assumption instead.
A slash in a sample below separates output lines; it is not a printed character.

## 1. Hours to seconds

Read hours0..100. Use a named constant to output total seconds.

**Sample:** Input2 ->7200

## 2. Three-factor product

Read a,b,c in [0,10000]. Output their product without int overflow.

**Sample:** Input10000 10000 10000 ->1000000000000

## 3. Fractional half

Read integer x in [-100,100]. Output x/2 to two decimals.

**Sample:** Input3 ->1.50

## 4. Truncation study

Read double x in [-100,100]. Print its conversion to int. Test both signs.

**Sample:** Input-2.8 ->-2

## 5. Two-character badge

Read two non-whitespace characters. Print them separated by a hyphen.

**Sample:** Input A Z ->A-Z

## 6. Same display, different types

No input. Print the character literal '8' and integer literal 8 on separate lines. Explain why their types differ even though their display is the same.

**Sample:** 8 / 8

## 7. Scope prediction

Create an outer x=3 and an inner x=8. Print inner x, then outer x. Explain why the second is unchanged.

**Sample:** 8 / 3

## 8. Exact amount addition

Read two nonnegative amounts, each as whole units<=1000 and cents0..99. Output their total cents.

**Sample:** Input1 75 2 50 ->425

