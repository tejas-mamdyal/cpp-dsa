# Reciprocal links endpoints and identity: notes

Every adjacent next/prev pair is reciprocal;head.prev and tail.next are null. Traversing backward should equal the reversed forward sequence. Known-node erasure is constant-time,but finding a target by position/key still costs traversal. Borrowed targets must belong to this owner.

## Worked reasoning

### A noncopyable doubly linked owner

CONTRACT: Front/back insertion and forward/backward traversal. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Update both directions and both endpoints when starting an empty list.

TRACE: front2,front1,back3 ->1,2,3 and reverse3,2,1.

CORRECTNESS: Adjacent next/prev links remain reciprocal and head.prev/tail.next are null.

COST: O(1) endpoint insertion,O(n) traversal/cleanup.

PITFALL: An owning raw-pointer class must disable shallow copies.

### Deleting endpoints must clear the opposite link

CONTRACT: Known head/tail; pop returns false for empty. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Use the shared unlink rule, updating neighbors before deletion.

TRACE: 1,2 ->pop front gives2 with prev null ->pop back gives empty.

CORRECTNESS: Surviving endpoints no longer refer to the deleted node; singleton removal clears both.

COST: O(1) erasure,O(1) working space.

PITFALL: A stale tail after the last deletion causes later use-after-free.

### Insert before a known valid observer

CONTRACT: Target belongs to the chain; null is rejected. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Wire the new node between target.prev and target.

TRACE: 1,3 insert2 before3 ->1,2,3.

CORRECTNESS: Both neighboring directions are updated before the new node becomes part of traversal.

COST: O(1) insertion given target,plus one node.

PITFALL: A foreign pointer is outside the API contract.

### Erase an interior node without predecessor search

CONTRACT: The supplied nonnull node belongs to this list. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: prev and next directly identify the two affected neighbors.

TRACE: 1,2,3 erase observer2 ->1,3.

CORRECTNESS: Reconnecting both directions bypasses exactly the victim.

COST: O(1) given-node deletion,O(1) auxiliary space.

PITFALL: The erased observer must never be dereferenced afterward.

### Reverse both directions and exchange endpoints

CONTRACT: Mutable head/tail. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Swap next/prev for every node while following saved old-next links.

TRACE: 1<->2<->3 becomes3<->2<->1.

CORRECTNESS: Every original edge reverses direction; swapping endpoints restores the public head/tail meaning.

COST: O(n) time,O(1) extra space.

PITFALL: Following current.next after swapping would walk the wrong direction.

### Locate a position then update reciprocal links

CONTRACT: Sorted list; insert after equal values. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Walk to first greater key; insert before it or append at tail.

TRACE: 1,3 insert2 ->1,2,3.

CORRECTNESS: Search establishes ordered neighbors; pointer wiring preserves reciprocal links.

COST: O(n) search,O(1) linking and extra state.

PITFALL: Empty and after-tail insertion need both endpoint updates.

### Remove later duplicates while preserving first nodes

CONTRACT: Any acyclic int chain. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: A hash set identifies repeated values; save next before unlink/delete.

TRACE: 2,1,2,3,1 ->2,1,3.

CORRECTNESS: Only the first occurrence of each key is retained and all removed nodes are reclaimed.

COST: Expected O(n) time,O(u) set space; worst hashing can be quadratic.

PITFALL: Advance using the saved next, not a deleted node.

### Move a node without changing its identity

CONTRACT: Known node belongs to nonempty chain. Chains are acyclic and uniquely owned; tail is an observer.

IDEA AND STATE: Detach its existing links, then attach it before the old head.

TRACE: 1,2,3 move observer3 to front ->3,1,2.

CORRECTNESS: The same allocation is relinked; all other nodes keep their relative order.

COST: O(1) time and space with known node/endpoints.

PITFALL: This is the list mechanism used by later cache designs, not a reason to allocate a replacement node.


