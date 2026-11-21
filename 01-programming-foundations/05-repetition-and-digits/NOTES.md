# Understanding this unit

for performs initialization once, checks before each iteration and updates after
the body. while checks before the body; do/while checks after it, guaranteeing one
iteration. An accumulator stores an aggregate of processed values. Write down its
initial value (0 for sum, 1 for product), invariant and progress measure. break
exits the nearest loop; continue skips to the next iteration. Bounds must guarantee
termination and representable arithmetic. Use a do/while for zero as a single digit.

## Work a trace before running

| iteration | remaining before | extracted digit | sum after |
|---:|---:|---:|---:|
|1|407|7|7|
|2|40|0|7|
|3|4|4|11|

Invariant: sum contains exactly the digits already removed. Remaining shrinks.

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

