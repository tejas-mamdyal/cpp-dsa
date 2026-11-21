# Data-structure toolkit project

[01_data_structure_toolkit.cpp](01_data_structure_toolkit.cpp) is a standalone C++17
reference implementation. Complete all Phase3 unit checkpoints before using it.
The sequence owns a vector,the list uniquely owns nodes,and the stack/queue use
actual bounded arrays. Parsing,models and output are separate functions/classes.

## Command contract

One command per line;EOF or QUIT ends normally. Values must be ints in
[-1000000,1000000]. Sequence/list capacity is1000 elements;stack/queue capacity8.
There is no command-count quota. Bounds limit stored data,not how long a session runs.

| Model | Commands |
|---|---|
|Sequence|SEQ_PUSH value;SEQ_INSERT index value;SEQ_ERASE index;SEQ_REVERSE;SEQ_SORT;SEQ_FIND value;SEQ_SHOW|
|List|LIST_PUSH_FRONT value;LIST_PUSH_BACK value;LIST_INSERT index value;LIST_ERASE index;LIST_REVERSE;LIST_FIND value;LIST_SHOW|
|Stack|STACK_PUSH value;STACK_POP;STACK_PEEK|
|Queue|QUEUE_PUSH value;QUEUE_POP;QUEUE_FRONT|
|Control|RESET;CHECK;SELFTEST;QUIT|

Semicolons in the table separate command descriptions,not input syntax. Enter each
command on its own line. Indices are zero-based:insert permits0..size;erase requires
0..size-1. FIND returns the first index or-1. SHOW prints one normalized line;
empty data prints a blank line. Successful mutations print OK;erasures/pops print
the removed value;empty stack/queue observations print EMPTY;capacity rejection
prints FULL without mutation. Invalid syntax/value/index prints stderr and exits1;
earlier successful output remains. No personal files are read or written.

```text
LIST_PUSH_BACK 1
LIST_PUSH_FRONT 2
LIST_INSERT 1 3
LIST_REVERSE
LIST_SHOW
STACK_PUSH 9
STACK_POP
QUEUE_PUSH 4
QUEUE_PUSH 5
QUEUE_POP
CHECK
QUIT
```

Expected output:

```text
OK
OK
OK
OK
1 3 2
OK
9
OK
OK
4
valid
```

## Ownership and invariants

A nonempty list has live head/tail,tail.next=null and exactly size reachable nodes.
Empty means both endpoints null. The owner disables copying to prevent double
release and deletes iteratively. Reversal updates tail to the old head. A failed
index/value command validates before touching state. CHECK inspects the list
invariant and live-node count. RESET reclaims list nodes and empties every model.

The stack count defines live array positions. The ring queue stores logical front
and used count;full and empty never depend only on equal physical indices. Front
advances modulo the positive fixed capacity. These mechanisms are implemented here;
std::vector/std::deque are independent test models rather than replacements for
the owning list or ring implementation.

## Cost ledger

| Operation | Time | Additional working memory |
|---|---|---|
|Sequence append|Amortized O(1)|Possible vector growth|
|Sequence insert/erase|O(n)|O(1),apart from possible allocation|
|Sequence insertion sort|O(n^2) worst|O(1)|
|First-match find|O(n)|O(1)|
|List endpoint insertion|O(1)|One new node|
|List positional insert/erase|O(n)|O(1),plus inserted node|
|List reverse|O(n)|O(1)|
|Stack/ring operations|O(1)|Fixed capacity storage|
|CHECK/RESET|O(n)|O(1),excluding existing storage|

Parsing a command line of L characters costs O(L) time and temporary memory;
the model-operation table excludes that parsing work.

## Independent checks

SELFTEST compares200 mixed list/stack/queue steps with vector/deque models after
every step,including equality of returned values,status,front/top and list order.
It checks1000-node capacity rejection and live-node restoration. Assertions must
stay enabled for teaching tests;external input validation does not use assertions.

wrap/full/empty behavior,capacity1000,negative/index errors,trailing junk and reset.
A separate invariant harness verifies that rejected commands preserve data and
output and that destruction reclaims all allocations,including a populated owner.

Run the generated executable from the repository root and enter commands. Try
SELFTEST followed by CHECK,then a sequence of your own. A bounded passing oracle
is evidence for tested operations,not a universal memory/correctness proof.

## Project assessment:40 points

Implement from this contract before reading the reference. Score each category/8:
representation and invariants;complete commands/validation;ownership and cleanup;
independent normal/boundary/error checks;clear decomposition and time/space account.
Aim for32/40 with no unsafe copy,dangling access,unchecked index or leaked node.
Extensions:deep-copyable list,transactional command batches,logging,and a doubly
linked model. Update the contract and tests before adding a feature.

