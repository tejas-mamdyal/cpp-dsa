# Hash containers and standard lookup questions: notes

unordered_map and unordered_set offer expected constant-time lookup but linear worst-case lookup under collisions. Iteration is unspecified, not random and not sorted. reserve and max_load_factor control capacity policy without promising collision-free behavior. Rehash invalidates iterators; element references survive rehash, while erasing an element invalidates its references too.

The central invariant in two sum is that the table holds earlier indices only. Frequency maps separate counting from answer selection; ties need an explicit policy. Distinct intersection ignores multiplicity, whereas sorted multiset algorithms can retain it. A canonical sorted-word key groups anagrams because equal character multisets produce equal keys.

Hash costs include hashing the key itself: a string of length m is not free to hash. Choose ordered maps for deterministic key traversal and logarithmic worst-case lookup when appropriate.

## Concepts in the worked programs

### 01 hash frequency

Use [] to increment, find to query without insertion, and at for an existing key.

Trace: 4,4,1 gives count4=2 and count1=1. Each occurrence increments its own key counter once.

Cost: Expected O(n) total updates, worst O(n^2) under pathological collisions; O(u) keys. Pitfall: Hash iteration order is unspecified; do not use it as sorted output.

### 02 first repeated

Insert into an unordered_set and inspect insertion success.

Trace: 2,5,2,5 -> second2 is the earliest repeated encounter. Before each insertion the set contains exactly the previously seen values.

Cost: Expected O(n) time, worst O(n^2); O(u) space. Pitfall: This asks for the first repeated encounter, not the smallest repeated value or earliest first occurrence.

### 03 two sum

Return two different indices whose bounded int values sum to a target. Look up the complement before inserting the current value.

Trace: 2,7,11 target9 -> indices0,1;3,3 target6 ->0,1. The map contains only earlier positions, so any found partner is a different element.

Cost: Expected O(n) time, worst O(n^2); O(n) space. Pitfall: Inputs and target are within [-1000000,1000000] and length fits int. General int subtraction needs overflow care.

### 04 set intersection

Hash sets remove duplicates; output sorted order is established separately.

Trace: 1,2,2 and2,3 intersect at2 and union to1,2,3. Sets encode distinct membership; each first-set key is considered only once.

Cost: Expected O(n+m+k log k), worst hashing may be quadratic; O(n+m) storage. Pitfall: A set intersection ignores multiplicity; multiset intersection is a different question.

### 05 load factor reserve

Set max_load_factor before reserve; inspect bucket_count and load_factor.

Trace: reserve100 requests room for100 elements at the chosen load factor. reserve sizes the bucket array for a target element count under the load-factor policy.

Cost: Expected O(n) construction, O(n) memory; rehash may be expensive. Pitfall: Rehash invalidates iterators but not references/pointers to surviving elements; erase invalidates the erased element. Collision attacks can still cause bad performance.

### 06 word frequency

Split whitespace words and count them in a hash map; punctuation remains part of a word.

Trace: red blue red ->red2 blue1. Each successfully extracted token contributes exactly one occurrence.

Cost: Expected O(L) hashing/token work for L characters; worst collisions can degrade lookup; O(L) key storage. Pitfall: Define normalization before counting natural-language text; this example is deliberately case-sensitive and punctuation-sensitive.

### 07 anagram hash

Count byte multiplicities without assuming a lowercase alphabet. This is byte equality, not Unicode normalization.

Trace: Dorm and mroD have matching byte counts; Dorm and dorm do not. Every byte in the second string consumes one matching occurrence from the first.

Cost: Expected O(n) time, worst O(n*u); O(u) distinct byte keys. Pitfall: Case folding, accents and Unicode code points require an explicit text policy beyond byte counting.

### 08 group anagrams

Sort a copy of each word and use it as an ordered-map key.

Trace: eat,tea,ate share key aet; bat has key abt. Two words have the same sorted key exactly when their byte multiplicities match.

Cost: O(sum m log m + total key-comparison costs) time for word lengths m; O(total characters) stored words/keys. Pitfall: Sort a copy so the original spelling stays available; group ordering here follows map keys.

### 09 unordered multi

unordered_multiset stores repeated values and unordered_multimap stores repeated associations.

Trace: two5 values remain distinct occurrences; key1 maps to10 and20. Multi-container insertion does not discard an existing equivalent key.

Cost: Expected O(1) single lookup plus O(k) matches; worst O(n); O(n) stored records. Pitfall: Hash iteration order is unspecified. erase(key) removes all equivalent entries; erase(iterator) removes one.


