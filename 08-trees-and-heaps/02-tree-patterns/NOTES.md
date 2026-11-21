# Reasoning before code

Postorder returns child summaries. Balance returns height or invalid marker; diameter combines two heights at every path peak. Maximum path sum can score both branches locally, but an extendable return uses only one branch. Preserve a nonempty answer on all-negative trees.

Root-to-leaf routes end at leaves. Downward target paths may start at any ancestor, so prefix frequencies must be scoped to the active route and undone before siblings. LCA compares node identities, not values, and checks both targets are present. Connecting distance sums their depths below LCA.

Views need coordinates and ties. Top keeps first BFS item per column; bottom keeps last, later left-to-right arrival winning equal depths. Vertical traversal sorts(column, row, value). Boundary sides exclude leaves to avoid double output. Complete-position width counts interior missing slots; its height limit 30 prevents an unrepresentable true width. Normalization alone cannot bound a truly enormous width.

Completeness is an uninterrupted prefix of BFS slots, not balance. Flattening moves owners into a preorder chain. Child-sum checks immediate children, not whole subtree totals. Target spread introduces parent links locally and advances one queue wave per edge distance.

Core:01-09,17-18. Reinforcement:10-13,15. Challenge:14,16,19-20. Read height conventions before 02/03, postorder before 04, prefix restoration before 07, LCA before 09, and ownership transfers before 19.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

