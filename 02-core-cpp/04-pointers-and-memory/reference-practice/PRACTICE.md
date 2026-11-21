# Independent practice: References pointers and lifetime

Write each solution from a blank file. Use C++17 and state input constraints,
return/absence policy, cost and at least one empty/invalid/boundary case.
Small exercise integers have absolute value <=1000000 unless stated otherwise.

## 1. Swap equal values

Swap7 and7 and explain why a temporary is still correct.

Example: 7,7 ->7,7.

## 2. Optional write

Set a pointed-to int to zero, returning false for nullptr.

Example: pointer to9 ->0,true; nullptr ->false.

## 3. Range maximum

Return a pointer to the first largest element, or nullptr for length0.

Example: 2,9,9 ->pointer to index1.

## 4. Two outputs

Compute minimum and maximum via references for a nonempty array.

Example: 4,-2,7 ->-2,7.

## 5. Const API

Write a sum helper that cannot change input elements.

Example: 1,2,3 ->6.

## 6. Lifetime diagnosis

Explain why returning &local is wrong and replace it with a value return.

Example: helper returns42 safely.

## 7. Function selection

Select add or subtract using a function pointer.

Example: 8,3 ->11 or5.

## 8. Reference versus pointer const

List which assignments compile for int* const and const int*.

Example: fixed pointer may write its int; read-only view may redirect.


