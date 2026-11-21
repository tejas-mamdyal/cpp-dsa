# Sliding windows: understand the state

A window is a contiguous range with state updated as either end moves. Fix inclusive or half-open indices before coding. A fixed-width window adds an arriving value and removes a departing value; validate k before indexing. Signed values are fine for fixed width.

A variable window needs a monotone validity condition. For nonnegative sums, adding right cannot reduce sum and removing left cannot increase it. This justifies longest-budget and shortest-target rules. Signed values break both implications:[5,-4] is a valid budget 3 range even though[5] is too expensive. Read lesson 15 before reusing a sum-shrinking rule.

Frequency windows have a different justification: removing values cannot increase distinct count. Erase zero-frequency map entries so map size describes active distinct values. Count exactly k via atMost(k)-atMost(k-1); for each valid right endpoint, at-most counting contributes right-left+1 possible starts. Long long is necessary for the total number of ranges.

Core:01-07,11,15. Reinforcement:08,09,12-14. Challenge:10. Read 05 before 06;09 before 11. Lesson 08 recomputes a maximum over 26 counts for an exact invariant. Lesson 10 fixes a desired distinct count for each pass, then tracks how many present letters meet k; this restores a shrink condition that raw minimum frequency lacks.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

