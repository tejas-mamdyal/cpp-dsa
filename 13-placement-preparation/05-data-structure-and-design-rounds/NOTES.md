# Mixed data structures,greedy choices and design rounds: reasoning before code

Derive an interface before coding a data structure. State who owns values,how ties are resolved and what happens at empty capacity. Heap problems need a precise meaning for the root;monotonic structures need a reason discarded entries will never help. Greedy proofs must justify a safe exchange or an impossible starting region. Design questions add operation sequences:compare complete returned values after every call,not only final state. The final round integrates parsing,operator precedence and a declared grammar;do not silently accept unsupported syntax.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

The LRU lesson includes both a vector reference and a list+hash implementation. List splice relinks an existing node in constant time without invalidating its iterator;the hash table retains that iterator. Eviction must erase the hash key before removing its list node. The class prohibits copying because copied iterators would still observe the original list. Compare full get results against the simple reference across mixed operation sequences.

