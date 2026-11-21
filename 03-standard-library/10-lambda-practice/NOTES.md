# Lambdas captures and comparators: notes

A lambda creates a callable object. Captures are established when the closure is created and its body runs when called. Value captures retain copies; reference captures borrow original objects and can dangle. Init captures name new owned state. mutable permits mutation of captured copies; it does not turn a copied capture into a reference.

Generic auto parameters deduce a type per call, provided the body operations exist for that type. A function object expresses the same idea with an explicit operator(). std::function provides type erasure for a fixed signature and may add allocation/dispatch overhead; it is not required merely to call a lambda.

Ordering comparisons must be irreflexive and transitive, with consistent equivalence. Use strict < or > and explicit tie-breakers. <= is not a valid sort predicate. Prefer named helpers if a lambda hides a substantial algorithm or its state requirements.

## Concepts in the worked programs

### 01 value reference capture

Copy one offset and borrow another; changing the source only changes the borrowed view.

Trace: offset2 ->5; copied add1 gives3 while borrowed gives6. The copied capture stores its own int; the reference capture observes the original.

Cost: O(1) time and closure storage. Pitfall: Never return a closure borrowing a destroyed local.

### 02 mutable init capture

An init capture can create a separate counter; mutable permits modifying a captured copy.

Trace: counter starts0 and successive calls return1,2; outer value stays10. The closure retains its own counter between calls.

Cost: O(1) time/storage. Pitfall: mutable changes captured copies, not the original variable captured by value.

### 03 generic lambda

auto parameters produce a suitable call operator for each used argument type.

Trace: twice3=6; twice2.5=5; string ab ->abab. Each call instantiates a parameter type whose + operation supplies the result.

Cost: Numeric calls O(1); string concatenation O(n) time and output storage. Pitfall: Generic does not mean every type is supported; the requested operations must exist.

### 04 strict weak order

Order records by descending mark, then ascending ID; equal records compare false in both directions.

Trace: marks90 IDs1,2 precede mark80 ID3. Lexicographic tie-breaking defines consistent strict comparisons.

Cost: O(n log n) comparisons; sort implementation uses O(log n) typical stack space. Pitfall: Never use <= in a sort comparator; irreflexivity and transitivity are required.

### 05 functor and wrapper

A class operator() carries state; std::function can hold compatible callable kinds.

Trace: Scale3 applied4=12; wrapper replaced with add1 gives5. All stored operations accept an int and return an int.

Cost: O(1) bounded callable state; std::function may allocate and adds indirect-call overhead. Pitfall: Calling an empty std::function throws bad_function_call. Use a named function or auto lambda when type erasure is unnecessary.

### 06 custom heap comparator

Use a strict functor comparator for priority_queue: greater priority first, smaller ID first on ties.

Trace: priority5 IDs2,1 ->serve ID1 then2 before priority3 ID0. The comparator returns true when the left job has lower precedence than the right job.

Cost: O(log n) push/pop, O(1) top, O(n) stored jobs. Pitfall: Heap comparator direction differs from sorted-output intuition; never use <= and test ties explicitly.


