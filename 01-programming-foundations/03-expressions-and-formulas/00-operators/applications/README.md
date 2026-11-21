# Operator applications after loops

Prerequisites: scalar operators, validation, while/for loops and accumulators.
These programs deliberately occur later than the scalar operator introductions.

1. [Single number with XOR](01_single_number_xor.cpp): paired values cancel. Exactly
   one value appears once and all others twice; this assumption is not verified.
2. [Count set bits](02_count_set_bits.cpp): x&(x-1) clears the lowest set bit, so
   each iteration accounts for one bit. Zero naturally takes zero iterations.
3. [Power of two](03_power_of_two.cpp): positive and one set bit. Zero is excluded
   explicitly; positivity also protects the signed arithmetic in the next test.
4. [Set clear toggle test](04_bit_flags.cpp): a validated position creates one mask.
   OR sets, AND with complement clears, XOR toggles and AND tests.

Read each comment's bounds. A shift by an operand width or a negative count is not
valid. Bitwise tricks need clear contracts; XOR does not find a general mode.

Attempt [practice](PRACTICE.md), then [hints](HINTS.md) and [checkpoint](CHECKPOINT.md).

