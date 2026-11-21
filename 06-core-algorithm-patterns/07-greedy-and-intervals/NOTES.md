# Greedy choices, intervals and sweeps: understand the state

A greedy choice needs an exchange or stays-ahead proof. Maximum meeting count, minimum rooms, and maximum covered length have different objectives. Earliest finish maximizes compatible count: replace the first optimum interval by an earlier-finishing one without reducing future room, then repeat. Earliest start fails when a long first interval blocks several short ones.

Write endpoint conventions beside each problem. Half-open meetings ending at t release a room for a start at t; closed merged intervals sharing t overlap. Train platforms deliberately use arrival-before-departure at a tie. Sweeps measure a coordinate gap using the active state before applying changes at its right boundary.

Fractional knapsack permits density exchanges because weight can be divided; indivisible knapsack is deferred to Phase 7. Coin greediness depends on denominations:4,3,1 at 6 defeats largest-first. Reachability stores a reachable prefix; minimum jumps advances complete reachability layers. Gas-station resets exclude all starts in a failed segment, and total balance decides global possibility.

Core:01-07,10-13. Reinforcement:08,09,14,15. Challenge:16. Read 01 before 02/16,03 before 04,05 before 06, and 10 before 11. Weighted scheduling needs Phase 7 DP; general shortest paths need Phase 6 graphs. The finite coin audit demonstrates evidence over tested amounts, not a universal canonical-currency proof.

Before coding, write the input domain, empty/no-answer convention, and a quadratic baseline. Draw indices on a small input and identify each variable after every iteration. Prove every discarded candidate is permanently useless. Count input, output and auxiliary storage separately. Copies consume linear storage; standard sorting also has implementation-dependent internal storage.

Source comments supply a trace for every variant. Reproduce it on paper, then try repeated values and an empty or impossible case. Do not infer a stronger contract from a passing sample.

