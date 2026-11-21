# Understanding this unit

A type determines a value's representation and valid operations. int and long
long store whole numbers in finite ranges; double approximates real numbers;
char stores a character code; bool represents true/false. Declarations introduce
names; initialization gives first values; assignment updates existing objects.
const forbids reassignment. sizeof reports storage bytes; numeric_limits reports
portable bounds. Conversions can lose fractions or range. Precision and formatting
change what is printed, not the stored mathematical accuracy.

Syntax preview used in this unit: == asks whether values are equal; >= asks whether
the left is at least the right. Both produce bool. static_cast<T>(expression)
explicitly converts to type T. std::fixed and std::setprecision come from output
formatting; include iomanip for setprecision. Use the introductory declarations
here before revisiting comparison logic in unit03.

## Work a trace before running

| Expression | Type/result |
|---|---|
|7/2|int3|
|static_cast<double>(7)/2|double3.5|
|static_cast<int>(-3.9)|int-3|

A type affects computation; a formatting manipulator affects display.

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

`1LL` is a long long literal, so1LL*a*b widens arithmetic before multiplication.
`numeric_limits<int>` is the library information interface for int; its `::min()`
and `::max()` are zero-argument calls returning bounds, not two-value min/max helpers.
The angle brackets select the type being queried; writing template implementations comes later.

Scientific notation such as1e6 means1 times10 to the sixth power, or1000000.
In C++ that notation is floating-point; use an integer literal when the value
should be an integer. This also explains abbreviated limits in later comments.

