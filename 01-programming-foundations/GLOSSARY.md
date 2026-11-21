# Phase 1 glossary

| Term | Meaning in this course |
|---|---|
| Algorithm | A finite, unambiguous method for solving a problem |
| Program | Instructions expressed in a programming language |
| Source | Human-readable program text, here a .cpp file |
| Compiler | Tool that checks and translates source |
| Linker | Tool that connects definitions and runtime support into an executable |
| Executable | A compiled program that the operating system can run |
| Standard library | C++'s supplied interfaces, such as streams and numeric limits |
| Header | File of declarations made available with #include |
| Namespace | A naming scope; std contains standard-library names |
| Statement | A program step, often ended by a semicolon |
| Expression | Code that computes a value |
| Literal | A value written directly, such as7, true or 'A' |
| Variable | Named storage with a type and value |
| Declaration | Introduction of a name and its type |
| Initialization | Giving an object its initial value |
| Assignment | Replacing a stored value using = |
| Type | Rules for a value's representation and operations |
| int | A finite-range signed whole-number type |
| long long | A signed integer type with at least64 bits, used for larger totals |
| double | An approximate floating-point type |
| char | A character-code storage type; not a full Unicode text character in general |
| bool | A true/false value |
| const | Declares an object that cannot be reassigned through that name |
| Cast | An explicit conversion, such as static_cast<double>(x) |
| Overflow | A result exceeds a type's representable range; signed overflow is undefined |
| Undefined behavior | The language provides no required outcome for an invalid operation |
| Stream | A sequence-oriented input/output interface |
| std::cin | Standard input stream |
| std::cout | Standard output stream for results |
| std::cerr | Error output stream |
| Extraction | Reading a formatted value with >> |
| Insertion | Sending output with << |
| Escape sequence | Source notation for a special character, such as \\n |
| Precedence | Rules deciding how operations group |
| Short circuit | Skip the right operand of && or || when the answer is already determined |
| Branch | A selected block of conditional execution |
| Loop | Repetition controlled by a condition |
| Iteration | One execution of a loop body |
| Accumulator | State holding a running aggregate, such as a sum |
| Invariant | A property preserved by an algorithm step |
| Sentinel | A special input value that signals termination and is not ordinary data |
| Function | A named unit of behavior with an interface |
| Parameter | Local input name in a function declaration/definition |
| Argument | A value supplied by a call |
| Return value | Result delivered from a function back to its caller |
| void | No returned value |
| Scope | Region where a name can be used |
| Lifetime | Time during which an object exists |
| Pass by value | Copy the argument value into a local parameter |
| Overload | Same function name with different parameter lists |
| Precondition | Assumption that must hold before an operation |
| Postcondition | Property guaranteed after a successful operation |
| Test case | Input plus expected behavior/output |
| Boundary case | Input at or next to a permitted limit |
| Regression | A previously fixed behavior fails again |
| Assertion | A programmer check that may be disabled in release builds |
| Oracle | An independent way to determine an expected result |
| Breakpoint | A debugger location at which execution pauses |
| Call stack | The chain of active function calls |
| Time complexity | How work grows with a defined input-size measure |
| Auxiliary space | Extra working memory, apart from input/output storage |

For O(n), doubling n roughly doubles the dominant work. O(1) means a bounded
amount of work relative to the chosen size measure, not instantaneous execution.
Digit loops use d=number of digits; printed patterns must account for output size.

