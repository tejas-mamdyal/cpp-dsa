# Sorting mechanisms stability and tradeoffs: notes

Sorting must preserve the input multiset as well as establish order. State mutation,stability,key-domain assumptions and memory. Selection's distant swaps can change equal-record order; strict insertion shifts preserve it. Binary insertion reduces comparisons but not shifting cost. Merge sort uses a reusable buffer; bottom-up merging removes recursive frames. Last-pivot quick sort can degrade quadratically; three-way partition improves duplicate-heavy cases without a universal guarantee.

The heap lesson locally introduces parent>=children and child indices2*i+1,2*i+2 before sorting. Bottom-up construction is linear because most nodes are near leaves. Stable counting scatters whole tagged records; signed keys need offsets. Radix requires stable digit passes and a nonnegative bounded contract. Bucket cost depends on distribution. A k-displaced heap requires that precondition. Inversions are counted during merge and checked with a quadratic oracle.

## Worked reasoning

### Bubble sort with a shrinking unsorted suffix

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Swap adjacent inversions; each pass fixes the largest remaining value. Stop after a pass without swaps.

TRACE: 3,1,2 ->1,2,3 on the first pass.

CORRECTNESS: Every comparison pushes a larger neighbor rightward; the last active position is final.

COST: O(n^2) worst, O(n) already-sorted time; O(1) extra space; stable.

PITFALL: The no-swap flag must reset on each pass.

### Insertion sort grows a sorted prefix

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Save the next value, shift strictly greater predecessors, then insert it.

TRACE: 1,4,2 ->save2,shift4 ->1,2,4.

CORRECTNESS: The prefix is sorted before insertion; shifting opens its unique stable insertion location.

COST: O(n^2) worst,O(n) best time; O(1) extra space; stable.

PITFALL: Save the value before shifts overwrite its old slot.

### Stable merge sort with one reusable buffer

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Split half-open ranges, sort halves, merge their ordered heads.

TRACE: 3,1 plus2,0 ->sorted halves1,3 and0,2 ->0,1,2,3.

CORRECTNESS: Sorted halves partition the input; the smallest remaining head is the next output.

COST: O(n log(n+1)) time,O(n) buffer plus O(log(n+1)) stack; stable.

PITFALL: Choose the left value on equality and do not allocate/copy full sub-vectors at every call.

### Compare partition sorting with bounded-value counting

CONTRACT: Small ints[-10,10];compare two different sorting mechanisms.

IDEA AND STATE: Quick sort partitions around a last pivot; counting reconstructs values by their multiplicities.

TRACE: 3,-1,3 ->counts{-1:1,3:2} ->-1,3,3.

CORRECTNESS: Partition places each chosen pivot correctly; counting emits exactly each input multiplicity in key order.

COST: Quick sort O(n^2) worst/O(n log n) average under suitable inputs, O(n) worst stack. Counting O(n+21) time,O(21) counts.

PITFALL: Last-element pivots degrade on sorted/equal input; counting assumes the stated range and does not establish record stability.

### Selection sort fixes one minimum at a time

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Find the smallest suffix value then swap it into the next position.

TRACE: 3,1,2 ->1,3,2 ->1,2,3.

CORRECTNESS: After each pass the prefix contains the smallest values in sorted order.

COST: Theta(n^2) comparisons,O(n) swaps,O(1) space; generally unstable.

PITFALL: One distant swap can reverse equal-key record order.

### Binary insertion reduces comparisons not shifts

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Find an upper insertion boundary in the sorted prefix, then shift the suffix.

TRACE: 1,4,4 inserting another4 uses the position after existing4 values.

CORRECTNESS: The binary boundary is correct for the sorted prefix; shifting preserves the remaining order.

COST: O(n log n) comparisons but O(n^2) worst moves/time; O(1) space; stable.

PITFALL: A logarithmic position search does not make linear shifting disappear.

### Bidirectional bubble passes

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Sweep right to fix a maximum, then left to fix a minimum; shrink both boundaries.

TRACE: 3,2,1 ->2,1,3 ->1,2,3.

CORRECTNESS: Each sweep settles an endpoint without disturbing already settled positions.

COST: O(n^2) worst,O(n) best time; O(1) space; stable with strict swaps.

PITFALL: Guard empty input and unsigned decrement loops carefully.

### Bottom-up merge sort removes recursive frames

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Merge sorted runs of width1,2,4,... using a buffer; n<=1000.

TRACE: Individual elements become sorted pairs then runs of4.

CORRECTNESS: At each level every run of the current width is sorted; merging creates the next level.

COST: O(n log(n+1)) time,O(n) buffer, no recursive stack; stable.

PITFALL: The final run may be shorter; clamp both middle and right boundaries.

### Three-way partition handles many equal keys

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: Maintain less-than, equal and unknown regions plus a greater suffix.

TRACE: 2,1,2,3,2 ->less1,equal2,2,2,greater3.

CORRECTNESS: Each step moves a value to its correct pivot region; only less/greater regions need recursion.

COST: O(n^2) worst,O(n log n) typical; all-equal input O(n); O(n) worst stack.

PITFALL: After swapping an unknown with the right boundary, inspect the incoming value before advancing.

### Teach the array heap invariant before heap sort

CONTRACT: Mutable vector of small ints; n<=1000. Values[-10,10] in the demonstrations.

IDEA AND STATE: A max heap has parent>=children; children of i are2*i+1 and2*i+2. Repair downward, build bottom-up, then extract the maximum to the suffix.

TRACE: 3,1,4 builds root4; swap root to final slot then repair the shorter heap.

CORRECTNESS: Bottom-up repairs make every subtree a heap. Each extracted root is the largest remaining value and enters its final position.

COST: O(n) heap construction,O(n log(n+1)) sorting,O(1) extra space; unstable.

PITFALL: The heap is a prefix, not the entire vector after extraction; later heap chapters expand this invariant.

### Count bounded nonnegative keys

CONTRACT: Mutable vector of small ints; n<=1000. Values0..100.

IDEA AND STATE: Store a frequency for every permitted value0..100, then emit the counts in ascending order.

TRACE: 3,0,3,1 ->0,1,3,3.

CORRECTNESS: Each input increments one counter and reconstruction emits exactly those multiplicities.

COST: O(n+R) time,O(R) space for R=101.

PITFALL: A huge key range can make counting impractical even for few elements.

### Stable counting sort retains record order

CONTRACT: Records have key[-3,3] and an arrival serial.

IDEA AND STATE: Prefix counts identify the first output position for each key; scatter input records left-to-right.

TRACE: key1 IDs0,2 stay in that order after sorting.

CORRECTNESS: Every key gets a disjoint output interval; advancing its position preserves equal-key arrival order.

COST: O(n+7) time,O(n+7) auxiliary space.

PITFALL: Signed keys need an offset; reconstructing only key values loses attached records.

### LSD radix sort needs stable digit passes

CONTRACT: Mutable vector of small ints; n<=1000. Values0..100.

IDEA AND STATE: Sort nonnegative ints0..9999 by units,tens,hundreds,thousands using stable counting passes.

TRACE: 21,12,11:units11,21,12; then tens11,12,21.

CORRECTNESS: After each stable pass all processed lower digits are correctly ordered within the new higher-digit groups.

COST: O(d*(n+10)) time,O(n+10) extra space for d decimal digits.

PITFALL: Negative numbers require another design; the stated upper bound also prevents exponent overflow.

### Distribute by range then sort each bucket

CONTRACT: Mutable vector of small ints; n<=1000. Values0..100.

IDEA AND STATE: Scores0..100; use11 buckets by value/10 then comparison-sort within each.

TRACE: 29,11,24 ->bucket1:[11],bucket2:[29,24] ->11,24,29.

CORRECTNESS: All values in an earlier bucket precede later buckets; sorting each completes the global order.

COST: O(n log(n+1)) worst time plus bucket overhead; O(n+11) space.

PITFALL: Bucket performance depends on distribution and bucket design; this example does not promise universal linear time.

### Sort when each element is at most k places away

CONTRACT: Vector where each element is displaced by at most k from some sorted arrangement; k nonnegative.

IDEA AND STATE: A min heap of k+1 lookahead elements exposes the next correct value.

TRACE: 3,1,2,5,4 with k2 ->1,2,3,4,5.

CORRECTNESS: The next smallest unplaced value cannot lie beyond the permitted lookahead.

COST: O(n log(k+2)) time,O(min(n,k+1)) heap space.

PITFALL: The precondition matters; k=0 is only for already sorted input.

### Observe stability with tagged equal keys

CONTRACT: Sort records by score only and retain arrival order among ties.

IDEA AND STATE: Shift only records with strictly greater keys.

TRACE: (2,A),(1,B),(2,C) ->(1,B),(2,A),(2,C).

CORRECTNESS: A later equal key never crosses an earlier equal key.

COST: O(n^2) worst time,O(1) auxiliary record storage.

PITFALL: Using >= in the shift condition reverses equal records; ordinary std::sort does not guarantee stability.

### Count inversions while merging

CONTRACT: Count index pairs i<j with a[i]>a[j], sorting a as a side effect.

IDEA AND STATE: When a right value precedes a left value, every remaining left value forms an inversion with it.

TRACE: 2,4,1,3,5 has3 inversions.

CORRECTNESS: Both halves count their internal inversions; the merge counts each cross-half inversion exactly once.

COST: O(n log(n+1)) time,O(n) buffer plus O(log(n+1)) stack; long long count.

PITFALL: Equal values are not inversions. n<=1000 keeps index conversions safe.


