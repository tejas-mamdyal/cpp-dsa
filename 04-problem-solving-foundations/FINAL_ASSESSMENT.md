# Phase3 final assessment

80 points. Work independently;deliver complete C++17 programs with explicit
contracts,invariants,edge cases,operation counts and memory/ownership accounting.
The course content is delivered;your checkpoint scores record personal readiness.

1. **Searching and sorting (20):** implement lower/upper boundaries and two sorts
   with different tradeoffs. Explain sortedness,absence,duplicate handling,stability
   and auxiliary storage. Test with a standard-library or linear/pairwise oracle.
   Include empty,singleton,all-equal,sorted/reverse and extreme permitted keys.
2. **Array/hash decisions (20):** solve one in-place transformation and one frequency/
   lookup problem. State key-range/multiplicity assumptions,expected versus worst
   hashing costs,and why an ordered container might be required. Explain a manual
   collision/deletion/rehash trace and give a counterexample to a tempting wrong rule.
3. **Linked ownership (20):** implement validated insertion/erasure,reversal and
   either cycle removal or merge/split transfer. Cover empty/singleton/head/tail,
   rejected indices,copy policy,observer invalidation and complete cleanup. Explain
   why shared-suffix intersection is observation,not two independent owning chains.
4. **Stacks queues and toolkit (20):** build a bounded stack and ring queue,then
   integrate them with a list CLI. Demonstrate underflow/overflow,wraparound,reset,
   invalid commands and independent mixed-operation model checks. Compare FIFO/LIFO
   and amortized two-stack queue behavior. Use the project rubric for a deeper review.

Each task:correct implementation8,correctness/invariant4,boundary tests4,and cost/
ownership explanation4. Aim for64/80 and at least12 in every task. Do not execute
invalid memory access or infinite loops to obtain a counterexample. Keep teaching
assertions enabled and use ordinary validation for untrusted input.

Reference material:the14 unit guides and [toolkit project](projects/README.md).
Consult only after an independent attempt. Explain where formal reasoning goes
beyond the bounded test oracle. Proceed to Phase4 only after repairing weak areas.

