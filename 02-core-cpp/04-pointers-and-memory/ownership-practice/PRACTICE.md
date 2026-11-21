# Independent practice: Ownership lifetime and RAII

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Early return cleanup

Demonstrate a destructor on an early-return path.

Example: counter returns to0 on both paths.

## 2. Move a buffer

Move a unique_ptr into a helper taking ownership.

Example: caller becomes empty; helper sees original value.

## 3. Borrow without transfer

Write a helper reading an owned int through const int*.

Example: owner remains engaged after call.

## 4. Array ownership

Replace raw new[] with vector<int>.

Example: three zeros, then values2,4,6.

## 5. Weak expiration

Observe an object after all shared owners leave scope.

Example: lock returns an empty shared_ptr.

## 6. Cycle diagnosis

Draw two shared owners pointing to each other and repair one edge.

Example: one weak link permits reclamation.

## 7. Rule of zero

Explain which special members a vector-backed Buffer needs to define.

Example: none for ordinary value semantics.

## 8. Cast safety

Classify casting a mutable view versus writing an actually const int.

Example: only the originally mutable case can be writable.


