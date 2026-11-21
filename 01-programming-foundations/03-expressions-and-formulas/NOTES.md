# Understanding this unit

An expression computes a value. Arithmetic has precedence: * / % before + -;
parentheses make grouping explicit. Assignment stores a value; compound assignment
updates it. Integer division truncates toward zero and remainder satisfies
a == (a/b)*b + a%b. Comparisons produce bool. &&, || and ! combine truth values;
&& and || short-circuit. Fixed input bounds below keep arithmetic representable.

## Work a trace before running

| total seconds | hours | remaining | minutes | seconds |
|---:|---:|---:|---:|---:|
|3661|1|61|1|1|

Remainder removes complete groups before the next decomposition.

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

