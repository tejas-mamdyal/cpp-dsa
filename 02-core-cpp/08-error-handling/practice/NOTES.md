# Errors validation and stream recovery: notes

Use ordinary return status/optional for expected absence and exceptions when an operation cannot fulfill its contract. Catch polymorphic exceptions by const reference and put specific handlers before general ones. Stack unwinding destroys fully constructed automatic objects. A noexcept promise is distinct from catching an error.

Assertions document internal assumptions and may be disabled; external input must be validated with ordinary control flow. The worked harnesses intentionally run with assertions enabled. Stream recovery needs clear to reset flags and ignore to discard offending input. Retrying without consuming the bad text repeats the same failure.

## Concepts in the worked programs

### 01 throw and catch

Reject a negative square side using invalid_argument.

Trace: side3 ->9; side-1 -> catch. Invalid input is rejected before multiplication.

Cost: O(1) normal path; exceptional runtime overhead is implementation-dependent. Pitfall: Catch derived exception types before their base classes; catching by value can slice exception information.

### 02 optional result

Return optional<int> for a missing integer; check engagement before dereference.

Trace: nonempty vector minimum-2; empty input nullopt. An explicit absence state avoids inventing an int sentinel.

Cost: O(n) time in the length of the data; O(1) auxiliary space. Pitfall: Never dereference a disengaged optional; absence is not necessarily an exception.

### 03 stream recovery

clear resets failure state, ignore discards the malformed line, then extraction can resume.

Trace: oops then42: first extraction fails, recovered extraction succeeds. Both failure flags and offending characters must be handled before retrying.

Cost: O(L) time to skip a malformed line of L characters; O(1) extra space. Pitfall: clear alone leaves the same bad text waiting and can create an infinite retry loop.

### 04 noexcept expression

noexcept(expression) is a compile-time boolean and does not execute the expression. A noexcept function promises not to let exceptions escape.

Trace: safe is declared noexcept; risky is not, regardless of its body. The operator examines the exception specification without evaluating a call.

Cost: O(1) runtime work; noexcept inspection itself is compile-time. Pitfall: An escaping exception from a noexcept function terminates the program. This is not a try/catch replacement.

### 05 assert vs validation

Validate external values with control flow, then assert an internal postcondition.

Trace: mark-1 returns false; mark75 succeeds. The guard prevents invalid mutation; the assertion documents the maintained invariant.

Cost: O(1) time and space. Pitfall: Assertions may be disabled with NDEBUG. Never put a required user-input validation or important side effect only inside assert in production code.


