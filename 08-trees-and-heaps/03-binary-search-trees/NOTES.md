# Reasoning before code

A strict BST orders entire subtrees and ignores duplicate insertions. Immediate child comparisons are insufficient: carry ancestor bounds or validate strict inorder order. Optional bounds leave INT_MIN and INT_MAX available as real keys. Operations take O(height), which can be O(n) in an unbalanced tree.

Deletion handles leaf, one-child and two-child cases. Move a child replacement into a temporary before destroying its parent. For two children, copy the smallest right-subtree value then delete that successor. Borrowed pointers to erased nodes expire. Floor/ceil include equality; predecessor/successor are strict. Rank is 1-based and invalid rank is absent.

An iterator stores the pending left spine between calls. Each node is pushed/popped once, so a complete traversal is linear with O(height) memory; one next call may cost O(height). Balanced rebuild extracts sorted values then chooses middles. This is a batch rebuild, not a dynamically balanced AVL or red-black tree. Merge uses distinct set-union semantics.

Core:01-08,10-12. Reinforcement:09,13-14,16. Challenge:15. Invariants precede validation/deletion; general-tree LCA precedes ordered LCA; sorted construction precedes rebalancing. Iterator borrowing requires a live unchanged tree.

Every source supplies a contract, state, hand trace, correctness, cost and pitfall. Trace a normal and boundary case before compiling. Explain returned summaries and ownership transfers. Count work buffers, call stack and output separately. Finite comparisons support proofs; they do not replace them.

