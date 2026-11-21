# Algorithms numeric utilities and applications: notes

Library algorithms consume half-open iterator ranges. Their preconditions still matter: sorted bounds require compatible ordering, output algorithms need actual writable elements or an inserter, and heap algorithms require an existing heap except during make_heap. Container reserve does not make an output iterator dereferenceable.

remove and unique compact logical prefixes and return new ends; erase changes container size. unique only merges adjacent equals. Stable algorithms preserve equivalent-element order, while ordinary sort/partition do not. nth_element selects a rank without sorting both sides. next_permutation enumerates all distinct arrangements when started at the sorted first arrangement.

The initial value determines accumulate arithmetic type. Use 0LL or 0.0 intentionally and promote before potentially overflowing multiplication. gcd/lcm require representable intermediate/result values. Set algorithms require sorted ranges and honor multiplicities. Algorithm-interface fluency comes before implementing the algorithms in Phase3.

## Concepts in the worked programs

### 01 binary search bounds

lower_bound finds first >=value; upper_bound first >value; their distance counts duplicates.

Trace: 1,2,2,4 ->count2=2;lower_bound3 points to4. Sorted order allows discarding half the remaining candidates.

Cost: O(log n) comparisons and iterator jumps on vector. Pitfall: The range must be partitioned according to the search ordering; sorting/searching with incompatible comparators breaks the contract.

### 02 erase remove unique

Use erase-remove for filtering; sorted unique collapses adjacent equal values then erase changes size.

Trace: 1,2,2,3,4 remove evens ->1,3;1,1,2 unique ->1,2. Algorithms compact retained elements to a prefix; erase discards the unused suffix.

Cost: O(n) time and O(1) extra sequence storage. Pitfall: remove/unique alone do not reduce container size, and unique removes adjacent duplicates only.

### 03 transform copy predicates

Pre-size destinations or use an output inserter; all_of on an empty range is true.

Trace: 1,2,3 doubles2,4,6 and filtering retains2,3. transform writes one result per source element; back_inserter grows the destination safely.

Cost: O(n) calls and O(n) destination storage. Pitfall: Writing through emptyVector.begin() is invalid; reserve alone does not create output elements.

### 04 accumulate iota partial sum

Generate1..4 with iota; use long long accumulation and partial_sum for prefix totals.

Trace: 1,2,3,4 ->sum10;prefix1,3,6,10. Each prefix adds the next element to the accumulated total.

Cost: O(n) range work and O(n) output storage; gcd/lcm add logarithmic arithmetic work. Pitfall: The initial value controls accumulate arithmetic type; 0LL avoids int summation for a long long result. lcm requires representability.

### 05 partition and stability

stable_partition retains relative order within true/false groups; stable_sort retains equivalent-key order.

Trace: 3,2,1,4 grouped evens ->2,4,3,1. Stability preserves encounter order among elements whose grouping/key is equivalent.

Cost: stable_partition O(n) predicate calls and up to O(n log n) moves without a buffer; stable_sort O(n log n) comparisons with buffer, up to O(n log^2 n) otherwise; up to O(n) extra memory. Pitfall: Ordinary partition and sort do not promise that stability.

### 06 permutations and nth

Starting sorted visits distinct permutations; nth_element selects a position without fully sorting.

Trace: 1,1,2 has3 distinct permutations; rank2 in9,1,5,3 is5. Lexicographic successor avoids repeated arrangements; nth_element establishes the selected rank partition.

Cost: Permutation enumeration O(p*n) for p permutations; nth_element expected O(n) comparisons. O(n) stored data. Pitfall: nth_element does not sort either side; never select an index outside the range.

### 07 sorted set algorithms

Use set_intersection and set_difference on sorted ranges; duplicates are counted, not silently discarded.

Trace: 1,2,2,3 intersect2,2,4 gives2,2; difference gives1,3. Sorted heads identify whether the next value is shared or exclusive.

Cost: O(n+m) comparisons and O(n+m) output capacity. Pitfall: Both ranges must use the same ordering. set_difference is directional: a-b differs from b-a.

### 08 heap algorithms

make_heap establishes a max-heap; pop_heap moves its maximum to the end, then pop_back removes it.

Trace: 3,1,4 ->heap front4;pop_heap then pop_back leaves maximum3. Each operation preserves the heap invariant on its documented range.

Cost: make_heap O(n); push/pop O(log n); sort_heap O(n log n); in-place range storage. Pitfall: pop_heap alone does not shrink the vector. push_heap requires that all but the newly appended element already form a heap.


