# Narrow-topic worked scenarios

These supplement single implementations rather than pretending they are different programs.
Read the implementation,then close it and derive each result. Repeatedly running assertions
is not equivalent to solving independently.

## Suffix automaton

For the empty word there are zero nonempty substrings. For `aaaa`,the distinct substrings
are `a,aa,aaa,aaaa`,so there are four. For `abc`,all six intervals give different strings.
For `ababa`,group by length:2+2+2+2+1=9. Membership and distinct counting are separate tasks.
The clone case `abb` forces two different length histories to share transitions;trace the
split instead of treating the implementation as a memorized recipe. Independently enumerate
all intervals and insert their texts into a set to check small inputs.

## Aho-Corasick

Patterns `a,aa` in `aaa` have five occurrences:three single letters and two overlapping
double letters. Patterns with duplicate IDs remain distinct outputs. Failure links preserve
the longest suffix that is a trie prefix;output links expose patterns ending at that suffix.
A scan that reports only the current terminal misses suffix matches. Verify against separate
naive searches for each pattern,including absent patterns. Empty patterns are excluded by
this implementation's contract;do not silently adopt another convention.

## Flow

Parallel arcs of capacities2 and3 can carry5. A disconnected sink carries0. These differ
from merely checking one saturated edge. Residual reverse arcs permit cancellation of an
earlier choice;flow is not the same as deleting a route after finding it. On four vertices,
enumerate every source-side set excluding the sink and sum outgoing capacities;the least
cut is an independent oracle. State capacity bounds and distinguish a value from a cut witness.

## CRT

`x=2 mod3,x=3 mod5` first meets at8,with period15. Noncoprime equations can also work:
`x=2 mod6,x=5 mod9` meets at14,period18. Incompatible `x=0 mod2,x=1 mod4` has no answer.
Equal equations retain their original period. Check compatibility by the gcd before using
an inverse;enumerate one complete period on small inputs to verify the returned pair.

## What still needs independent practice

There is no defensible fixed number of examples that guarantees understanding. Use three
checks:implement without copying,explain the invariant,and solve a changed constraint.
The narrow specialist topics have introductions here;they do not yet have the breadth of
the core array,graph or DP sections. The audit makes that limitation visible.

