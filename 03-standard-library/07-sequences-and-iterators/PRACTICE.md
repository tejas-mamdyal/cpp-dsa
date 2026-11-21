# Independent practice: Sequences utilities and iterator contracts

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Container selection

Choose structures for indexed scores, FIFO jobs and frequent front insertion.

Example: vector,queue,deque respectively.

## 2. Erase odds

Erase odd values using erase returned iterators.

Example: 1,2,3,4 ->2,4.

## 3. List splice

Move a list node to another list without copying its value.

Example: move2 from1,2 into3 ->1 and3,2.

## 4. Forward-list filter

Remove values below0 with predecessor tracking.

Example: -1,2,-3 ->2.

## 5. Reverse copy

Copy in reverse order without altering the source.

Example: 1,2,3 ->3,2,1.

## 6. Const iteration

Explain why assigning through cbegin fails.

Example: reading works; writing is rejected.

## 7. Variant query

Hold either a numeric score or a textual absence reason.

Example: string reason is inspected before get.

## 8. Invalidation trace

Explain why a saved vector iterator cannot cross a forced reallocation.

Example: reacquire by valid index afterward.


