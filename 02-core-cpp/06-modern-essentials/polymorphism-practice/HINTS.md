# Hints: Interfaces inheritance and dispatch

Try the problem and hand trace before reading its hint.

## 1. Perimeter interface

First: identify the state and precondition.

Next: Define a pure virtual const method and override it.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 2. Override diagnosis

First: identify the state and precondition.

Next: Compare complete signatures, not just names.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 3. Slicing repair

First: identify the state and precondition.

Next: The reference borrows the complete object.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 4. Cast failure

First: identify the state and precondition.

Next: Check before dereferencing; reference casts throw.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 5. Destructor trace

First: identify the state and precondition.

Next: Use scoped objects first, then owning polymorphic pointers.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 6. Protected versus private

First: identify the state and precondition.

Next: Prefer access to behavior over unrestricted state mutation.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 7. Final diagnosis

First: identify the state and precondition.

Next: Do not run invalid code; record the expected diagnostic.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.

## 8. Composition choice

First: identify the state and precondition.

Next: Use inheritance for substitutability, not merely to reuse fields.

Check the sample, then one boundary case; explain why each update preserves the stated meaning.


