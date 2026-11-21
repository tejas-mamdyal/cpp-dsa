# Understanding this unit

A program is a sequence of instructions acting on data. An algorithm describes
the steps; C++ expresses them. Source text is compiled and linked into an executable.
main is where execution starts. Braces group statements and semicolons end them.
#include makes library declarations available; std::cout sends text to output.
<< inserts output; >> extracts input. A quoted string is text; an int variable
stores a whole number. These are introduced here and studied in detail next.
The early input examples assume well-formed values in their stated domains;
validation with conditions is introduced in unit 04.

## Work a trace before running

| Step | width | height | area |
|---|---:|---:|---:|
| Read |4|3|not computed|
| Multiply |4|3|12|
| Print |4|3|12|

Output is12; source layout does not itself insert output newlines.

## Explain the reasoning

Read each source's WHY THIS WORKS section. Identify what changes at each statement
and what remains true. For a loop, explain its starting state, repetition condition,
update, invariant and termination. For fixed calculations, connect the formula to
the requested quantity and its units. A working sample alone does not prove all cases.

## Study and test

Compile one source at a time using the start guide. Enter the sample input from
Compare exact output, including spacing/newlines. Early units assume input within
the stated contract. Unit04 onward explicitly rejects malformed/out-of-range input
and returns a nonzero exit status. Unless stated otherwise, extra tokens after the
required input are ignored; menus require their quit command.

Read comments before code. Reimplement a core example without looking, change one
constraint, and explain what needs to change in the implementation. Use PRACTICE.md
for independent problems and HINTS.md only after making a written attempt.

Reaching the closing brace of main implicitly returns0; an explicit return0 is also valid. Single-statement loop/branch bodies may omit braces, but use braces when grouping multiple statements.

Chained extraction such as `std::cin >> a >> b` reads a and then b. Whitespace,
including a newline, separates numeric tokens. A space character is written `' '`;
`'\n'` is a newline character. Double quotes enclose text, single quotes one character.

Cost notation preview: O(1) means a fixed amount of work or storage as input size
grows. O(n) means work proportional to n items; O(n*n) can arise from n rows of n
items. These labels summarize growth, not execution speed; formal analysis follows later.

