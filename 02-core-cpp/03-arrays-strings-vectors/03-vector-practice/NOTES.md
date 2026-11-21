# Vectors and standard array questions: notes

A vector owns contiguous elements and keeps size separate from capacity. reserve requests storage without constructing additional elements; resize changes the number of live elements. A push is amortized constant-time because occasional growth is shared across many pushes. Middle insertions and erasures shift a suffix.

Copies own different elements; references borrow the same object. Reallocation invalidates all element pointers/references/iterators. Erasure invalidates those at or after the erased position. Keep identifiers or appropriate indices, then reacquire access after mutation; even an index changes meaning if earlier elements are inserted or removed.

Classic questions reinforce the representation: second-largest distinct requires an explicit absence state, stable zero movement uses a write prefix, rotation handles an empty sequence before modulo, and merging relies on already sorted input. A ragged vector of vectors must use each row length.

## Concepts in the worked programs

### 01 size capacity reserve

Reserve changes allocation capacity, resize changes the number of elements.

Trace: reserve(8) leaves size 0; resize(3,7) creates 7,7,7. Capacity describes storage; size describes live elements.

Cost: reserve/resize may take O(n) time and O(n) allocated storage. Pitfall: After reserve alone, values[0] is still out of bounds. Exact capacity growth is implementation-defined.

### 02 push pop checked access

push_back appends; pop_back removes without returning a value; at checks bounds.

Trace: empty -> 3,8 -> 3. Each operation updates only the last logical position except when growth reallocates.

Cost: Amortized O(1) push_back, O(1) pop_back, O(n) storage. Pitfall: front/back/pop_back require a nonempty vector. at throws on invalid indices; [] does not check.

### 03 insert erase by index

Implement the shift manually before learning iterator insert/erase. Index must be valid.

Trace: 1,3 -> append slot -> shift ->1,2,3; erase index1 ->1,3. Backward shifts preserve unread values on insertion; forward shifts close the erasure gap.

Cost: O(n) time per middle insertion/erasure; O(1) extra space aside from vector capacity. Pitfall: Check empty input and bounds before indexing; valid indices end at size()-1.

### 04 copy and alias

Contrast a copy, reference and const-reference view.

Trace: copy changes to 9 without changing source; alias then changes source to 7. Copy construction creates a new owned sequence; references denote the existing object.

Cost: O(n) time/storage for a copy; O(1) to create references. Pitfall: A const view does not freeze other aliases; it only forbids writes through that view.

### 05 safe invalidation

Keep a numeric index across capacity changes, then reacquire an element reference.

Trace: index1 still names the value 20 after reserve; the old pointer must not be reused. Numeric positions survive relocation if the element order and size stay unchanged.

Cost: O(n) reserve time and allocation; O(1) indexed lookup. Pitfall: Insert/erase can change positions too. A saved index is not a universal stable element identifier.

### 06 nested vectors

Create a matrix, then append a shorter row. Rows own independent vectors.

Trace: two rows of three zeros; matrix[1][2]=7; third row contains only 9. Each row is a separate vector copy, so modifying one row does not change another.

Cost: O(r*c) for a rectangular construction and storage. Pitfall: Use each row size when traversing a ragged matrix; matrix[2][1] is invalid here.

### 07 second largest distinct

Use a boolean to represent whether a second distinct value exists, not a magic sentinel.

Trace: 3,9,9,5 -> second largest5; 7,7 has no answer. largest and optional second contain the two greatest distinct values of the processed prefix.

Cost: O(n) time and O(1) extra space. Pitfall: Duplicates of the maximum are not the second-largest distinct value.

### 08 move zeros

Overwrite nonzero values in encounter order, then fill the remaining suffix with zeros.

Trace: 0,3,0,1 ->3,1,0,0. write never exceeds the read position, so unread input is not overwritten.

Cost: O(n) time in the length of the data; O(1) auxiliary space. Pitfall: Swapping every zero with the last element does not preserve nonzero order.

### 09 rotate copy

Normalize k modulo n and copy element (i+k)%n into output position i; empty input returns immediately.

Trace: 1,2,3,4 rotated left by6 ->3,4,1,2. Modulo maps every result position to exactly one source position.

Cost: O(n) time and O(n) result space. Pitfall: Never compute k%n when n is zero; this helper accepts nonnegative k.

### 10 merge sorted sequences

Advance the smaller head and append the unconsumed suffix. Inputs must be nondecreasing.

Trace: 1,3 plus2,3 ->1,2,3,3. The smallest remaining element is always one of the two current heads.

Cost: O(n+m) time and O(n+m) output storage. Pitfall: This is a traversal exercise, not a general sorting algorithm; unsorted input violates its contract.

### 11 sorted deduplication

Maintain a write prefix of distinct values, then resize to that prefix.

Trace: 1,1,2,2,3 ->1,2,3. Equal values are adjacent in sorted input, so comparing with the last retained value is sufficient.

Cost: O(n) time in the length of the data; O(1) auxiliary space. Pitfall: Without sorting first, this removes adjacent duplicates only; it does not remove separated duplicates.


