# Phase 4 final assessment

Allow 150 minutes. Close solutions and hints. Use C++17 and your compiler. Inputs have at most1000 elements with magnitudes at most1000000 unless narrowed. Use long long accumulation. Total80 points;pass64 with no zero for reasoning on an implemented task.

1. **15 points:** return earliest longest signed zero-sum half-open range or absence. Explain why a nonnegative budget window is unsuitable. Include empty and no-answer tests.
2. **15 points:** return shortest signed nonempty range reaching a positive target. Supply a quadratic oracle and compare all vectors[-1,0,1] through length5 for targets1..3.
3. **15 points:** split nonnegative ordered tasks into exactly k nonempty groups, minimizing largest sum. Return absence for invalid k and an actual partition for valid input. Prove predicate and monotonicity separately.
4. **15 points:** return maximum rectangle under a histogram; include a repeated-height counterexample for incorrect strictness or width. Compare all heights0..2 through length5 with a baseline.
5. **10 points:** for half-open intervals, compute both maximum selectable count and minimum rooms. Explain why the objectives need different state and how equal-time endpoints behave.
6. **10 points:** refute earliest-start interval scheduling and largest-first coins with explicit inputs. Give the exchange argument for earliest-finish scheduling and state why the fractional density argument does not solve indivisible knapsack.

For each15-point implementation: contract2,working code5,proof4,cost2,meaningful tests2. For each10-point task: correct results or counterexamples4,reasoning4,boundary analysis2. A hardcoded sample earns no code points. If using a hint,record it and retry that task on changed data before advancing.

Review directions after submission: task1 needs earlier prefix positions;task2 needs increasing prefix dominance;task3 combines capacity search with nonnegative subdivision;task4 resolves limiting bars;task5 distinguishes selection from concurrent occupancy;task6 requires a proof or a decisive counterexample. Consult the corresponding unit hints only after scoring your own attempt.

