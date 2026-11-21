# Checkpoint: Ownership lifetime and RAII

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Early return cleanup:** Demonstrate a destructor on an early-return path. State the result for counter returns to0 on both paths, then add a different test.

2. **Borrow without transfer:** Write a helper reading an owned int through const int*. State the result for owner remains engaged after call, then add a different test.

3. **Cycle diagnosis:** Draw two shared owners pointing to each other and repair one edge. State the result for one weak link permits reclamation, then add a different test.

4. **Cast safety:** Classify casting a mutable view versus writing an actually const int. State the result for only the originally mutable case can be writable, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

