# Searching and boundary contracts: notes

An exact search may return any duplicate position; first/last positions and insertion boundaries are different contracts. Linear traversal needs no ordering; binary search requires sorted data or a monotone false/true partition. With half-open bounds,right can equal size: the returned insertion position is not automatically a dereferenceable match. lower_bound rejects values<key and upper_bound rejects values<=key. Every step must shrink the candidate range.

Use left+(right-left)/2 and state whether endpoints are inclusive. Recursive search borrows its input and adds logarithmic frames. Exponential bracketing guards doubling. Square root compares positive middle with x/middle to avoid overflow. A globally row-major sorted matrix permits flat binary search; merely sorted rows/columns need staircase elimination instead. The final bounded oracle independently scans for the first not-less position.

## Worked reasoning

### Iterative exact binary search

CONTRACT: Nondecreasing int vector; length fits int; return any matching index or-1.

IDEA AND STATE: Maintain inclusive candidate interval[left,right].

TRACE: 1,3,5,7 target5:middle1 rejected, then middle2 matches.

CORRECTNESS: Discarded halves cannot contain the key by sorted order; every failed step shortens the interval.

COST: O(log(n+1)) time,O(1) extra space.

PITFALL: An exact match is not necessarily the first duplicate; never binary-search unsorted input.

### Linear first and last matching positions

CONTRACT: Any int vector; return a pair of first/last indices or{-1,-1}.

IDEA AND STATE: Scan once and preserve the first match while updating the latest match.

TRACE: 4,2,4,4 ->target4 positions0,3.

CORRECTNESS: After each prefix first is earliest and last latest among matches already processed.

COST: O(n) time,O(1) extra space.

PITFALL: Do not initialize absence to0, a valid position.

### First position not less than a key

CONTRACT: Sorted vector; return an insertion position in[0,size], including end.

IDEA AND STATE: Use half-open[left,right);a[middle]<key eliminates the left prefix.

TRACE: 1,2,2,5 key2 ->1; key6 ->4.

CORRECTNESS: All indices before left are less than key; all at/after right are not less.

COST: O(log(n+1)) time,O(1) space.

PITFALL: The returned end position is not a dereferenceable match.

### First position greater than a key

CONTRACT: Sorted vector; return first strictly greater index, or size.

IDEA AND STATE: Move past values<=key.

TRACE: 1,2,2,5 key2 ->3.

CORRECTNESS: The rejected prefix is entirely<=key; remaining interval contains the first greater candidate.

COST: O(log(n+1)) time,O(1) space.

PITFALL: Changing <= to < instead computes lower_bound.

### Duplicate range via two boundaries

CONTRACT: Sorted vector; report count without scanning every duplicate.

IDEA AND STATE: One boundary finds first>=key and the other first>key.

TRACE: 1,2,2,2,8 target2 gives[1,4),count3.

CORRECTNESS: Exactly the equal values lie between the two partition boundaries.

COST: O(log(n+1)) time,O(1) space.

PITFALL: Counting by scanning after one found match can degrade to linear.

### Floor and ceiling with explicit absence

CONTRACT: Sorted vector; return optional values floor<=key and ceiling>=key.

IDEA AND STATE: An insertion boundary identifies ceiling and its predecessor gives floor unless equality holds.

TRACE: 2,5,9 key6 ->5,9; key1 has no floor.

CORRECTNESS: Sorted order makes adjacent insertion neighbors the closest legal values.

COST: O(log(n+1)) time,O(1) space.

PITFALL: Use optional rather than a sentinel that may be a valid input.

### Recursive binary search on a half-open range

CONTRACT: Sorted vector and valid[left,right);return index or-1.

IDEA AND STATE: The base is an empty range; each recursive call keeps only one half.

TRACE: 1,4,7 target7 ->[0,3),then[2,3) matches.

CORRECTNESS: A sorted discarded half cannot contain the target; interval length strictly decreases.

COST: O(log(n+1)) time and call-stack space.

PITFALL: Do not copy the vector or omit the returned recursive result.

### Reverse the order assumptions consistently

CONTRACT: Vector sorted nonincreasingly; return any match index or-1.

IDEA AND STATE: Larger values lie left, so a[middle]<key discards the right side.

TRACE: 9,7,4,1 target7 ->index1.

CORRECTNESS: The comparator order determines which half is impossible.

COST: O(log(n+1)) time,O(1) space.

PITFALL: An ascending search on descending data has the wrong invariant.

### Search a monotone predicate boundary

CONTRACT: Given n and firstTrue in[0,n], model a false prefix then true suffix; n means all false.

IDEA AND STATE: Binary search the predicate index>=firstTrue.

TRACE: n8,boundary5 ->5; all false ->8.

CORRECTNESS: The false prefix and true suffix partition the candidate range; every step preserves the first true position.

COST: O(log(n+1)) predicate calls,O(1) space.

PITFALL: This applies only to monotone predicates. Binary search on numeric answers is expanded in Phase4.

### Floor square root without multiplication overflow

CONTRACT: 0<=x<=9223372036854775807; return greatest r with r*r<=x.

IDEA AND STATE: Compare middle<=x/middle, never middle*middle.

TRACE: x26 ->5; x0 ->0.

CORRECTNESS: The predicate is true for all positive candidates up to the root and false afterward.

COST: O(log(x+1)) time,O(1) space.

PITFALL: Handle x<2 before division; cap the search to the largest possible signed64-bit root.

### Find a small search window by doubling

CONTRACT: Sorted vector; find a key with doubling bounds then ordinary lower_bound in that window.

IDEA AND STATE: Grow a bound until its value reaches key or the vector ends.

TRACE: 1,3,5,7,9 target7:bounds1,2,4 then search indices2..4.

CORRECTNESS: Earlier rejected positions are smaller than key; the bracket contains any possible first match.

COST: O(log(p+1)) comparisons near insertion position p; O(1) space.

PITFALL: Guard size arithmetic instead of allowing bound*=2 to wrap.

### Binary search a globally ordered matrix

CONTRACT: Rectangular nonempty rows; each row sorted and each next row starts after the previous last. Empty matrix is allowed.

IDEA AND STATE: Map a virtual flat midpoint to row=mid/columns,column=mid%columns.

TRACE: [1,3,5;7,9,11] target9 maps flat4 to row1,column1.

CORRECTNESS: Global row-major ordering makes the virtual flattened sequence sorted.

COST: O(log(rows*columns+1)) time,O(1) space; matrix size must fit int here.

PITFALL: Sorted rows and columns alone do not guarantee this stronger global row-major condition.

### Search rows and columns sorted independently

CONTRACT: Rectangular matrix sorted nondecreasing in each row and column.

IDEA AND STATE: Start top-right; too large discards a column, too small discards a row.

TRACE: [1,4,7;2,5,8;3,6,9] target6:7->4->5->6.

CORRECTNESS: The current corner bounds all values in its row/column, so each discarded strip is impossible.

COST: O(rows+columns) time,O(1) space.

PITFALL: This has a different precondition from row-major binary search; do not flatten this matrix as sorted.

### Exhaust search boundaries against a linear oracle

CONTRACT: Enumerate all nondecreasing vectors of length0..5 over{0,1,2};compare own lower boundary with linear scanning.

IDEA AND STATE: Decode base3, sort and compare for targets-1..3.

TRACE: Empty gives0;[0,1,1],key1 gives1.

CORRECTNESS: A direct scan independently identifies the first not-less element; exhaustive inputs exercise duplicates and end boundaries.

COST: Helper O(log n) time/O(1) space; bounded oracle harness enumerates364 raw vectors and5 targets.

PITFALL: The oracle is evidence on a finite domain, not a proof outside it.


