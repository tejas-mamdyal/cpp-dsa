# Sequences utilities and iterator contracts: notes

Select a container from the operations needed, not familiarity alone. vector is contiguous and supports constant-time indexing; array has a fixed extent; deque supports both ends; list offers stable node positions for unaffected elements; forward_list uses predecessor-based operations. Iterators describe half-open ranges and do not all support arithmetic.

Vector insertion may reallocate and invalidate all iterators. Erasure invalidates at/after the erased position; use the returned iterator. list insertion preserves existing iterators; erasure invalidates only erased nodes. Deque end insertion invalidates iterators but preserves references to existing elements, while middle insertion/erasure has stronger invalidation. forward_list has forward traversal and no size member.

pair/tuple group fields, optional expresses absence and variant expresses one active alternative. These are representation choices with explicit access rules. Prefer const iteration for observation and use reverse iterators only after understanding their sentinels.

## Concepts in the worked programs

### 01 forward list

Use before_begin and insert_after/erase_after on a singly linked standard container.

Trace: 1,3 -> insert2 after1 ->1,2,3 ->erase2 ->1,3. A predecessor iterator identifies the link being changed.

Cost: O(1) insert/erase with a known predecessor; O(n) to find it. Pitfall: forward_list has no random access or size member. end cannot be dereferenced.

### 02 iterator categories

Vector iterators support addition/subtraction; list iterators require stepping with advance/distance.

Trace: vector begin+2 reads30; list advanced2 also reads30. Both ranges are half-open, but only random-access iterators support arithmetic.

Cost: Vector jumps/distance O(1); list advance/distance O(n). Pitfall: Do not write list.begin()+2; container interfaces reveal different traversal costs.

### 03 erase iterator loop

Use the iterator returned by erase instead of incrementing a destroyed iterator.

Trace: 1,2,4,3 -> remove evens ->1,3. erase returns the next valid position, including end when the tail is removed.

Cost: O(n^2) worst case for repeated vector erasures; O(1) extra space. Pitfall: The later erase-remove idiom avoids repeated shifts; this lesson focuses on safe iterator control flow.

### 04 reverse and const iterators

rbegin starts at the last element; cbegin disallows mutation through its iterator.

Trace: reverse copy of1,2,3 is3,2,1. Reverse iterator increments move toward the original range beginning.

Cost: O(n) time and O(n) result storage. Pitfall: rend is a sentinel, not a dereferenceable element. Reverse base() points one position after the element represented.

### 05 optional variant tuple

A tuple groups fields, optional expresses absence, variant holds one of several types.

Trace: tuple score90, optional empty fallback-1, variant string Ada. Each type makes the result shape explicit instead of encoding it in a sentinel.

Cost: O(n) for stored string copies, O(1) bounded tags/handles. Pitfall: get of the wrong variant alternative throws; inspect the active alternative first.

### 06 vector iterator insert

Use vector insert/erase after the iterator introduction; capture returned iterators.

Trace: 1,3 ->insert2 ->1,2,3 ->erase2 ->1,3. The returned iterator is valid after that particular modification and identifies the changed position.

Cost: O(n) shifts per middle insert/erase, O(n) vector storage. Pitfall: Insertion can invalidate all iterators on reallocation; do not reuse earlier iterators.

### 07 list splice

Move one node between standard lists with compatible allocators. Existing iterators to the moved element remain valid.

Trace: move2 from1,2,3 to end of4 ->1,3 and4,2. Relinking the selected node preserves its value and identity.

Cost: O(1) single-node splice; O(n) stored nodes. Pitfall: The destination position belongs to the destination list; source and destination allocator compatibility is required.

### 08 bitset

Use bitset<8> for eight flags with checked test/set/reset/flip and population count.

Trace: 00001010 ->set0 ->00001011 ->flip1 ->00001001. Each bit position is a boolean flag; transformations modify only the selected positions.

Cost: O(B) for whole-bitset operations on B bits in a portable upper bound; O(B) storage. Pitfall: Position0 is the rightmost printed bit. Integer-to-bitset construction truncates high bits; out-of-range positional operations throw.

### 09 string view

A string_view observes existing storage and substr returns another view. Keep the owner alive and avoid reallocation.

Trace: cat viewed as cat; source[0]=C changes the view to Cat. The view stores a location and length instead of copying the owned text.

Cost: O(1) view construction/subview, O(n) string comparison; O(1) view handles. Pitfall: A view can dangle after owner destruction/reallocation. data() is not guaranteed to point to a null-terminated view-sized string.

### 10 std array fill

std::array<int,3> owns three contiguous ints and supports fill and checked access.

Trace: fill7 produces7,7,7; at1 becomes9. Unlike an adjusted raw array parameter, std::array retains its extent in its type.

Cost: O(n) fill and storage; O(1) indexed access. Pitfall: at throws for an invalid index; std::array<int,0> is legal but has no front/back element.


