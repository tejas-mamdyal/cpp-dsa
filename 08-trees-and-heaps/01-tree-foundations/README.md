# Tree ownership, construction, serialization and traversals

Phase 5 unit 5: 20 worked programs and 12 independent exercises. Complete earlier Phase 5 units first. Read [notes](NOTES.md), then sources numerically; notes identify core, reinforcement and challenge routes. Every source is standalone C++17 with embedded assertions. No input is required; success prints `checks passed`.

|Order|Worked program|
|---|---|
|01|[Build an owned binary tree and borrow nodes safely](01_manual_construction.cpp)|
|02|[Clear children before their parent](02_postorder_cleanup.cpp)|
|03|[Visit parent before its child subtrees](03_recursive_preorder.cpp)|
|04|[Visit between the ordered child subtrees](04_recursive_inorder.cpp)|
|05|[Visit parent after both child subtrees](05_recursive_postorder.cpp)|
|06|[Replace pending recursive subtrees with a stack](06_iterative_preorder.cpp)|
|07|[Keep the path whose parent visits are pending](07_iterative_inorder.cpp)|
|08|[Reverse parent-right-left to obtain left-right-parent](08_iterative_postorder.cpp)|
|09|[A queue completes one tree depth at a time](09_level_order.cpp)|
|10|[Change presentation order without changing queue semantics](10_zigzag_level_order.cpp)|
|11|[Build shape from a preorder stream with explicit nulls](11_build_preorder_nulls.cpp)|
|12|[Preserve missing children when serializing a tree](12_serialize_preorder.cpp)|
|13|[Check structure and values after encoding then decoding](13_roundtrip_serialization.cpp)|
|14|[Use the inorder root position to split unique-value traversals](14_preorder_inorder_construction.cpp)|
|15|[Consume postorder backward and build the right subtree first](15_postorder_inorder_construction.cpp)|
|16|[Copy values and shape without sharing child ownership](16_clone_owned_tree.cpp)|
|17|[Return child summaries using one explicit height convention](17_count_height_and_sum.cpp)|
|18|[Distinguish no children from a missing single child](18_count_leaves.cpp)|
|19|[Compare matching positions rather than just traversal values](19_same_tree.cpp)|
|20|[Swap owned child subtrees without copying nodes](20_invert_tree.cpp)|

Attempt [practice](PRACTICE.md) before [staged hints](HINTS.md), then complete debugging and [the checkpoint](CHECKPOINT.md). Return to [the Phase 5 plan](../../07-recursion-and-backtracking/PHASE5_PLAN.md).

