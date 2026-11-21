# Reasoning before code

A binary tree has one root and ordered left/right children. Each nonroot node has one parent: no cycles or shared child ownership. unique_ptr owns a node; get() borrows it. Never delete a borrowed pointer, retain it past erasure, or turn it into a second owner. Moving a unique_ptr transfers ownership. Automatic destruction follows owned children; explicit cleanup illustrates postorder.

The summary lesson measures height in edges: empty -1, leaf 0. Preorder visits before children, inorder between them, postorder after them. Iterative stacks hold pending recursive work. A FIFO queue processes increasing depth; freeze queue size for one row. Zigzag reverses saved rows without changing traversal semantics.

Null tokens make preorder shape encoding unambiguous, with 2n+1 tokens. optional<Tree> separates malformed input from a valid empty owned tree. Reject missing and trailing tokens. Unique-value preorder/inorder and postorder/inorder construction split disjoint inorder intervals; duplicates are rejected rather than guessed.

Core:01-09,11-13,17-20. Reinforcement:10,16. Challenge:14-15. Read ownership before pointer traversal, recursive traversal before iterative forms, and 11/12 before 13. Cloning creates new owners; inversion swaps existing owners. Arbitrary trees have no BST ordering guarantee.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

