# Observer gaps cycles and restoration: notes

Middle selection uses one-speed/two-speed observers;initial positions and guards choose the even-length policy. Nth-from-end instead maintains a fixed gap and validates it before mutation. Floyd compares identities,not values. Inside a cycle of length c,relative position advances by one modulo c until meeting.

If the prefix length is x and meeting offset y,the traveled-distance relation makes x+y a multiple of c. Reset one observer to head and move both at speed1 to find entry. One lap counts length. Breaking the entry predecessor link removes the cycle without losing nodes,including entry=head/self-loops. Palindrome checking reverses a half temporarily but restores it even on a mismatch. Odd/even grouping refers to positions,not payload parity.

## Worked reasoning

### Second middle with one-speed and two-speed observers

CONTRACT: Acyclic list; even length returns the second middle; empty returns null. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Slow advances one link and fast two.

TRACE: 1,2,3,4 ->middle3.

CORRECTNESS: When fast reaches the end, slow has traversed half as many links.

COST: O(n) time,O(1) extra space.

PITFALL: Check fast and fast.next before following two links.

### Floyd detection versus pointer-set detection

CONTRACT: Borrow a possibly cyclic chain; cleanup breaks the known fixture cycle first. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Floyd observers eventually meet in a cycle; a set detects a repeated node identity.

TRACE: 1->2->3->2 creates a cycle even when all values are distinct.

CORRECTNESS: Within a cycle the relative position advances by one modulo its length, forcing a meeting.

COST: Floyd O(n) time/O(1) space; hash expected O(n) time/O(n) space.

PITFALL: Repeated values do not imply repeated nodes; ordinary null-terminated cleanup cannot traverse a cycle.

### Reset one observer after a Floyd meeting

CONTRACT: Return cycle entry identity, or null for acyclic input. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Move one observer from head and one from meeting, both at speed1.

TRACE: 1->2->3->4->2 has entry node2, not necessarily the meeting node.

CORRECTNESS: The distance equation modulo cycle length makes both observers arrive at the entry together.

COST: O(n) time,O(1) space.

PITFALL: A meeting position is not automatically the entry; compare identities, not payloads.

### Delete nth from end with a fixed observer gap

CONTRACT: n>=1; reject invalid n before unlinking anything. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: A dummy predecessor and an n-link lead let slow stop immediately before the victim.

TRACE: 1,2,3 with n3 deletes head1.

CORRECTNESS: When fast reaches the tail, slow.next is n positions from the end.

COST: O(n) time,O(1) space.

PITFALL: An oversized gap must return failure without partially changing the list.

### Count one lap after meeting

CONTRACT: A possibly cyclic list; acyclic length answer0. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Find a meeting then walk until returning to that same node.

TRACE: Five nodes with tail->index2 have cycle length3.

CORRECTNESS: One complete lap visits each distinct cycle node once.

COST: O(n) time,O(1) space.

PITFALL: Count only cycle nodes, not the leading noncyclic prefix.

### Break the cycle without losing a node

CONTRACT: Remove a cycle if present and preserve the chain reached from its original head. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Find entry, then find its predecessor within the cycle and set that one link to null.

TRACE: 1->2->3->2 becomes1->2->3->null.

CORRECTNESS: Only the repeated back-edge is removed; every distinct reachable node stays reachable once.

COST: O(n) time,O(1) space.

PITFALL: Handle entry=head and a self-loop, not only a cycle after a prefix.

### Compare list halves and restore borrowed input

CONTRACT: Acyclic list; return a palindrome result without leaving the list reversed. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Find first-half end, reverse the second half, compare, then reverse it back on every path.

TRACE: 1,2,2,1 is true and remains1,2,2,1 afterward.

CORRECTNESS: Mirrored halves agree exactly for a palindrome; restoring links preserves the observation-only API.

COST: O(n) time,O(1) extra space.

PITFALL: Do not return immediately on a mismatch before restoring the second half.

### Group nodes by position rather than value parity

CONTRACT: Acyclic chain; odd-indexed positions1,3,5 precede2,4,6 stably. The caller owns every allocated node unless ownership is explicitly transferred. Test fixtures reclaim all nodes.

IDEA AND STATE: Two link chains grow in parallel, then the odd tail joins the even head.

TRACE: 1,2,3,4,5 ->1,3,5,2,4.

CORRECTNESS: Each original node joins exactly one chain in its original relative order.

COST: O(n) time,O(1) extra space.

PITFALL: Odd/even refers to positions, not stored integer parity.


