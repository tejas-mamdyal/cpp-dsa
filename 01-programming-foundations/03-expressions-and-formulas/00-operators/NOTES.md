# Operators before formula applications

An operand supplies a value; an operator describes an operation on it. Unary - uses
one operand, binary subtraction two, and ?: three. The result has a type: comparisons
produce bool, integer division produces an integer, and conversion before division
can select floating arithmetic. Assignment changes an object; equality compares.

Read one statement at a time. Prefix increment returns the new value while postfix
returns the previous value. Both still modify the object. Avoid mixing several
changes to one object in one expression. Parentheses show grouping; precedence and
associativity do not generally tell you operand execution order.

Built-in && evaluates its right side only if the left is true. Built-in || evaluates
its right side only if the left is false. These rules allow safe guards. & and | are
bitwise operations and do not provide logical short circuit. ^ combines unequal bits:
0^0=0,0^1=1,1^0=1,1^1=0. Therefore equal whole values cancel under XOR.

Use unsigned values in bit exercises and validate shift positions. A promoted
32-bit operand shifted by32 is invalid, even if assigned afterward to64-bit storage.
1ULL selects an unsigned long long left operand. ~ flips all promoted bits; mask
unwanted bits if your problem speaks of only the lowest four/eight bits.

sizeof gives bytes and alignof an alignment requirement. Their exact numeric sizes
vary by implementation. sizeof on an ordinary expression does not execute it.
The (void) cast in the size example explicitly discards that expression result.

The conditional lesson intentionally demonstrates ?:; elsewhere an if/else is often
clearer for several actions. The comma lesson intentionally demonstrates the comma
operator; normal sequential code should use separate lines. Alternative token
spellings are standard but the symbolic forms are more common in DSA examples.

The complete catalogue explains pointer/class operators and points to their Phase2
lessons. Do not attempt member pointers or manual allocation before those topics.

