# Understanding this unit

Debugging starts from a reproducible input and a prediction. Distinguish compile
errors (syntax/types), link errors (missing definitions), runtime defects and logic
errors. Read the first diagnostic. Use a breakpoint to pause, Step Over for a
statement, Step Into for a function, and inspect locals and the call stack. Find
the first incorrect state, fix its cause, and rerun the failure plus normal cases.
These files contain corrected runnable programs; the exercises ask you to find faulty
snippets so deliberate mistakes never enter the normal build. assert checks a
programmer assumption and may be disabled; external validation uses normal if.

## Work a trace before running

| test | wrong int division | real division |
|---|---:|---:|
|4/2|2|2.00|
|1/4|0|0.25|

The first test hides the defect; the second distinguishes the implementations.

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

