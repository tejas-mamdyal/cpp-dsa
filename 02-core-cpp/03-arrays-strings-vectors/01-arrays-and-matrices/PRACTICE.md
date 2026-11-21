# Independent array/matrix practice

Use only Phase1 plus this unit; no pointers or vectors. One-dimensional capacity10,
matrix capacity4x4, values[-1000,1000] unless specified. Reject invalid input with
an error and exit1. All indices are zero-based. Attempt before reading HINTS.md.
Each problem needs normal, smallest-legal and adversarial tests.

## 1. Last occurrence

Read n0..10, n values and a target. Print its last index or-1. Sample:
`4 7 2 7 9 7` -> `2`. Empty input sequence is permitted.

## 2. Count occurrences

Read n0..10, n values and a target. Print the number of matches. Sample:
`4 2 2 1 2 2` -> `3`. Empty input produces0.

## 3. Copy and change

Read n1..10 and n values. Copy into a second array; add1 to the first copied
element. Print copy then original on separate lines. Sample `2 4 5` -> `5 5`
then `4 5`. The copy's first value may be1001 after the update.

## 4. Above the mean

Read n1..10 and n values. Print the indices whose values exceed the mean, in
order, or an empty line. Sample `3 1 2 6` -> `2`. Avoid truncating the mean.

## 5. Compare sequences

Read n0..10, n values, m0..10 and m values. Print equal only if lengths and all
corresponding values agree; otherwise different. Sample `2 1 2 2 1 2` -> `equal`.

## 6. Remove the first matching value

Read n0..10, n values and a target. Remove its first occurrence using a shift;
if absent leave the sequence unchanged. Print the result. Sample `4 2 1 2 3 2`
-> `1 2 3`. Empty input produces an empty line.

## 7. Append until full

Read n0..10 and its values, then k0..10 and k further values. Reject if n+k>10;
otherwise append and print. Sample `2 1 2 2 3 4` -> `1 2 3 4`.

## 8. Matrix extrema

Read rows,columns1..4 and all values. Print maximum followed by its first row and
column in row-first order. Sample `2 2 -4 -1 -1 -8` -> `-1 0 1`.

## 9. Row with largest sum

Read a matrix and print its first maximum-sum row index and sum. Sample:
`2 2 -4 -1 -2 -1` -> `1 -3`. Do not assume a row sum is nonnegative.

## 10. Symmetric square

Read an n-by-n matrix, n1..4 (input n then n*n values). Print symmetric if each
matrix[r][c] equals matrix[c][r], otherwise asymmetric. Sample `2 1 3 3 2`
-> `symmetric`. A1x1 matrix is symmetric.

## 11. Matrix border sum

Read rows,columns1..4 and all values. Sum cells on the outer border, each once.
Sample `2 3 1 2 3 4 5 6` -> `21`; sample `1 1 7` -> `7`.

## 12. Flattened index lookup

Read a matrix and a linear position0..rows*columns-1. Print its logical row,
column and value using row-major active dimensions. Sample:
`2 3 1 2 3 4 5 6 4` -> `1 1 5`. Reject an invalid linear position.

