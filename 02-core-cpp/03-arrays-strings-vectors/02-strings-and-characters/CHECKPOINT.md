# Checkpoint: Strings and characters

20 points. Work without a worked solution. Score each task out of5: correct
approach2, working implementation/explanation1, boundary coverage1, clear cost/lifetime
reasoning1. Aim for16/20 and revisit any unsafe access or unexplained prerequisite.

1. **Count vowels:** For lowercase English input, return the number of a,e,i,o,u. State the result for education ->5; empty ->0, then add a different test.

2. **Last occurrence:** Return the last start of a substring or -1; allow overlapping matches. State the result for banana,ana ->3, then add a different test.

3. **Remove a selected character:** Preserve order while removing every occurrence of one character. State the result for banana,a ->bnn, then add a different test.

4. **Anagram validation:** Reject non-lowercase input before applying the 26-counter algorithm. State the result for a!,!a ->invalid, then add a different test.

Self-review: compile with warnings enabled; explain every parameter, state update,
empty-range guard and ownership relationship. A passing sample alone is insufficient.

