/*
decltype(expression) names a type without evaluating the expression. An unparenthesized variable gives its declared type; decltype((variable)) can produce a reference type because the parenthesized expression is an lvalue. Unlike auto, decltype can preserve references.
*/
/*
FUNDAMENTAL TYPES QUALIFIERS AND ALIASES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Recognize bool, character types, signed/unsigned integer families, floating types, void and nullptr_t. Exact widths are implementation-defined.
Trace: int alias3; unsigned limit positive; constexpr count4.
Why it works: Type declarations select representation and allowed operations; const forbids mutation through that name.
Cost: O(1) demonstration.
Common mistake: volatile is not a thread-synchronization tool. Fixed-width cstdint aliases exist only when supported; numeric_limits reports implementation properties.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <type_traits>
#include <limits>
#include <cstddef>

int main() {
    using Count = long long;
    Count count = 3;
    const int fixed = 4;
    constexpr int limit = 4;
    auto inferred = 2.5;
    decltype(count) copied = count;
    volatile int hardwareStyle = 0;
    (void)hardwareStyle;
    assert(count == 3 && copied == 3);
    assert(fixed == limit);
    static_assert(std::is_same<decltype(inferred), double>::value, "auto retains double");
    static_assert(std::numeric_limits<unsigned int>::is_integer, "unsigned is integral");
    assert(std::numeric_limits<unsigned int>::min() == 0);
    char16_t letter = u'A';
    assert(letter == 65);
    std::nullptr_t absent = nullptr;
    assert(absent == nullptr);
    std::cout << "checks passed\n";
}
