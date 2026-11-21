# Checkpoint: Matrix standard questions

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Identity product:** Multiply a2x3 matrix by a3x3 identity. State the result for result equals the original2x3 matrix, then add a different test.

2. **Counterclockwise rotation:** Map each cell to its counterclockwise destination. State the result for [1,2;3,4] ->[2,4;1,3], then add a different test.

3. **Spiral edge cases:** Trace1x1,1x4,4x1 and an empty matrix. State the result for [1,2,3,4] ->1,2,3,4, then add a different test.

4. **Safe multiplication bounds:** Choose an accumulator for up to100 products of values<=1000000. State the result for sum can reach100000000000000, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

