# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Delete a singleton from either endpoint.

Example/result: both endpoints null.

## 2. Task

Insert before the current head.

Example/result: new head.prev null.

## 3. Task

Explain a foreign target pointer contract violation.

Example/result: unchecked unlink can corrupt another owner.

## 4. Task

Reverse twice and inspect both directions.

Example/result: original sequence/endpoints recovered.

## 5. Task

Insert duplicates after equals in sorted order.

Example/result: 1,2,2,3.

## 6. Task

Remove a duplicate currently at tail.

Example/result: tail moves to its predecessor.

## 7. Task

Move the already-front node again.

Example/result: same identity/live count.

## 8. Task

Compare known-node erase with erase-by-index.

Example/result: constant relink versus linear lookup.


