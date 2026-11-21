/*
NAMESPACES AND SCOPE RESOLUTION PREVENT COLLISIONS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Use :: to select a global, namespace or class name.
Trace: global value1 and school::value2 remain different names.
Why it works: Qualified lookup selects the intended scope explicitly.
Cost: O(1) time/space.
Common mistake: Avoid using namespace directives in shared headers; local shadowing can obscure which value is used.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

int value = 1;

namespace school {
inline constexpr int value = 2;

struct Record {
    static constexpr int maximum = 100;
};
} // namespace school

int main() {
    int value = 3;
    assert(value == 3);
    assert(::value == 1);
    assert(school::value == 2);
    assert(school::Record::maximum == 100);
    std::cout << "checks passed\n";
}
