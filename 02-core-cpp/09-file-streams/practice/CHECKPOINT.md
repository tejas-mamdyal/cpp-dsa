# Checkpoint: Files serialization and persistence

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Count nonblank lines:** Ignore truly empty lines while counting file records. State the result for A,empty,B ->2, then add a different test.

2. **Quoted round trip:** Store a name with spaces and embedded quotes. State the result for Ada "Ace" restores exactly, then add a different test.

3. **Write failure:** Check stream state after close. State the result for a failed save is not reported as SAVED, then add a different test.

4. **Report formatting:** Print averages with fixed two decimal places. State the result for 90 ->90.00, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

