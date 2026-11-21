# Errors,modern vocabulary,tests and measurement: reasoning before code

Choose error vocabulary deliberately:optional means expected absence,variant can carry distinct success/error payloads,and exceptions express failures crossing call layers. Validate complete text rather than accepting a numeric prefix silently. string_view and span-like pointer ranges borrow storage. C++17 structured bindings unpack values;variant visitation dispatches by the active alternative. A property test checks an invariant across many inputs;an oracle should be independently derived. A benchmark must verify equivalent outputs,prevent unused work from disappearing,report the workload/compiler and separate construction from queries. Timing is evidence for that machine,not a proof of asymptotic complexity. The project README includes debugger and sanitizer commands with platform limitations.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

