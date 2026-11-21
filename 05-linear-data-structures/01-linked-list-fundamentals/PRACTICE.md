# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Build and clear an empty chain twice.

Example/result: head stays null.

## 2. Task

Borrow a singleton then clear its owner.

Example/result: live count returns to baseline.

## 3. Task

Append a third manual node without losing head.

Example/result: 1->2->3->null.

## 4. Task

Repair deletion before reading next.

Example/result: save next while the current node is live.

## 5. Task

Explain deleted owner copy operations.

Example/result: two owners must not delete one allocation set.

## 6. Task

Clone values independently and mutate only the clone.

Example/result: original remains unchanged.

## 7. Task

Compare repeated rescanning append with maintained tail.

Example/result: quadratic versus linear construction.

## 8. Task

Explain catch/clear/rethrow during building.

Example/result: partial nodes are reclaimed.


