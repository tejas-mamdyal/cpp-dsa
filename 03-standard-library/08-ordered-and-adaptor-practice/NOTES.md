# Ordered containers and adaptors: notes

set stores unique ordered keys; multiset retains duplicate keys. map associates unique keys with values; multimap permits several records per key. Member lookup/bounds are logarithmic. Use find for observation; map operator[] intentionally inserts a default value when absent. Equal ranges are half-open.

stack exposes last-in-first-out behavior, queue first-in-first-out and priority_queue the highest-priority element. top/front only observe and pop removes without returning. Check nonempty first. greater makes a numeric priority_queue a min-heap. A comparator must be a strict weak ordering; equal elements compare false in both directions.

Bracket matching uses a stack of unmatched openers. A top-k min-heap discards the smallest retained value after each insertion, keeping exactly the best k of the prefix. These applications teach container interfaces; implementing their underlying structures remains in later phases.

## Concepts in the worked programs

### 01 multiset duplicates

Compare erase(iterator) of one occurrence with erase(value) of every equal occurrence.

Trace: 2,2,3 erase one2 ->2,3; erase value2 removes the remaining one. The selected iterator denotes a single node, while key erasure selects an equal-key range.

Cost: O(log n) search/insertion; erase(key) O(log n + removed count). Pitfall: erase(end()) is invalid. set would discard duplicate keys.

### 02 multimap equal range

Use equal_range to visit all records for one key without accidentally inserting data.

Trace: CS scores80,90 sum170; absent key produces an empty range. Equal keys are contiguous in the ordered range.

Cost: O(log n + k) for k matching records. Pitfall: A multimap has no operator[] because a key may identify more than one value.

### 03 ordered bounds

Use member lower_bound and upper_bound to locate >=key and >key.

Trace: set1,3,5: lower_bound3=3;upper_bound3=5. Tree ordering narrows the candidate range without linear stepping.

Cost: O(log n) per member search. Pitfall: Prefer set/map member bounds; generic bounds on tree iterators may perform O(n) iterator steps.

### 04 map lookup insertion

Use find for observation and [] when intentional default insertion is useful.

Trace: find missing keeps size0; counts[7] creates value0. operator[] inserts a value-initialized mapped value only if the key is absent.

Cost: O(log n) map operations. Pitfall: Observation through [] can silently change the container.

### 05 balanced brackets

Push opening brackets and match every closing bracket with the latest opener. Other characters are ignored.

Trace: ([x]) succeeds;([)] fails. The stack stores exactly the unmatched opening brackets in nesting order.

Cost: O(n) time and O(n) stack space. Pitfall: Equal total counts do not prove correct order or nesting.

### 06 queue service

Process requests in arrival order; front reads and pop removes.

Trace: arrivals4,7,2 are served4,7,2. Queue insertion at the back and removal at the front preserve arrival order.

Cost: O(n) total operations and O(n) stored requests/output. Pitfall: pop returns no element; read front before removing and only when nonempty.

### 07 top k largest

Keep at most k values; remove the smallest whenever the heap exceeds k.

Trace: 3,1,9,5 with k2 retains5,9; output is descending. After each prefix the heap contains its k largest values, with the smallest retained one ready for removal.

Cost: O(n log(k+2)+k) time and O(k) heap/output space, capped by n. Pitfall: This application follows algorithm interfaces; priority_queue does not expose sorted iteration.


