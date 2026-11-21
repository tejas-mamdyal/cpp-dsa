# Unsigned bits and bounded enumeration: notes

Phase1 supplied operator truth tables; this unit derives algorithms. Unsigned wrap does not permit a shift count at or above the operand width. Distinguish significant width,population count and highest bit;zero needs its own absence/identity policy. Pair-cancellation XOR assumes valid multiplicities and cannot verify them.

Two singletons separate on one differing bit. Hamming distance counts ones in XOR. Subset masks retain exponentially many outputs,while submasks enumerate only selected bits and must stop after zero. Range XOR follows a period-four identity and handles left0 before unsigned subtraction. The independent submask check tries all byte-sized candidates.

## Worked reasoning

### Unsigned bit masks and safe positions

CONTRACT: Unsigned values and bit positions below numeric_limits<unsigned int>::digits.

IDEA AND STATE: One-bit masks select individual flags; AND/OR/XOR implement clear/set/toggle/test.

TRACE: 12 and10 ->AND8,OR14,XOR6;set bit0 ->13.

CORRECTNESS: Each bit operation follows its truth table independently.

COST: O(1) fixed-width operations and storage.

PITFALL: A shift by the type width is invalid; unsigned complement flips the full width.

### Kernighan count versus a bit-by-bit oracle

CONTRACT: Unsigned fixed-width values.

IDEA AND STATE: value&(value-1) removes the lowest set bit.

TRACE: 12 ->8 ->0, two set bits.

CORRECTNESS: Every iteration removes exactly one1 and terminates when none remain.

COST: O(popcount) operations,O(1) space.

PITFALL: Do not subtract from a signed minimum; zero must skip the loop.

### Count significant bits and find the highest set bit

CONTRACT: Unsigned values; zero has width0 and no highest-set-bit index.

IDEA AND STATE: Shift until0, counting positions.

TRACE: 8 is1000,width4,highest index3.

CORRECTNESS: Each shift removes one low-order bit until all significant positions are consumed.

COST: O(width) time,O(1) space.

PITFALL: Width is not population count:8 has one set bit but four significant positions.

### Two unique values among pairs

CONTRACT: Unsigned values:exactly two distinct values occur once; every other value twice.

IDEA AND STATE: XOR all values, isolate one differing bit, then XOR the two groups.

TRACE: 1,2,1,3,2,5 ->singletons3,5.

CORRECTNESS: Pairs cancel within their bit group; the unique values differ on the isolated bit and separate.

COST: O(n) time,O(1) extra space.

PITFALL: The multiplicity condition is a precondition; XOR alone cannot validate it.

### Count differing bit positions

CONTRACT: Unsigned values of the same fixed width.

IDEA AND STATE: XOR marks exactly the unequal positions; count those ones.

TRACE: 10 XOR12 =6, distance2.

CORRECTNESS: Equal bits cancel and unequal bits produce1.

COST: O(number of differing bits) time,O(1) space.

PITFALL: Numeric subtraction does not measure bitwise distance.

### Enumerate bounded subsets by masks

CONTRACT: At most10 distinct input ints; retain all subset outputs.

IDEA AND STATE: Bit i indicates membership of input position i.

TRACE: 1,2 produces[],[1],[2],[1,2].

CORRECTNESS: Every subset has exactly one membership mask and each mask is visited once.

COST: O(n*2^n) time and output storage,O(n) temporary subset.

PITFALL: Validate n before shifting; an empty input still has the empty subset.

### Enumerate only subsets of selected bits

CONTRACT: Mask in0..255; include submask0 exactly once.

IDEA AND STATE: Repeatedly use(submask-1)&mask and stop after0.

TRACE: mask10 ->10,8,2,0.

CORRECTNESS: Subtracting moves to the next lower allowed combination after the AND clears forbidden bits.

COST: O(2^popcount(mask)) output/time,O(output) stored results.

PITFALL: Without the zero break, unsigned wrap restarts the enumeration forever.

### Use the period-four XOR identity

CONTRACT: Endpoints0<=left<=right<=1000000000.

IDEA AND STATE: XOR1..n repeats a four-case pattern; cancel the prefix before left.

TRACE: XOR3..6 =3^4^5^6=4.

CORRECTNESS: XOR pairs cancel and four consecutive aligned values establish the period.

COST: O(1) fixed-width time/space.

PITFALL: Handle left0 before subtracting1 from an unsigned value.


