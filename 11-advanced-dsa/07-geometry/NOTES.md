# Exact predicates,spatial search and geometric sweeps: reasoning before code

For integer coordinates use orientation signs instead of slopes:vertical lines then need no special division. Define boundary behavior before intersection or containment. Use long long for products and prove coordinate bounds. Convex hull removes interior collinear points;degenerate sets may return0,1 or2 vertices. Divide-and-conquer closest pair sorts by x once and merges by y,then checks a narrow strip. Rotating calipers advance antipodal support vertices on a convex hull. Rectangle union integrates covered y-length across x-event strips;compressed coordinate gaps keep their original physical lengths. Floating line intersection is approximate and needs a stated tolerance.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

