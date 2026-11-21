# Ownership,copy/move and exception-safe values: reasoning before code

Prefer rule of zero:standard containers and smart pointers already manage lifetime. Copy creates an independent value;move transfers resources and leaves a valid state whose specific value is usually unspecified. std::move is a cast enabling move overload resolution,not a transfer by itself. A hand-written owning type must coordinate destructor,copy constructor,copy assignment,move constructor and move assignment (rule of five). This unit gives a tiny bounded owner to study mechanics;production code should prefer vector. Copy-and-swap prepares a replacement before committing for a strong exception guarantee. noexcept move helps containers relocate efficiently. Shared ownership is different from observation:weak_ptr breaks cycles and must be locked before access.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

