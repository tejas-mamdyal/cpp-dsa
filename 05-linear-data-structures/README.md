# Linear structures: Phase3

**87 worked programs** across9 delivered units,with72 independent exercises,
notes,hints,debugging labs and checkpoints. Prerequisites:Phase3 foundations and
Phase2 pointers/classes/ownership. This chapter implements mechanisms used through
library interfaces earlier;it does not silently treat STL use as implementation.

Follow this order rather than the historical directory numbers:

1. [Array/matrix/string operations](00-array-operations/README.md):15 programs.
2. [Hash mechanisms and applications](08-hashing/README.md):10.
3. [Linked memory and ownership](01-linked-list-fundamentals/README.md):6.
4. [Singly linked lists](02-singly-linked-list/README.md):18.
5. [Fast/slow observer methods](03-fast-slow-pointers/README.md):8.
6. [Doubly linked lists](04-doubly-linked-list/README.md):8.
7. [Circular linked lists](05-circular-linked-list/README.md):6.
8. [Stacks and expressions](06-stacks/README.md):8.
9. [Queues/deques](07-queues-deques/README.md):8.

The list chapters state owners,borrowed observers,copy policy and complete cleanup.
Shared-suffix intersection explicitly separates observation from owning two chains.
Removed nodes are reclaimed;cycles are broken before acyclic cleanup;palindrome
inspection restores links. Ring implementations check full/empty/wrap transitions.

Complete [the toolkit project](../04-problem-solving-foundations/projects/README.md)
and [Phase3 assessment](../04-problem-solving-foundations/FINAL_ASSESSMENT.md).

