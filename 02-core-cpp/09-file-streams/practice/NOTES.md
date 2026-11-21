# Files serialization and persistence: notes

A round-trip format needs explicit boundaries, quoting/escaping, field validation and duplicate policies. Stage an entire load in a temporary collection and commit only when it is valid. The contact project demonstrates this. Direct overwriting saves are not crash-atomic; an atomic-replacement format and backup strategy are later production extensions, not an implied guarantee.

## Concepts in the worked programs

### 01 text round trip

Write a known record in a scratch build directory; close before opening an input stream.

Trace: Ada and42 survive the file round trip. Closing the output flushes buffered text before the input reads it.

### 02 append and line count

Write one line, append another, then count complete lines.

Trace: first then second -> two records. app directs every write to the file end, retaining the earlier line.

Cost: O(L) time, O(M) space for the longest line. Pitfall: Default ofstream truncates; do not accidentally use it when appending.

### 03 missing file

Try to open a deliberately absent file in a fresh scratch directory.

Trace: open fails; fail state is true; no record is read. A failed open sets stream failure instead of creating input data.

### 04 delimited record validation

Parse id,mark in two stages and reject any extra character. Keep the old record unchanged on failure.

Trace: 2,90 accepted;2,90x rejected; previous result remains2,90. Only a fully valid local candidate is assigned to persistent state.

Cost: O(L) parsing time/storage for L characters. Pitfall: Updating fields during parsing can leave a half-modified object after an error.

### 05 formatting flags

Stream manipulators control formatting; quoted text preserves spaces and quotes.

Trace: 3.5 becomes3.50; a quoted name is read back exactly. The writer escapes embedded quotes and the matching reader reverses that encoding.

Cost: O(L) time and storage for serialized text. Pitfall: Formatting flags persist on a stream; specify them intentionally. Use binary-safe/versioned formats for more demanding persistence.


