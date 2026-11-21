# Library applications: notes

These bridge examples connect earlier units; follow the exact reading order rather than treating this directory as a new prerequisite. Standard type traits query compile-time properties; they do not require writing a generic template. Default arguments fill omitted trailing values. constexpr permits constant evaluation and static locals retain state. Positional number conversion repeatedly divides by a base for output, or multiplies and adds a checked digit for input. Perform an overflow guard before the operation, not afterward. An unordered iteration order is unspecified; deterministic answers need explicit tie policies.

Types are part of computation, not just storage. unsigned wraps but mixed signed/unsigned comparisons can surprise; use a known representable range and convert deliberately. char/wchar_t/char16_t/char32_t are distinct character types; Unicode text needs an encoding policy. float/double/long double are approximate; bool represents truth, void represents no returned value, and nullptr has nullptr_t. const describes non-mutation through a name; volatile is for special observable access, not thread synchronization. using creates an alias, auto deduces an initializer type and decltype queries expression type.

For base conversion, value*base+digit appends a digit only when digit is in range. Check value<=(max-digit)/base first. Output digits arrive least-significant first and must be reversed; zero still needs one digit. Token-based conversion consumes one input token; extra later tokens are outside that example's required fields.

Integer power/default examples use nonnegative exponents and small values with representable products. Overload resolution depends on parameter types/counts, not return type alone. A default argument must not create ambiguity with another overload. A static local retains its object across calls; a constexpr function can also execute at runtime.

