# Independent parsing practice

Use standard streams and strings. Put all code in one .cpp file; no custom header
is needed. Define malformed-input behavior and test it before adding calculations.

1. **Pipe-separated integers:** read `4|5|-2` and print `4 5 -2`. Reject empty
   fields and a trailing pipe. Change only the delimiter policy from the comma lesson.
2. **Decimal values on a line:** read finite doubles in[-1000,1000] and print their
   mean to two decimals; an empty line prints no data. `1.5 2.5` ->`2.00`.
3. **N full names:** read n0..10, then n full lines, preserving intentionally blank
   names as empty records. `2` followed by `Ada Lovelace` and an empty line produces
   two records. Explain why ws would lose the blank record.
4. **Name:score:** read exactly two fields with score0..100. `Ada:90` ->`Ada | 90`.
   Reject a missing name, an extra colon and a partially numeric score.
5. **T count-prefixed lists:** each test case supplies n0..100 then n ints in[-1000,1000].
   Print the sum per case. `2 3 1 2 3 0` ->`6` then`0`.
6. **Coordinate text:** read one line `(3,-2)` and print `3 -2`. Check parentheses,
   comma and complete consumption. Two ordinary int variables are enough.
7. **Optional final delimiter:** deliberately accept one trailing comma in numeric
   lists, while still rejecting consecutive commas. `1,2,` ->`1 2`; `1,,` is invalid.
8. **Blank line terminator:** count nonempty data lines until an exact empty line
   or EOF. A line containing spaces is data. `hello` then a blank line ->`1`.
9. **Text setting:** read `title=My first project`; print `My first project`.
   Split at the first equals sign and preserve the remaining text, including spaces.
10. **Escaped quote:** read a name such as `"Ada \"Ace\""` with std::quoted and
    print `Ada "Ace"`. Test both missing closing quotes and an ordinary unquoted name.
11. **Column total:** read a matrix with dimensions1..10 and values[-1000,1000],
    then a valid column index; print that column's sum. Test a nonsquare matrix.
12. **Boundary-policy comparison:** compare fixed-count extraction with strict
    complete-line parsing on `1 2 3junk`. Explain which characters remain unread,
    whether each stated contract permits them, and how to reject all extra text.

