# Understanding this unit

An outer loop selects a row or group; the inner loop performs work within it.
Count actual iterations: a rectangle has rows*columns items; a triangle has
1+2+...+n. Reset per-row state inside the outer loop. Put the newline after each
completed row. Streaming algorithms process one value at a time without arrays:
maintain only the aggregates needed. This prepares you for arrays in Phase 2.

## Work a trace before running

| row | leading spaces | stars |
|---:|---:|---:|
|1|2|1|
|2|1|2|
|3|0|3|

Use two inner loops; put the newline outside both.

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

