# Staged hints

Use the first hint after an independent attempt;read the second only after recording a trace and a specific difficulty.

## 1. Exercise 1

1. Record owns its string and vector and needs no custom special members.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 2. Exercise 2

1. A unique_ptr represents exactly one owning handle; custom copy allocates a new int.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 3. Exercise 3

1. Temporary copy is fully constructed before swapping into the destination.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 4. Exercise 4

1. This custom move transfers a unique_ptr, whose source becomes empty.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 5. Exercise 5

1. Move assignment releases a previous allocation through unique_ptr and transfers the incoming resource.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 6. Exercise 6

1. The type trait queries whether constructing from an rvalue is nonthrowing.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 7. Exercise 7

1. Construction increments a live-resource counter and destruction decrements it.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 8. Exercise 8

1. The return value owns the result or represents absence.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 9. Exercise 9

1. weak_ptr records observation; lock obtains temporary shared ownership if the object still lives.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 10. Exercise 10

1. reference_wrapper is copyable observation of an existing object, not ownership.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 11. Exercise 11

1. Equality compares all identity-relevant value fields.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

## 12. Exercise 12

1. operator+= mutates this and returns an lvalue reference; operator+ receives a copy.
2. State why the transition or exclusion is valid,then compare the complete answer or witness with an independent tiny reference. Include the smallest legal and an impossible/boundary case.

