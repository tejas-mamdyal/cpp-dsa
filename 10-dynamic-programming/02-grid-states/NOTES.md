# Grid,triangle and coupled-position states: reasoning before code

Write exactly which cell the state ends at or starts from. Acyclic movement permits row/column evaluation orders;blocked cells must contribute0 count rather than inherit a previous row value. Minimum cost uses an impossible positive sentinel,while maximum collection may need a negative sentinel.

Reconstruction needs a table or saved decisions;one-row compression generally loses that history. A triangle has different row widths. Falling paths use only previous-row values. Two simultaneous agents require both column positions in the state to avoid double-counting a shared cell. Adding a remainder or previous task is justified only when it changes future legal transitions.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

