# Prefix, suffix and difference arrays: understand the state

Define prefix[0]=0 and prefix[i+1]=prefix[i]+a[i]. Sum on[left, right) equals prefix[right]-prefix[left], including empty ranges. This costs O(n) storage and gives O(1) static queries. Updates require rebuilding; dynamic range structures belong to Phase 8.

For signed target sums, prefix[end]-prefix[start]=target. Store frequencies to count, earliest positions to maximize length, and indices to reconstruct. Seed the empty prefix and query before inserting current state. Negative C++ remainders need normalization into[0, k).

Inclusive range addition[l, r] changes diff[l]+=delta, diff[r+1]-=delta; integration reconstructs values. Half-open ranges instead cancel at r. In 2D, four signed corners mark a rectangle; prefix inclusion-exclusion removes the overlap subtracted twice. Draw a small grid before deriving formulas.

Suffix maxima summarize future candidates. Product-except-self combines products strictly before and after i without division, so zeros are supported. XOR cancels because x^x=0. A 26-bit parity mask answers palindrome-permutation queries, not whether the original substring is a palindrome.

Core:01-06,08-11. Reinforcement:07,13,15. Challenge:12,14,16. Read 01 before prefix queries,09 and 11 before 12,13 and Phase 3 bits before 16. In 14, best-left stores the largest completed eligible window; try both width orders, and never initialize a signed optimum to zero.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

