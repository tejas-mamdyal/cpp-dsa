# Hints: References pointers and lifetime

Try the problem and hand trace before reading its hint.

## 1. Swap equal values

First: identify the state and precondition.

Next: Trace each assignment; equal inputs need no special case.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 2. Optional write

First: identify the state and precondition.

Next: Check presence before dereferencing.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 3. Range maximum

First: identify the state and precondition.

Next: Update only for a strictly greater value; the caller owns the array.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 4. Two outputs

First: identify the state and precondition.

Next: Initialize from the first element, then scan.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 5. Const API

First: identify the state and precondition.

Next: Use const int* and a supplied length.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 6. Lifetime diagnosis

First: identify the state and precondition.

Next: A local ends when the function returns; do not execute a dangling access.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 7. Function selection

First: identify the state and precondition.

Next: Both functions must share an identical signature.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 8. Reference versus pointer const

First: identify the state and precondition.

Next: Separate the stored address from the addressed object.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.


