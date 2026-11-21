# Independent practice: Matrix standard questions

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Identity product

Multiply a2x3 matrix by a3x3 identity.

Example: result equals the original2x3 matrix.

## 2. Rectangular rotation

Rotate a2x3 matrix clockwise.

Example: [1,2,3;4,5,6] ->[4,1;5,2;6,3].

## 3. Counterclockwise rotation

Map each cell to its counterclockwise destination.

Example: [1,2;3,4] ->[2,4;1,3].

## 4. Symmetry

Check whether a square matrix equals its transpose.

Example: [1,2;2,3] ->true.

## 5. Boundary sum

Count each border cell exactly once.

Example: [1,2,3;4,5,6] ->21.

## 6. Spiral edge cases

Trace1x1,1x4,4x1 and an empty matrix.

Example: [1,2,3,4] ->1,2,3,4.

## 7. Row with largest sum

Return the earliest row attaining the largest sum.

Example: [1,2;0,4] ->row1.

## 8. Safe multiplication bounds

Choose an accumulator for up to100 products of values<=1000000.

Example: sum can reach100000000000000.


