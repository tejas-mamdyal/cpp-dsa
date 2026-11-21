# Staged hints

Trace first, then consult only the task you need.

## 1. Arithmetic trace

First identify the operand/state types. Then: Integer division truncates toward zero.

## 2. Conversion timing

First identify the operand/state types. Then: Convert an operand before division.

## 3. Compound trace

First identify the operand/state types. Then: Write one update per line.

## 4. Range predicate

First identify the operand/state types. Then: Combine two comparisons with &&.

## 5. Guarded division

First identify the operand/state types. Then: Put the denominator check before the division.

## 6. Prefix/postfix

First identify the operand/state types. Then: Record returned and stored values separately.

## 7. Conditional maximum

First identify the operand/state types. Then: Use only a simple value selection in ?:.

## 8. Bit table

First identify the operand/state types. Then: Write the operands as110 and011.

## 9. Bit toggle

First identify the operand/state types. Then: XOR with the same mask cancels.

## 10. Size distinction

First identify the operand/state types. Then: A pointer stores an address, not an extent.

## 11. Precedence

First identify the operand/state types. Then: Grouping is not an execution schedule.

## 12. Comma versus separator

First identify the operand/state types. Then: The parenthesized operator yields the last value.

