# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Insert at head,tail and length+1.

Example/result: only invalid position is rejected.

## 2. Task

Remove all equal values from a same-key list.

Example/result: head becomes null.

## 3. Task

Drain an owning list then append again.

Example/result: new singleton has valid endpoints.

## 4. Task

Merge empty and nonempty owners.

Example/result: one result owns all nodes;inputs null.

## 5. Task

Split at0,length and an invalid position.

Example/result: two disjoint owners or unchanged failure.

## 6. Task

Explain delete-given on the penultimate node.

Example/result: supplied allocation survives with a different value.

## 7. Task

Compare reverse time and stack usage.

Example/result: both linear time;recursive stack linear.

## 8. Task

Add reversed9,9,9 and1.

Example/result: 0,0,0,1.


