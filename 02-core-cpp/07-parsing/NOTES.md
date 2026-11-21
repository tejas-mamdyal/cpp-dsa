# Input without unnecessary machinery

## Choose the input boundary first

If a problem asks for three numbers, `cin >> first >> second >> third` is enough.
Formatted numeric extraction skips spaces, tabs and newlines. Do not split strings
yourself just to read ordinary whitespace-separated values.

If a field is a whole name or sentence, use getline. If you need to parse the contents
of that line again, construct an istringstream from it. The stream holds a reading
position and supports the same >> interface as cin. Include sstream explicitly.

## Stream failure and exact fields

`if (!(stream >> value))` catches a missing/malformed int and an out-of-range value.
Extraction may stop at the first character that does not belong to the number:
reading an int from `12abc` can first obtain12. Strict fields must check that no
non-whitespace character remains. The comma example therefore attempts an extra
char after reading its integer. If that succeeds, reject the field.

When reading a variable-length numeric line, skip whitespace and test eof BEFORE
attempting the next number. If the attempted number then fails, reject it even
when eof is also set: otherwise an overflowing final token could be mistaken for
normal end of input. This is why `while (stream >> value); if (!stream.eof())...`
alone is not a complete overflow check.

## Whitespace and full lines

After >>, a newline may still be waiting. `getline(cin >> ws,name)` skips leading
whitespace, including blank lines, then reads the name. Use it only when skipping
those blanks is the intended policy. To preserve blank lines, discard only the
remainder of the numeric line first, then call getline normally; the earlier
input/types example demonstrates ignore with a newline limit.

## Delimiters and punctuation

`getline(fields,field,',')` reads until a comma instead of a newline. Consecutive
commas create an empty field, which numeric extraction rejects. A final comma
needs explicit checking because getline at EOF does not yield another empty field.
A trailing field containing only spaces is also rejected by its numeric stream.

For a bracketed list, do not simply delete every punctuation character: that can
silently accept `[1 2]` or missing brackets. Read/check each expected separator.
peek looks ahead without consuming a character; get consumes the character seen.

## Text fields, quotes and settings

find returns the delimiter position, or string::npos if absent. substr(start,length)
copies a portion; substr(start) copies the suffix. These operations are sufficient
for a simple key=value record; no regular expression or map is needed for one record.

std::quoted from iomanip reads text enclosed by quotes, including spaces. Its
default escape character is backslash. For example a quoted name containing
`\"` produces a literal quote in the extracted name. It also accepts an unquoted
single word. This is a quoted-record exercise, not a general quoted-CSV implementation.

## Keep each example focused

The comma example uses only main, strings, vectors and string streams. The sorting
application counts directly into its map instead of storing all numbers twice.
There are no local-header dependencies, pointer conversions, custom error types,
parser classes or reusable framework layers to understand before the input format.
Named helper functions are useful when they express an actual subproblem; a separate
file is useful when multi-file organization itself is the lesson.
