# Independent practice: Lambdas captures and comparators

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Capture prediction

Create copied and borrowed captures, change the source twice and predict results.

Example: copy sees original; reference sees latest.

## 2. Stateful counter

Make two independent mutable counter closures.

Example: first1,2 and second1.

## 3. Generic square

Use a generic lambda for int and double squares.

Example: 3 ->9;1.5 ->2.25.

## 4. Sort names

Sort by shorter length then lexicographic name.

Example: b,aa,ab.

## 5. Descending scores

Sort records descending score then ascending ID.

Example: ties retain a deterministic ID order.

## 6. Dangling capture

Explain why returning [&local] from a function is unsafe.

Example: the source local has expired.

## 7. Callable replacement

Store two compatible operations in std::function.

Example: add1 then times2.

## 8. Wrapper choice

Explain when auto lambda is simpler than std::function.

Example: local known callable needs no type erasure.


