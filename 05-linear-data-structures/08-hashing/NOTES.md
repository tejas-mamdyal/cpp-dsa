# Collision mechanisms and hashing applications: notes

A hash narrows the search; equality distinguishes keys. Separate chaining retains colliding keys in one bucket. Open addressing distinguishes never-used from deleted slots: tombstones preserve probe reachability. Reusing a tombstone must not bypass duplicate detection farther along the probe sequence. Negative remainders need normalization.

Load is elements/buckets. Geometric rehash recomputes every position under the new modulus. Expected constant lookup assumes distributed hashes and bounded key work; worst-case lookup is linear. Iteration is neither sorted nor original order. Two-sum records earlier indices; first-unique uses counts then original order; multiset intersection consumes counts; isomorphism needs both directions. Consecutive-run scanning starts only without a predecessor. Composite equality and hashing must agree for equal keys; unequal keys may collide.

## Worked reasoning

### Separate chaining makes collisions visible

CONTRACT: Set of int keys with5 buckets; duplicate insertions are ignored.

IDEA AND STATE: Normalize a remainder to a bucket, then search only that bucket.

TRACE: 1,6,11 collide in bucket1 but remain distinct keys.

CORRECTNESS: Every key stays in the bucket selected by its hash; equality resolves collisions.

COST: O(1+load) expected lookup with distributed keys,O(n) worst; O(n+5) storage.

PITFALL: A collision does not mean equality; negative remainders need normalization.

### Two-sum indices require a previous occurrence

CONTRACT: Values/target bounded to magnitude1000000; length fits int.

IDEA AND STATE: Look up the complement before inserting the current index.

TRACE: 3,3 target6 uses two different indices.

CORRECTNESS: The table contains only earlier indices, so a found complement cannot reuse the current element.

COST: Expected O(n) time,O(n) space; O(n^2) worst hashing.

PITFALL: Inserting before lookup can falsely use one value twice.

### Compare hashing with sorting for duplicate detection

CONTRACT: Int vector; observation must leave caller input unchanged.

IDEA AND STATE: Hash inserts detect previous values; sorting a copy exposes adjacent equals.

TRACE: 2,1,2 duplicates;2,1,3 does not.

CORRECTNESS: Any repeated value creates either a repeated insertion or an adjacent sorted pair.

COST: Hash expected O(n),worst O(n^2),O(n) space; sorted copy O(n log n),O(n) copy.

PITFALL: Sorting caller data changes its order unless a copy is explicit.

### Frequency first then original order

CONTRACT: Return the first input value appearing once, or absence.

IDEA AND STATE: Count globally then scan input order rather than hash iteration order.

TRACE: 4,2,4,7 ->2.

CORRECTNESS: The second scan picks the earliest position whose completed count is1.

COST: Expected O(n) time,O(u) space; worst O(n*u) hash work.

PITFALL: Unspecified hash traversal cannot establish the first original occurrence.

### Consume frequency counts for multiplicity

CONTRACT: Output common occurrences in the second input encounter order.

IDEA AND STATE: Store counts from the first input and decrement only when consuming a match.

TRACE: 1,1,2 with1,2,1,1 ->1,2,1.

CORRECTNESS: A count permits at most the available number of each value to be emitted.

COST: Expected O(n+m) time,O(u+k) storage including k output; worst hashing degrades.

PITFALL: A membership set would lose multiplicities.

### Start consecutive scans only at sequence beginnings

CONTRACT: Int values in[-1000000,1000000];duplicates ignored.

IDEA AND STATE: A value without predecessor starts a sequence; extend until the first absent successor.

TRACE: 100,4,200,1,3,2 ->length4 from1..4.

CORRECTNESS: Every distinct value belongs to exactly one started run, avoiding repeated full-run scans.

COST: Expected O(n) time,O(u) space; O(n^2) worst hashing.

PITFALL: Bounds make value-1/current+1 representable; arbitrary INT_MIN/MAX would need guards.

### Two maps enforce a bijection

CONTRACT: Equal-length byte strings; compare exact char units.

IDEA AND STATE: Map left->right and right->left so neither side can collapse distinct characters.

TRACE: egg/add true;ab/aa false.

CORRECTNESS: Each processed pair respects both directions of the same one-to-one mapping.

COST: Expected O(n) time,O(u) map storage; byte alphabet bounds u.

PITFALL: A single forward map permits two source characters to share a destination.

### Equality and hashing must agree

CONTRACT: Grid-cell key contains row and column; hash map stores a value per cell.

IDEA AND STATE: Define equality using both fields and combine their size_t hash values.

TRACE: (1,2) and(2,1) are different cells even if hashes collide.

CORRECTNESS: Equal keys produce equal hashes; bucket collisions are resolved by key equality.

COST: Expected O(1) operations for bounded keys,O(n) worst; O(n) storage.

PITFALL: A hash is not a unique ID, and this example is not a cryptographic hash.

### Linear probing needs tombstones after deletion

CONTRACT: Fixed7-slot set; insert returns false for duplicate or full, erase/find for absence.

IDEA AND STATE: Probe a circular sequence; deleted slots are reusable but do not end search.

TRACE: 1,8,15 collide; deleting8 must not hide15.

CORRECTNESS: Every live key remains reachable along its probe path until an originally empty slot.

COST: O(capacity) worst operation,O(capacity) storage; fixed capacity7 here.

PITFALL: Clearing a deleted slot to empty incorrectly breaks a collision chain.

### Rehash all keys when bucket count changes

CONTRACT: Unique int keys; start with3 buckets,grow to2*b+1 when size exceeds2*b.

IDEA AND STATE: Compute each old key hash using the new bucket count and move its value.

TRACE: After several inserts the same keys remain findable under a larger bucket array.

CORRECTNESS: Rehash redistributes every key according to the new modulus; no key disappears or duplicates.

COST: Expected amortized O(1) insertion under distributed hashing; O(n+B) rehash; O(n+B) storage; O(n) worst lookup.

PITFALL: Changing the bucket count without redistributing keys makes old keys unreachable.


