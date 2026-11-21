# Checkpoint: Interfaces inheritance and dispatch

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Perimeter interface:** Add perimeter to two concrete shapes. State the result for 3x4 rectangle ->14; square5 ->20, then add a different test.

2. **Slicing repair:** Change a function parameter from Base value to const Base&. State the result for derived dispatch survives the call, then add a different test.

3. **Protected versus private:** Replace protected raw state with a protected const accessor. State the result for derived reads through an invariant-preserving method, then add a different test.

4. **Composition choice:** Explain whether Student has-an Address or is-an Address. State the result for composition is appropriate, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

