/*
 Nonnegative appetites/cookie sizes; one cookie per child.

IDEA AND STATE: Sort copies; advance a child only when the cookie meets its appetite.

TRACE: children 1,2,3; cookies 1,1 ->1.

The first size1 cookie satisfies appetite1;the next size1 cannot satisfy appetite2,so only one
child is served.

Using a larger sufficient cookie for the easiest child can be exchanged with the
smaller sufficient one without harming other matches.

O(n log n+m log m) time, O(n+m) copied input.

A cookie cannot be divided among children in this contract.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int cookies(std::vector<int> needs, std::vector<int> sizes) {
    std::sort(needs.begin(), needs.end());
    std::sort(sizes.begin(), sizes.end());
    std::size_t child = 0;
    for (int size : sizes) {
        if (child < needs.size() && size >= needs[child]) {
            ++child;
        }
    }
    return static_cast<int>(child);
}

int main() {
    assert(cookies({1, 2, 3}, {1, 1}) == 1);
    assert(cookies({1, 2}, {1, 2, 3}) == 2);
    assert(cookies({}, {1}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
