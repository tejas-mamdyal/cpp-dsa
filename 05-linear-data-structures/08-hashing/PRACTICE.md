# Independent practice

Use small stated bounds,n<=1000 unless the problem requires a smaller bound.
Explain preconditions,errors,correctness,time and owned/auxiliary memory. Reclaim
node allocations and never dereference erased observers.

## 1. Task

Trace collision keys1,8,15 in capacity7 then delete8.

Example/result: 15 remains reachable.

## 2. Task

Reuse a tombstone then reject a duplicate farther in the probe chain.

Example/result: one freed slot becomes reusable.

## 3. Task

Normalize bucket positions of-1 and-6 with5 buckets.

Example/result: both bucket4.

## 4. Task

Choose a most-frequent value with smaller-key ties.

Example/result: [2,1,2,1] ->1.

## 5. Task

Explain why singleton3 cannot solve target6.

Example/result: two distinct indices required.

## 6. Task

Verify all old keys after every growth.

Example/result: membership unchanged.

## 7. Task

Design equality/hash for row,column,layer.

Example/result: all three define identity.

## 8. Task

Choose ordered versus hash containers under ordering/collision requirements.

Example/result: logarithmic guarantee versus expected constant.


