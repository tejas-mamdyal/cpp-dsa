# Learn each concept before using it

Use this route rather than alphabetically opening migrated folders. Read a unit's
notes first, then its programs in the listed order, then practice and checkpoints.
Concept explanations are kept near their use. Ask whether you understand an operation
before copying it;the guides cannot guarantee that every dependency is recognized.

The chapter guides provide the order. The notes below call out dependencies that differ
from simply sorting filenames.

## 1. Scalar programming before collections

Complete [Phase1](01-programming-foundations/README.md) in its eight-unit order.
Type notes preview comparison symbols and literal suffixes when first needed.
Read the dedicated scalar operator unit before formula applications; its four
bitwise applications follow loops. XOR precedes the single-number question.
Loop notes explain repetition before digit algorithms; function examples precede
projects. Read the gcd helper before the number toolkit, even on the shortened route.

The remaining Phase1 supplements use scalar variables and loops. String/iterator-
based base conversions have moved to a later STL application, not this beginner route.
Simple helpers such as min/max and finite-number checks are explained at their use.

## 2. Core C++ with precise dependencies

1. [Reviewed arrays/matrices](02-core-cpp/03-arrays-strings-vectors/01-arrays-and-matrices/README.md).
2. Strings and line input. Range-based character loops are explained locally.
3. Value/reference parameters, then pointers/null and pointer-versus-reference.
4. Vectors: their existing print helper takes a const reference, so references come first.
5. auto and range loops, then the 13 standalone [parsing examples](02-core-cpp/07-parsing/README.md).
6. Structs, classes, constructors and encapsulation; polymorphism uses a stack object and reference.
7. Dynamic storage, ownership/RAII and moves after object/lifetime basics.
8. [Basic exceptions](02-core-cpp/08-error-handling/README.md), then
   [file streams](02-core-cpp/09-file-streams/README.md), then persistence applications.

The expanded units include notes, practice, hints and checkpoints. Language
bridges in the exact index identify cross-unit dependencies. [Phase2's plan](02-core-cpp/PHASE2_PLAN.md) reflects this corrected order.
Read relevant [syntax bridges](reference/CPP_SYNTAX_BRIDGES.md) when opening a reference;
source comments repeat the relevant short explanations. The stoi conversion and
cleanup-on-exception examples follow exceptions; polymorphic deletion follows
dynamic storage; top-k selection follows the algorithm interfaces it calls.

## 3. Library interfaces before library-heavy problems

Pairs/tuples precede maps and structured bindings. Iterator ranges precede the
introductory sort call; a library API can be used before implementing its algorithm.
Then learn containers, simple comparators/lambdas, and
[captures/callable objects](03-standard-library/05-lambdas-comparators/02_function_objects_and_captures.cpp)
before custom algorithms and applications. Generic lambda parameters deduce types
at a call; captured references must not outlive their source objects.

Parsed frequency sorting belongs here: it needs a map, pairs, iterators and a
comparator in addition to the earlier parser. String-based number conversions also
belong here because they use string traversal/reverse iterator ranges.

## 4. Foundations before recursive and bit-based algorithms

## 5. Data structures, patterns, backtracking, trees and graphs

Follow chapters05–09. The exception introduction now precedes stack/queue/heap
implementations that throw. Named recursive helpers pass their state explicitly.
Basic recursion precedes tree cleanup/traversal and graph DFS.

The early interval chapter teaches greedy scheduling and interval union only.
Weighted interval profit is a DP problem and no longer appears before DP is taught.

## 6. DP and advanced topics

Read DP state/recurrence introduction before its families, including
[weighted scheduling](10-dynamic-programming/06-interval-and-partition/12_weighted_interval_schedule.cpp).
Bitmask states require the earlier bit lesson; tree DP requires tree traversal;
digit DP requires recursion and memoization. Individual source comments name
their prerequisites. Then use advanced ranges/strings/graphs/math, and later
engineering topics such as implementing templates and larger builds.

## Maintain the order

The first check verifies every active source is sequenced, tracked C++ constructs
are declared, and prerequisite introductions precede dependent programs. It includes
all active sources and ignores comments/literals. It distinguishes stream-output
lines from bit-shift heuristics. It is not a full C++ semantic or mathematical
proof: new algorithms still require a teaching review. The second check verifies
that moves did not leave missing destinations or broken documentation links.

For a new simple construct, explain it before its first statement and update the
then place dependent examples after it. Do not satisfy a prerequisite merely by
mentioning its name in a comment or marking a future unit as planned.

Phase5 follows its complete [nine-unit route](07-recursion-and-backtracking/README.md): decision trees, duplicate handling, partition/search, constraint puzzles, owned tree foundations, tree reasoning, BSTs, heaps, and tries. Both projects follow their tree/trie prerequisites. 

Phase6 released route: [75 worked programs](09-graphs/README.md),1 projects,with explicit unit prerequisites.

Phase7 released route: [100 worked programs](10-dynamic-programming/README.md),0 projects,with explicit unit prerequisites.

Phase8 released route: [90 worked programs](11-advanced-dsa/README.md),0 projects,with explicit unit prerequisites.

Phase9 released route: [40 worked programs](12-cpp-engineering/README.md),1 projects,with explicit unit prerequisites.

Phase10 released route: [60 worked programs](13-placement-preparation/README.md),0 projects,with explicit unit prerequisites.

