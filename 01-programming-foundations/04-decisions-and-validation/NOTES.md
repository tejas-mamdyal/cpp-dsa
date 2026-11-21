# Understanding this unit

if executes a block only when its condition is true. else handles the alternative;
an else-if chain selects the first true branch. Nested conditions express dependent
decisions. switch selects a discrete case; break prevents fallthrough. return
leaves the current function. A stream becomes false on extraction failure: test
!(std::cin >> value) before using input. || short-circuits, so later validation
checks run only when extraction succeeded. Report invalid input to std::cerr and
return 1; normal completion returns 0. Boundary values belong in explicit tests.

## Work a trace before running

| mark | >=90 | >=75 | Selected |
|---:|---|---|---|
|75|false|true|B|

Once a branch is selected the rest of its else-if chain is skipped.

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

