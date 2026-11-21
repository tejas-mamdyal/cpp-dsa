# Checkpoint: Errors validation and stream recovery

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Optional lookup:** Return optional<int> for a missing ID. State the result for absent ID ->nullopt, then add a different test.

2. **Recover two errors:** Skip two malformed lines then read42. State the result for oops,bad,42 ->42, then add a different test.

3. **Rethrow:** Log in a handler then propagate the same exception with throw;. State the result for outer handler receives the original type, then add a different test.

4. **Commit-on-success:** Parse a record into a local candidate before changing stored data. State the result for malformed update leaves the old record unchanged, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

