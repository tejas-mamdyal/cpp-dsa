/*
GENERIC LAMBDA PARAMETERS DEDUCE ARGUMENT TYPES
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: auto parameters produce a suitable call operator for each used argument type.
Trace: twice3=6; twice2.5=5; string ab ->abab.
Why it works: Each call instantiates a parameter type whose + operation supplies the result.
Cost: Numeric calls O(1); string concatenation O(n) time and output storage.
Common mistake: Generic does not mean every type is supported; the requested operations must exist.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>

int main() {
    auto twice = [](const auto& value) {
        return value + value;
    };
    assert(twice(3) == 6);
    assert(twice(2.5) == 5.0);
    assert(twice(std::string("ab")) == "abab");
    std::cout << "checks passed\n";
}
