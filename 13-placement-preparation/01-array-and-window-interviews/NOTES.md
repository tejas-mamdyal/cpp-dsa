# Mixed arrays,intervals and windows: reasoning before code

Read the statement without the filename first. Identify whether order,signs,duplicates and empty selections matter. A quadratic enumeration is a useful oracle;hashing trades expected lookup cost for storage,sorting changes index order,and sliding windows require a monotone validity condition. Interval endpoint conventions decide whether touching meetings conflict. For binary partition problems,prove why moving a cut discards an impossible half. The last exercises mix several patterns;record why the tempting alternative fails under the given constraints.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

