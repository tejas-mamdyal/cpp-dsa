# Checkpoint: Ordered containers and adaptors

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Sorted unique IDs:** Deduplicate and print IDs in order. State the result for 3,1,3,2 ->1,2,3, then add a different test.

2. **Range count:** Count ordered values in inclusive[low,high]. State the result for 1,2,2,4 with2..3 ->2, then add a different test.

3. **Service simulation:** Interleave job arrivals and one-at-a-time service. State the result for add1,add2,serve,add3 ->pending2,3, then add a different test.

4. **Priority tie break:** Order jobs by priority, then earlier ID. State the result for priority5 IDs1,2 serve1 first, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

