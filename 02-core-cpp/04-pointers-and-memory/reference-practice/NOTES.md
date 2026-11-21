# References pointers and lifetime: notes

A reference is an alias bound at initialization; assignment changes its referent rather than rebinding it. A pointer is an object storing an address and can be redirected or null. Neither a reference nor an ordinary pointer automatically owns the referred-to object. Constness of a pointer and constness of its pointee are separate choices.

An array often converts to a pointer to its first element. That pointer does not store a length. A one-past pointer is useful as a loop sentinel but is not an element to read. Pointer arithmetic, subtraction and ordering must respect the same array object. Return values for new computations and references only for objects whose lifetime extends beyond the call.

Function pointers encode an exact callable signature. They are useful for understanding interfaces, but named direct calls are usually simplest when the operation is already known. References/pointers used by the class, vector and iterator examples build on this unit.

## Concepts in the worked programs

### 01 const reference

A const reference observes an existing int without permitting writes through that alias.

Trace: value=7 is observed twice without changing the caller. The const qualifier forbids changing the referred-to int through this parameter.

Cost: O(1) time and space. Pitfall: Do not return a reference to a local variable or a temporary that will expire.

### 02 swap output parameters

Use reference parameters to return quotient and remainder after a nonzero divisor check.

Trace: 17 divided by 5 gives quotient 3 and remainder 2. The temporary preserves the first value; output references write directly to caller variables.

Cost: O(1) time and space. Pitfall: The division helper assumes small ints and distinct output variables; INT_MIN/-1 must also be excluded for general int division.

### 03 null and optional access

Use nullptr for absence and test before dereferencing. The pointer does not own the local value.

Trace: nullptr produces fallback 0; address of 8 produces 8. The guard returns before any dereference of an absent pointer.

Cost: O(1) time and space. Pitfall: A non-null pointer may still dangle; validity also depends on lifetime.

### 04 const pointer forms

Compare const int*, int* const and const int* const. Each const applies to a different object.

Trace: readOnly may be redirected; fixed may modify its int but cannot be redirected. The declarator separates whether the pointer value and/or pointed-to int can change.

Cost: O(1) time and space. Pitfall: Constness through a pointer does not make the original mutable int globally immutable.

### 05 array pointer bounds

Walk a fixed array using pointers from its first element up to but excluding one-past.

Trace: 2,4,6 sum to 12; end-begin=3. Every dereferenced pointer refers to an element of the same array.

Cost: O(n) time and O(1) space. Pitfall: One-past may be formed and compared, never dereferenced. Subtraction/order must stay within the same array.

### 06 array parameters

An int array parameter adjusts to a pointer and loses its array extent. Pass a length explicitly.

Trace: sum first 3 elements = 12; length 0 never dereferences the pointer. The caller supplies an in-bounds length; the loop reads exactly that many elements.

Cost: O(n) time and O(1) space. Pitfall: sizeof(values) inside this function is a pointer size, not the caller array size.

### 07 function pointers

Store the address of a function with matching signature and call it.

Trace: add(2,3)=5; redirected pointer multiply(2,3)=6. Both functions have the exact two-int-to-int signature.

Cost: O(1) time and space. Pitfall: Do not call a null function pointer or cast an incompatible function signature.

### 08 reference lifetimes

Return a value for newly computed results; borrow by reference only from an object that outlives the call.

Trace: local computation returns 12 by value; borrowed caller int changes from 4 to 9. The returned reference still refers to the caller-owned int, not a destroyed local.

Cost: O(1) time and space. Pitfall: Never return int& bound to computed local storage; no dangling dereference is executed here.


