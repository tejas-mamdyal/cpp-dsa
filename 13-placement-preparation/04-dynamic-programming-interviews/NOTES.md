# Derive mixed dynamic-programming states: reasoning before code

Start by saying what a state means and whether its answer is a count,boolean,optimum or witness. Derive the final decision before choosing a table order. Strictness,empty solutions and impossible states are contract decisions. Reconstruction must follow stored valid transitions;verify the witness independently. A table whose indices are items and sums has pseudo-polynomial complexity,not simply linear complexity. Interval states require shorter intervals first;string prefix states use the empty-prefix identities. The egg-drop coverage formulation changes the question rather than compressing the old table mechanically.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

