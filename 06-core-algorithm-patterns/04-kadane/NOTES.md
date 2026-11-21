# Kadane and interval optimization: understand the state

Define ending[i] as the best nonempty sum ending exactly at i, and best[i] as the best anywhere through i. Every ending interval starts here or extends one ending at i-1. Thus ending=max(a[i], oldEnding+a[i]), then best=max(oldBest, ending). Initialize from an actual element so all-negative input remains nonempty.

A recurrence describes exhaustive choices; general DP machinery is deferred to Phase 7. Reconstruction adds a start index and a tie policy. Restart only when the carried sum is negative to retain earlier starts on ties. A circular answer is ordinary or the complement of a minimum middle; guard all-negative data to prevent removing the entire array.

Maximum products need both extrema because a negative multiplier reverses order. Read both old extrema before writing either new one. Compress each row band to column sums for rectangles. For length>=k, minimize only prefixes that already yield sufficient length. One deletion joins a best left-ending and right-starting interval, or deletes nothing.

Core:01-04,07. Reinforcement:05,08. Challenge:06. Read 01 before every variant,03 before 04, and prefix lesson 01 before 07. Bounds on product inputs and matrix dimensions are part of the contract, not optional performance advice.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

