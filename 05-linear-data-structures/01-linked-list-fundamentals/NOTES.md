# Node observation ownership and cleanup: notes

A next pointer observes another node;it does not automatically own or delete it. Local nodes must not be passed to delete. Dynamic allocations need a single responsible owner and complete cleanup. Raw observers cannot extend lifetimes. The builder tracks tail for linear construction rather than rescanning a growing chain.

clear reads next before deleting the current node,then resets head;repeated cleanup is safe. Cycles need a different policy. Live counters provide a bounded allocation ledger,not a universal memory proof. Node destructors release only themselves;owner destructors delete iteratively. Owners forbid shallow copies. Deep cloning makes independent allocations;assigning an alias borrows the same chain. The builder cleans partial construction and rethrows allocation failure.

## Worked reasoning

### Links observe objects; ownership controls deletion

CONTRACT: Automatic nodes and borrowed next pointers. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Connect local nodes without allocating and watch their scope end.

TRACE: 10 points to20; following next reads20.

CORRECTNESS: The pointer designates the second live object; neither next link automatically deletes another object.

COST: O(1) operations and bounded automatic storage.

PITFALL: Never delete an automatic node or follow a link after its target lifetime ends.

### Allocate link traverse and release a chain

CONTRACT: Three uniquely owned dynamic nodes. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Create nodes, connect next links, then delete iteratively using a saved next position.

TRACE: 1->2->3->null becomes an empty owner after clear.

CORRECTNESS: Traversal follows one link per node; clear advances before releasing the previous node.

COST: O(n) traversal/cleanup,O(1) cleanup working state,O(n) owned nodes.

PITFALL: Deleting before reading next is a use-after-free.

### Build a list in linear time with a tail observer

CONTRACT: Input values form a new independently owned chain. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Keep a tail pointer so each append avoids rescanning the chain.

TRACE: Append1,2,3 using three constant-time link updates.

CORRECTNESS: Head stays at the first node; tail is always the last node and its next is null.

PITFALL: The tail is an observer into the same allocation set, not another owner.

### Cleanup is complete and idempotent

CONTRACT: Acyclic uniquely owned chain; clear resets the owner. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Remove one head at a time, keeping remaining nodes reachable.

TRACE: Three live nodes ->two ->one ->zero.

CORRECTNESS: Each original node is deleted once and the loop ends at null.

COST: O(n) time,O(1) auxiliary stack; no recursive destructor chain.

PITFALL: A cycle must be broken before this acyclic cleanup helper is used.

### Disable unsafe shallow ownership copying

CONTRACT: An owner class holds a raw owning head; copies are forbidden. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Destructor clears the chain; borrowed access cannot transfer deletion responsibility.

TRACE: Two pushed nodes disappear when the owning scope ends.

CORRECTNESS: Only the single owner releases its nodes, preventing two destructors deleting the same chain.

COST: Push O(1),destruction O(n); O(n) owned nodes.

PITFALL: A raw observer must not outlive its owner.

### Deep copying differs from borrowing a link

CONTRACT: Copy values into a new allocation set; a raw alias continues to observe the original. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Clone through the fixture builder and compare independent node identities.

TRACE: Original1,2 changes to9,2 through alias; clone remains1,2.

CORRECTNESS: Each copied value belongs to a new node; aliasing creates no node or new lifetime.

PITFALL: After clearing the original, its alias dangles and must not be dereferenced.


