# Checkpoint: References pointers and lifetime

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Swap equal values:** Swap7 and7 and explain why a temporary is still correct. State the result for 7,7 ->7,7, then add a different test.

2. **Range maximum:** Return a pointer to the first largest element, or nullptr for length0. State the result for 2,9,9 ->pointer to index1, then add a different test.

3. **Lifetime diagnosis:** Explain why returning &local is wrong and replace it with a value return. State the result for helper returns42 safely, then add a different test.

4. **Reference versus pointer const:** List which assignments compile for int* const and const int*. State the result for fixed pointer may write its int; read-only view may redirect, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

