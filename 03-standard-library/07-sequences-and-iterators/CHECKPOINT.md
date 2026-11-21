# Checkpoint: Sequences utilities and iterator contracts

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Container selection:** Choose structures for indexed scores, FIFO jobs and frequent front insertion. State the result for vector,queue,deque respectively, then add a different test.

2. **List splice:** Move a list node to another list without copying its value. State the result for move2 from1,2 into3 ->1 and3,2, then add a different test.

3. **Const iteration:** Explain why assigning through cbegin fails. State the result for reading works; writing is rejected, then add a different test.

4. **Invalidation trace:** Explain why a saved vector iterator cannot cross a forced reallocation. State the result for reacquire by valid index afterward, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

