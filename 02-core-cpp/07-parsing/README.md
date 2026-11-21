# Parsing: choose the simplest input method

This unit has **13 standalone programs**. Each compiles on its own using standard
headers; there is no shared .hpp file. Read Phase1 input/loops and Phase2 strings
and vectors first. Pointers, conversion exceptions and include guards are not
prerequisites for these examples.

## Reading order

| Step | Program | Use it when |
|---|---|---|
|1|[Fixed whitespace fields](01_space_separated.cpp)|You know how many numbers are required|
|2|[One line of numbers](02_whitespace_line.cpp)|The number of values on a line is unknown|
|3|[Input until EOF](03_read_until_eof.cpp)|Values may span several lines/files|
|4|[Count-prefixed sequence](04_count_prefixed.cpp)|Input gives n before the values|
|5|[Numbers then a full name](05_numbers_then_full_line.cpp)|Formatted extraction is followed by getline|
|6|[Comma-separated numbers](custom_input.cpp)|Numbers are separated by commas|
|7|[Semicolon record](06_semicolon_record.cpp)|A record has fixed delimited fields|
|8|[Multiple test cases](07_multiple_test_cases.cpp)|The same input contract repeats T times|
|9|[Matrix input](08_matrix_input.cpp)|Dimensions precede rows of values|
|10|[Bracketed list](09_bracketed_list.cpp)|Punctuation such as[1,2] must be checked|
|11|[Key=value setting](10_key_value.cpp)|A delimiter separates a key and value|
|12|[Quoted text fields](11_quoted_fields.cpp)|A field contains spaces or escaped quotes|
|13|[Whole lines to a sentinel](12_lines_until_sentinel.cpp)|An exact line ends a sequence of records|

Read [NOTES.md](NOTES.md), attempt [12 practice problems](PRACTICE.md) before
[hints](HINTS.md), then take [the checkpoint](CHECKPOINT.md).

## Quick comparison

```text
Known three numbers:       12 5 8
One line, unknown count:   12 5 -8 3
Count-prefixed sequence:   4 12 5 -8 3
Comma-separated numbers:   12,5,-8,3
Fixed text record:         Ada Lovelace;CSE;2
Bracketed list:            [12, 5, -8, 3]
Quoted record:             "Ada Lovelace" "Computer Science" 20
```

The examples print normalized results without prompts. Read their contracts: some
ignore tokens after a required fixed count, while complete-line/field examples
reject trailing junk. EOF and missing-sentinel policies are explicit per program.

From the repository root:

The later [frequency-sort application](../../03-standard-library/06-stl-problem-solving/03_parsed_frequency_sort.cpp)
also contains its own short parser. A little repetition makes each teaching example
independent. Shared headers belong in lessons/projects explicitly teaching multi-file
organization, rather than being required to read three comma-separated numbers.
