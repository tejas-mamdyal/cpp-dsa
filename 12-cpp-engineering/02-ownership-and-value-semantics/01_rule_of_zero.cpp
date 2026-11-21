/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Record owns its string and vector and needs no custom special members.

Copy then change b: the vector in a remains unchanged.

Memberwise value copies delegate resource management to standard types.

O(total member data) copy/storage.

Adding a raw owning pointer would invalidate this simple ownership story.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

struct Record {
    std::string name;
    std::vector<int> marks;
};

int main() {
    Record a{"Ada", {3, 4}};
    Record b = a;
    b.marks[0] = 9;
    assert(a.marks[0] == 3 && b.marks[0] == 9);
    std::cout << "checks passed\n";
    return 0;
}
