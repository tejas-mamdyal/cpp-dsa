# Mixed graphs,trees and model selection: reasoning before code

Translate the objective into an explicit graph before selecting a traversal. BFS minimizes unit edges;weighted routes need a weight-aware method. Tree properties rely on connected acyclic input;directed prerequisites use indegrees rather than undirected parent rules. DSU models connectivity but does not preserve routes or solve directed cycles. Check disconnected components and isolated vertices. Tree summaries distinguish a one-branch value that can be extended by a parent from a two-branch answer finalized locally. Validate witnesses against original edges and constraints.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

