# Checkpoint: Lambdas captures and comparators

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Capture prediction:** Create copied and borrowed captures, change the source twice and predict results. State the result for copy sees original; reference sees latest, then add a different test.

2. **Generic square:** Use a generic lambda for int and double squares. State the result for 3 ->9;1.5 ->2.25, then add a different test.

3. **Dangling capture:** Explain why returning [&local] from a function is unsafe. State the result for the source local has expired, then add a different test.

4. **Wrapper choice:** Explain when auto lambda is simpler than std::function. State the result for local known callable needs no type erasure, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

