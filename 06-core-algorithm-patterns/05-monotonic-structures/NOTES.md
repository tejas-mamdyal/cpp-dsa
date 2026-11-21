# Monotonic stacks and deques: understand the state

A monotonic structure stores undominated candidates. State what an index represents, why a new value makes an old one useless, and how indices expire. A nested while loop is linear when every index is pushed once and popped at most once: charge each pop to its unique push. This is aggregate amortized analysis, not a constant bound for each iteration.

Next/previous queries depend on direction and strictness. For histogram area, a popped bar spans between the remaining stack top and current index, exclusive. The zero sentinel flushes but must never be indexed as a real bar. For contribution counting, previous strictly smaller plus next smaller-or-equal assigns equal minima to their rightmost occurrence, so every interval has exactly one owner.

A deque supports front expiry and back dominance. Window maxima discard old indices at the front and no-larger values at the back. Two deques maintain max-min, whose validity survives left removals even on signed data. For shortest signed target sums, store increasing prefixes: a later no-larger prefix gives a shorter, no-worse future interval. Resolve valid fronts permanently because future endpoints can only lengthen those particular intervals.

Core:01-03,05-07,12. Reinforcement:04,08,09,13. Challenge:10,11,14. Read 01 before 04-06,07 before 08,10 before 11, and prefix 01 plus window 15 before 14. Vector-as-stack uses push_back/back/pop_back already taught in Phase 2; std:: deque supplies both ends.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

