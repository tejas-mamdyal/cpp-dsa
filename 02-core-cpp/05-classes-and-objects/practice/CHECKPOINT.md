# Checkpoint: Classes records and value semantics

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Validated rectangle:** Create a class accepting dimensions0..1000 and returning area. State the result for 3,4 ->12; negative update rejected, then add a different test.

2. **Record equality:** Compare ID and name using operator==. State the result for same fields ->true; different ID ->false, then add a different test.

3. **Scoped status:** Represent pending,accepted,rejected without magic numbers. State the result for Status::accepted is a valid named state, then add a different test.

4. **Student class:** Add checked mark replacement and derived average. State the result for 80,100 ->90; mark101 rejected, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

