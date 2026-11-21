# Circular ownership traversal and elimination: notes

A ring has no null next edge. Keep tail and derive head=tail.next;the singleton links to itself. A do/while traverses exactly one lap by identity. Ordinary null-terminated traversal/cleanup is invalid until a ring back-edge is broken.

Append moves tail;front insertion preserves nonempty tail. Erasing a singleton clears the owner;erasing tail substitutes its predecessor. Rotation advances the logical tail without changing edges or allocations. The owner forbids shallow copying and cleanup first breaks the cycle. Josephus reclaims every victim and the final survivor;an independent recurrence checks small n,k pairs. Its simulation costs O(n*k) time and O(n) nodes.

## Worked reasoning

### Own and traverse a circular list

CONTRACT: Noncopyable owner supports append and one-lap traversal. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: The first node links to itself; later appends preserve tail.next=head.

TRACE: 1,2,3 traverses exactly1,2,3, then returns to head.

CORRECTNESS: Each append changes two links while keeping a single cycle through every node.

COST: O(1) append,O(n) traversal/cleanup,O(n) nodes.

PITFALL: Null termination is not a circular-list stopping condition; cleanup breaks the cycle first.

### Insert immediately after tail

CONTRACT: Empty and nonempty rings supported. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Insert a node before the old head without moving a nonempty tail.

TRACE: 1,2 insert0 ->0,1,2.

CORRECTNESS: tail.next selects the new head while the old head remains its successor.

COST: O(1) time/working space plus one new node.

PITFALL: Empty insertion must form a self-loop.

### Remove the head of a ring

CONTRACT: Return false for empty; singleton removal empties the owner. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Bypass tail.next or clear tail for a singleton, then delete the victim.

TRACE: 1,2 ->2 self-loop ->empty.

CORRECTNESS: Every surviving ring still begins at tail.next and contains each remaining node once.

COST: O(1) time and extra space.

PITFALL: Do not retain the old head observer after deletion.

### Erase a ring node including the tail

CONTRACT: Remove the first matching key in head order, returning false if absent. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Start predecessor at tail and stop after one complete lap.

TRACE: 1,2,3 delete3 ->tail becomes2;delete1 ->2 singleton.

CORRECTNESS: The predecessor bypasses the victim and the tail observer is replaced when necessary.

COST: O(n) time,O(1) extra space.

PITFALL: Deleting the singleton must clear tail rather than leave it dangling.

### Rotate the logical head by moving an observer

CONTRACT: Nonnegative k; empty ring unchanged. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Count nodes, reduce k modulo length, advance tail k links.

TRACE: 1,2,3 left1 ->2,3,1 with the same edges.

CORRECTNESS: Changing tail changes which node is called head without allocating or relinking.

COST: O(n+k%n) time,O(1) extra space.

PITFALL: Do not apply modulo before checking the empty ring.

### Eliminate every kth live node

CONTRACT: n,k in1..10; return1-based surviving label; invalid values yield absence. A nonempty tail observer identifies the uniquely owned ring; head=tail.next. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Move a predecessor k-1 links then unlink/delete the current victim.

TRACE: n5,k2 removes2,4,1,5 and leaves3.

CORRECTNESS: The cursor always denotes the next counting start and predecessor enables safe removal.

COST: O(n*k) simulation time,O(n) owned nodes; all are eventually deleted.

PITFALL: The final survivor is still allocated and must also be deleted.


