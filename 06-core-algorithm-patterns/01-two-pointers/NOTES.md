# Two pointers: understand the state

A pointer is an index moving monotonically through input. Start with a quadratic pair scan, then ask what ordering lets you discard a whole family of pairs. Opposite pointers need sorted values or a geometric dominance argument; a write pointer instead maintains a completed output prefix. Do not sort a problem whose answer depends on original order.

For sorted two-sum, if a[left]+a[right] is too small, every pair using that left endpoint and a no-larger right endpoint is too small. Only then is advancing left justified. For compaction, indices before write contain exactly the retained values from processed input, in original order. Read a value before overwriting its position.

Core:01-03,06,08,10. Reinforcement:04,09,12. Challenge:05,07,11. Read 03 before 04/05;06 before 07. The container proof discards the shorter wall because narrowing width without increasing that limiting wall cannot improve area. Water trapping additionally needs accumulated wall maxima. Sorted squares fills from the back because largest magnitude is at one of the two ends.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

