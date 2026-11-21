# Singly linked operations and ownership transfer: notes

Head operations are constant-time;tracking tail makes append constant-time too,but tail deletion still needs its predecessor. Positional operations validate before allocation or mutation. Observers to erased nodes become invalid. Dummy nodes are automatic temporary predecessors with unused values;their next links borrow rather than recursively own.

Merge transfers disjoint input allocations into one result and nulls old owners. Split cuts one link into two disjoint owners;the output handle must start empty. Delete-given physically removes the successor and changes the supplied node value,so identity-sensitive APIs cannot treat it as ordinary erasure. Iterative reversal is constant-space;recursive reversal retains frames and must terminate the old head link. Digit-list addition borrows both inputs and allocates its own output including carry.

## Worked reasoning

### Owning singly linked list with head and tail

CONTRACT: Noncopyable owner; front/back insertion and safe front deletion. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Head owns the chain; tail observes the last node for O(1) append.

TRACE: Front2,front1,back3 ->1,2,3;drain ->both head/tail null.

CORRECTNESS: Every update preserves empty iff both endpoints are null and nonempty tail.next is null.

PITFALL: Reset tail when deleting the final node.

### Reverse links with three pointer roles

CONTRACT: Acyclic list; return the new owning head without allocating. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Save the next unprocessed node before reversing the current link.

TRACE: 1->2->3 becomes3->2->1.

CORRECTNESS: previous is the reversed processed prefix; head starts the untouched suffix.

COST: O(n) time,O(1) extra space.

PITFALL: Assign the returned head; keeping the old head loses access to the rest of the reversed chain.

### Insert before a zero-based list position

CONTRACT: Valid positions0..length; reject others without changing the chain. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Find the predecessor before allocating the new node.

TRACE: 1,3 insert2 at1 ->1,2,3.

CORRECTNESS: Only the predecessor link changes; the old suffix remains linked after the inserted node.

COST: O(position+1) time,O(1) working space plus one new node.

PITFALL: Validate first so an invalid insertion allocates nothing.

### Erase head interior and tail safely

CONTRACT: Index0..length-1; invalid index returns false without mutation. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Relink around the victim before deleting it.

TRACE: 1,2,3 erase1 ->1,3;erase0 ->3.

CORRECTNESS: All surviving nodes remain in original order and exactly one victim is reclaimed.

COST: O(index+1) time,O(1) extra space.

PITFALL: Any observer to the deleted node becomes invalid.

### Return a borrowed matching node

CONTRACT: Find first matching value; nullptr represents absence. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Walk from head and return the first equal node without allocating.

TRACE: 1,2,2 target2 returns the first2;updating it gives1,9,2.

CORRECTNESS: Every earlier node was checked and rejected, establishing first occurrence.

COST: O(n) worst search,O(1) space.

PITFALL: The returned pointer borrows its owner; never delete it separately.

### List access is traversal rather than indexing

CONTRACT: Return a const borrowed kth node or nullptr; k is zero-based. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Advance at most k links after validating nonnegative index.

TRACE: 4,7,9 kth2 ->9; kth3 absent.

CORRECTNESS: After i steps the observer denotes index i, if it exists.

COST: O(n) length and O(k+1) access,O(1) space.

PITFALL: A linked list does not offer vector-like constant-time random access.

### Erase only the first matching key

CONTRACT: Return false if absent; preserve later equal values. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Treat the head separately, then inspect predecessor.next.

TRACE: 2,1,2 erase2 ->1,2.

CORRECTNESS: The first matching node is bypassed and deleted; the unvisited suffix is unchanged.

COST: O(n) time,O(1) space.

PITFALL: Value equality does not mean all duplicate nodes should be removed.

### A stack dummy simplifies head deletion

CONTRACT: Remove every occurrence and return removed count. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: A temporary dummy borrows the head link so every victim has a predecessor.

TRACE: 2,2,1,2 ->1 and removed3.

CORRECTNESS: After a deletion the predecessor stays put to inspect the new next node; nonmatches advance it.

COST: O(n) time,O(1) extra space; removed nodes are reclaimed.

PITFALL: The dummy is automatic, its value is unused, and its destructor does not own/delete next.

### Insert after existing equal keys

CONTRACT: Input chain sorted nondecreasingly. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Find the final predecessor with value<=new key, including a dummy before head.

TRACE: 1,3,3 insert2 ->1,2,3,3.

CORRECTNESS: The new node lies between the last <= predecessor and first greater successor.

COST: O(n) time,O(1) working space plus one node.

PITFALL: A sorted-input precondition is required; this is not a sorting algorithm.

### Reclaim duplicate adjacent nodes in a sorted list

CONTRACT: Keep one node per distinct value. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: When next equals current, bypass/delete next without advancing current.

TRACE: 1,1,1,2,2 ->1,2.

CORRECTNESS: Sorted equal values are contiguous; one representative survives each run.

COST: O(n) time,O(1) space.

PITFALL: Deleting a node must not leak its successor or skip another duplicate.

### Merge by transferring existing nodes

CONTRACT: Two disjoint sorted owned chains; consume both owner pointers and return one owner. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Use a dummy/tail to attach the smaller current head.

TRACE: 1,3 and2,3 ->1,2,3,3 without allocating new data nodes.

CORRECTNESS: Each selected head is the smallest remaining value; no node belongs to two result positions.

COST: O(n+m) time,O(1) extra working space.

PITFALL: Input owners become null after transfer and must not later delete the transferred nodes.

### Split one owner into two disjoint chains

CONTRACT: Position0..length; second owner must initially be null; invalid positions leave first unchanged. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Locate the split predecessor then detach its next link.

TRACE: 1,2,3 split1 ->first1,second2,3.

CORRECTNESS: Cutting one link partitions the allocation set without duplication.

COST: O(position+1) time,O(1) extra space.

PITFALL: Overwriting an already owning second pointer would leak its old chain.

### Remove an nth-from-end node with two traversals

CONTRACT: n counts from1 at the tail; invalid n returns false. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Compute length then erase zero-based index length-n.

TRACE: 1,2,3 remove n1 ->1,2;remove n2 then deletes head.

CORRECTNESS: The nth-from-end position is exactly length-n when1<=n<=length.

COST: O(length) time for two traversals,O(1) space.

PITFALL: Two sequential linear scans are still linear; the next unit reduces to one gap-based traversal.

### Deletion with only a non-tail node observer

CONTRACT: A writable node in a live singly linked list; tail/null cannot be deleted by this method. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Copy the next value into this node and remove the physical next node.

TRACE: 1,2,3 with pointer to2 ->values1,3.

CORRECTNESS: The visible value sequence loses the requested position, although its original node identity survives.

COST: O(1) time/space.

PITFALL: This invalidates observers to the next node, not to the supplied node; it is unsuitable when identity matters.

### Recursive reversal retains pending frames

CONTRACT: Acyclic chain of at most100 nodes. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Reverse the suffix, point the old next back at head, then terminate the old head link.

TRACE: 1->2->3 ->suffix3->2,then3->2->1.

CORRECTNESS: The smaller suffix is reversed correctly; one back-link attaches the old head at its end.

COST: O(n) time,O(n) call-stack space; no new data nodes.

PITFALL: Set head.next=null or the back-link creates a cycle.

### Add numbers stored least-significant digit first

CONTRACT: Input nodes contain digits0..9; empty represents0; output is newly owned. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Add current digits and carry, emitting one result digit per step.

TRACE: 2,4,3 plus5,6,4 ->7,0,8, representing342+465=807.

CORRECTNESS: Each step fixes the next decimal digit and carries only the overflow into the next position.

COST: O(max(n,m)) time and output storage,O(1) additional state.

PITFALL: Do not mutate/delete borrowed inputs; preserve final carry.

### Sort a list by splitting and merging owned nodes

CONTRACT: Acyclic uniquely owned list,n<=1000;return its new owning head.

IDEA AND STATE: Count length,split at the midpoint,recursively sort both disjoint halves and merge their nodes.

TRACE: 3,1,2 ->halves3 and1,2 ->merged1,2,3.

CORRECTNESS: The split partitions the nodes; sorted-head merge emits the smallest remaining node each step.

COST: O(n log(n+1)) time,O(log(n+1)) recursive stack; no new data nodes.

PITFALL: The old head is not a second owner after relinking; assign the returned head and delete each final node once.

### Shared suffix intersection is identity not equality

CONTRACT: Two acyclic observed chains may share a suffix. The caller owns all allocations but must detach shared links before independently clearing prefixes.

IDEA AND STATE: Walk each observer through both chains; equal total traversed length aligns their suffix positions.

TRACE: Prefixes1,2 and3 both link to7,8;intersection is the shared7 node.

CORRECTNESS: After switching heads,both paths have equal combined length; they meet at the shared suffix or at null if disjoint.

COST: O(n+m) time,O(1) extra space.

PITFALL: Equal values do not prove shared nodes. Clearing two overlapping chains independently would double-delete the suffix.


