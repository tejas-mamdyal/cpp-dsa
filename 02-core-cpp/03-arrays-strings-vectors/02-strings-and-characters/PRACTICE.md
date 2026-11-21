# Independent practice: Strings and characters

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Count vowels

For lowercase English input, return the number of a,e,i,o,u.

Example: education ->5; empty ->0.

## 2. Normalize palindrome input

Ignore ordinary spaces and English case before checking symmetry.

Example: Never odd or even ->true.

## 3. Last occurrence

Return the last start of a substring or -1; allow overlapping matches.

Example: banana,ana ->3.

## 4. Longest run

Return the character and length of the longest adjacent run; ties choose the earliest.

Example: abbcccdd ->c,3.

## 5. String rotation

Decide whether equal-length b is a rotation of a using a+a.

Example: abcd,cdab ->true; empty,empty ->true.

## 6. Remove a selected character

Preserve order while removing every occurrence of one character.

Example: banana,a ->bnn.

## 7. Word count

Count whitespace-delimited words; punctuation belongs to words.

Example:   one  two ->2.

## 8. Anagram validation

Reject non-lowercase input before applying the 26-counter algorithm.

Example: a!,!a ->invalid.


