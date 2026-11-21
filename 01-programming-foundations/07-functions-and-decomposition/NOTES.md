# Understanding this unit

A function names a computation. Its declaration specifies return type, name and
parameter types; its body defines behavior. Calling evaluates arguments and passes
values into local parameters. return sends a result and leaves the function. void
means no returned value. Parameters passed by value are independent copies. A local
variable exists only during its block's lifetime. A declaration (prototype) can
appear before a call while the definition appears later. Overloads share a name
but have different parameter lists. Keep calculation separate from input/output;
this makes functions easier to test and reuse. Recursion is deferred to Phase 3.

## Work a trace before running

| location | caller n | local value | returned |
|---|---:|---:|---:|
|before call|4|not created|—|
|inside increment|4|5|—|
|after return|4|gone|5|

A returned value is not an automatic assignment to the caller.

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

Cost preview for gcd: log n grows like the number of times a positive quantity
can be halved before reaching1 (16→8→4→2→1 has four halvings). Euclid shrinks
its arguments quickly; its formal logarithmic analysis belongs in the later
complexity chapter. The helper still explains each remainder update here.

