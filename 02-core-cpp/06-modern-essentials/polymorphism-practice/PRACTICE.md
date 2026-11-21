# Independent practice: Interfaces inheritance and dispatch

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Perimeter interface

Add perimeter to two concrete shapes.

Example: 3x4 rectangle ->14; square5 ->20.

## 2. Override diagnosis

Explain why missing const in an override is a bug.

Example: compiler rejects override mismatch.

## 3. Slicing repair

Change a function parameter from Base value to const Base&.

Example: derived dispatch survives the call.

## 4. Cast failure

Check a Dog cast from an unrelated Animal object.

Example: pointer cast yields nullptr.

## 5. Destructor trace

Record base and derived destruction order.

Example: derived runs before base.

## 6. Protected versus private

Replace protected raw state with a protected const accessor.

Example: derived reads through an invariant-preserving method.

## 7. Final diagnosis

Explain why deriving from a final class fails.

Example: compile-time rejection.

## 8. Composition choice

Explain whether Student has-an Address or is-an Address.

Example: composition is appropriate.


