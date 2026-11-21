# Basic exceptions before implementations use them

Use [the expanded errors unit](practice/README.md) for worked examples, notes, exercises, hints and checkpoint.

Prerequisites: functions, references, classes and polymorphic interfaces.
Read [throw/try/catch](01_exceptions.cpp) before stack/queue/heap implementations
throw standard exceptions. throw leaves normal control flow and unwinds automatic
objects until a matching catch; catching by const reference avoids slicing/copies.
Input validation may still use ordinary conditions and status returns. This
introduction is no longer deferred to the engineering chapter.

