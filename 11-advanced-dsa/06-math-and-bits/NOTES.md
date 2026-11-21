# Algebraic invariants,modular arithmetic and bit bases: reasoning before code

An XOR basis uses the highest set bit as a pivot,just like elimination over two-element arithmetic. Euclid preserves common divisors;extended Euclid also maintains a linear combination. Modular multiplication here uses residues below 1000000007,so signed 64-bit products fit. An inverse exists only for coprime operands. Factorial inverses require a prime modulus and n below it;Pascal addition remains valid for composite moduli. CRT solutions exist exactly when residues agree modulo the gcd. Matrix powers compose recurrence transitions. Never shift by the type width or assume every nonzero residue is invertible.

For every source,write its domain and output convention before running it. Reproduce the commented trace;identify what each state means at the start and end of an iteration. Justify every discarded candidate,pruned branch or finalized value. Compare input,auxiliary and output storage separately. Copies,recursion depth and saved witnesses count toward storage.

First solve a tiny instance by enumeration or direct scans. An independent reference should use a different control structure rather than restating the optimized recurrence. Empty,unreachable,duplicate and boundary cases depend on the lesson contract;do not silently broaden it. Finite checks support the proof but cannot substitute for it.

