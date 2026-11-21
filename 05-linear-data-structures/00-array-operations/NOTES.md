# In-place array matrix and string operations: notes

These examples add representation tradeoffs to Phase2 operations. Capacity is not indexed element lifetime. Fixed arrays need an active count; insert shifts backward and erase shifts forward. Rotation normalizes signed k only after excluding empty size. A stable write prefix never outruns reading; three-way color partition groups values without promising stability.

Backward merging preserves unread left input. Missing-number XOR has a distinct-range precondition; a majority candidate needs verification. Square rotation composes transpose with row reversal. Zero markers record original zeros before mutation,preventing cascades. Symmetry and reshape validate shape before indexing; reshape preserves row-major order and equal cell counts. Word reversal states its single-space contract. Count output storage separately from working state.

## Worked reasoning

### Reverse in place with an interval invariant

CONTRACT: Mutable int vector.

IDEA AND STATE: Swap the unsolved endpoints and move inward.

TRACE: 1,2,3,4 ->4,3,2,1.

CORRECTNESS: Outside the active interval all elements already have their reversed positions.

COST: O(n) time,O(1) extra space.

PITFALL: Use half-open bounds to avoid empty size()-1 underflow.

### Signed right rotation with three reversals

CONTRACT: n<=1000; signed k may be negative, meaning left rotation.

IDEA AND STATE: Normalize k modulo n, reverse all, reverse the first k and then the rest.

TRACE: 1,2,3,4 right1 ->4,1,2,3;right-1 ->2,3,4,1.

CORRECTNESS: Reversing each block restores within-block order after exchanging their positions.

COST: O(n) time,O(1) auxiliary space.

PITFALL: Handle empty before modulo; normalize negative remainder.

### Distinct second maximum without a sentinel

CONTRACT: Int vector; return optional second distinct maximum.

IDEA AND STATE: Track the maximum and an optional smaller runner-up.

TRACE: 4,9,9,2 ->4;9,9 ->absence.

CORRECTNESS: After each element the state is the greatest and second-greatest distinct values seen.

COST: O(n) time,O(1) space.

PITFALL: INT_MIN may be a valid value; do not use it to mean missing.

### Manual insertion and erasure in a fixed array

CONTRACT: Capacity5 with active count0..5; validate positions.

IDEA AND STATE: Shift backward to open a slot and forward to close one.

TRACE: 1,3 insert2 at1 ->1,2,3;erase1 ->1,3.

CORRECTNESS: Shifting in the correct direction preserves unread active values.

COST: O(n) shifts,O(1) extra space.

PITFALL: Capacity is not active length; reject full insertion and invalid erase before mutation.

### Stable compaction with a write prefix

CONTRACT: Remove all selected values in place.

IDEA AND STATE: Write only retained values into an earlier prefix, then resize.

TRACE: 1,0,2,0 ->remove0 ->1,2.

CORRECTNESS: The write index never outruns reading, so unread values survive and retained order is unchanged.

COST: O(n) time,O(1) auxiliary space.

PITFALL: Shrinking inside the loop can invalidate traversal.

### Three-way partition of a restricted alphabet

CONTRACT: Values only0,1,2.

IDEA AND STATE: Maintain zeros prefix, ones region, unknown interval and twos suffix.

TRACE: 2,0,1,2,0 ->0,0,1,2,2.

CORRECTNESS: Each action moves a value to a final category and shrinks unknown positions.

COST: O(n) time,O(1) space; not stable.

PITFALL: Do not advance after swapping an unknown right-side value into the current position.

### Merge into reserved trailing slots

CONTRACT: a has m valid sorted values and n extra live slots; b has n sorted values.

IDEA AND STATE: Fill from the back so unread a values are not overwritten.

TRACE: a1,3,5,_,_,_ and b2,4,6 ->1,2,3,4,5,6.

CORRECTNESS: The greatest remaining value belongs at the last unused output position.

COST: O(m+n) time,O(1) extra space beyond provided slots.

PITFALL: Allocated capacity alone is not live indexed storage; a must have size m+n.

### Find one missing value by XOR

CONTRACT: n distinct values selected from0..n; exactly one missing.

IDEA AND STATE: XOR all indices0..n and all supplied values.

TRACE: 3,0,1 ->missing2.

CORRECTNESS: Every present number cancels its counterpart, leaving the absent one.

COST: O(n) time,O(1) space.

PITFALL: Distinctness/range are preconditions; XOR is not their validator.

### Majority candidate must be verified

CONTRACT: Return a value occurring more than n/2 times or absence.

IDEA AND STATE: Cancel unlike pairs to choose a candidate; scan again to verify.

TRACE: 2,2,1,2 ->2;1,2,3 ->absence.

CORRECTNESS: A true majority survives pair cancellation; verification rejects false candidates.

COST: O(n) time,O(1) space.

PITFALL: The candidate alone is not evidence that a majority exists.

### Rotate a square matrix without a second matrix

CONTRACT: Square matrix; empty allowed.

IDEA AND STATE: Transpose across the diagonal, then reverse each row.

TRACE: [1,2;3,4] ->transpose[1,3;2,4] ->[3,1;4,2].

CORRECTNESS: The composition maps old(row,column) to new(column,n-1-row).

COST: O(n^2) time,O(1) auxiliary space.

PITFALL: Only swap the upper triangle during transpose, or each swap is undone.

### Zero marked rows and columns with explicit marker storage

CONTRACT: Rectangular matrix; original zeros determine affected rows/columns.

IDEA AND STATE: First record zero locations, then rewrite in a separate pass.

TRACE: [1,0;3,4] ->[0,0;3,0].

CORRECTNESS: Markers depend only on original data, so newly written zeros do not cascade.

COST: O(rows*columns) time,O(rows+columns) auxiliary space.

PITFALL: Mutating while discovering zeros incorrectly propagates new marks.

### Reverse word order by reversing twice

CONTRACT: Words separated by exactly one ordinary space, no leading/trailing spaces; empty allowed.

IDEA AND STATE: Reverse all characters, then reverse each word.

TRACE: one two ->owt eno ->two one.

CORRECTNESS: The global reversal exchanges word positions; local reversals restore their spelling.

COST: O(n) time,O(1) extra space.

PITFALL: This contract does not normalize repeated whitespace.

### Compress sorted runs with counts

CONTRACT: Nondecreasing int vector.

IDEA AND STATE: Scan each maximal equal run and emit(value,count).

TRACE: 1,1,2,4,4,4 ->(1,2),(2,1),(4,3).

CORRECTNESS: Runs partition the input and each output records exactly its run length.

COST: O(n) time,O(u) output space for u distinct values.

PITFALL: An unsorted input counts adjacent runs instead of global frequency.

### Check square symmetry without constructing a transpose

CONTRACT: Square matrix; empty is symmetric.

IDEA AND STATE: Compare each upper-triangle cell with its mirrored lower-triangle cell.

TRACE: [1,2;2,3] symmetric;[1,4;2,3] not.

CORRECTNESS: Every off-diagonal pair is checked exactly once and diagonal cells match themselves.

COST: O(n^2) worst time,O(1) extra space.

PITFALL: Reject non-square shape before indexing mirrored coordinates.

### Reshape without changing row-major order

CONTRACT: Rectangular nonempty matrix,positive new dimensions,at most1000 cells; invalid shapes return absence.

IDEA AND STATE: Map each flat position to old and new row/column coordinates.

TRACE: [1,2,3;4,5,6] reshapes to[1,2;3,4;5,6].

CORRECTNESS: The same flat position denotes the same value before and after reshaping.

COST: O(cells) time and returned storage,O(1) extra working state.

PITFALL: Equal element counts are necessary; validate shapes before division/indexing.


