# Mock interview 08

Allow90 minutes:5 introductions,15 problem clarification,50 coding across three rounds,15 testing/tradeoffs,5 feedback. The interviewer may reduce implementation to two rounds and use the third as a verbal changed-constraint exercise;record which format was used.

## Round 1: P08

Modify a sequence into its next lexicographic permutation. If already greatest,reset to ascending and return false. Handle duplicates.

Follow-up:change one of signs,online updates,memory budget,duplicate policy or input scale. Explain whether the same method remains valid.

## Round 2: P20

Generate every balanced parenthesis string with n pairs once,for0<=n<=8. For n0 return the single empty sequence.

Follow-up:change one of signs,online updates,memory budget,duplicate policy or input scale. Explain whether the same method remains valid.

## Round 3: P44

Partition the full signed array into blocks of length at most k. Replace each block by copies of its maximum and maximize the resulting total. No element may be skipped.

Follow-up:change one of signs,online updates,memory budget,duplicate policy or input scale. Explain whether the same method remains valid.

## Feedback

Score100:implementation and complete result40;contract/boundaries15;correctness reasoning20;time/space10;tests10;communication5. Pass80 with no unsolved task and at least half implementation/reasoning credit per task. Supplied examples alone earn no correctness proof. Record hints;retry hinted tasks independently after a week.

Ask the candidate to defend one invariant,show a failing case for another approach,and explain a project design choice. Use the project notebook after coding.

