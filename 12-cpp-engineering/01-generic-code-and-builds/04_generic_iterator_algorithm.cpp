/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

[first, last) is the unprocessed valid range.

aba contributes one match at positions 0 and 2.

Each visited element adds exactly its equality indicator.

O(n) comparisons, O(1) work.

Both iterators must describe the same valid range; do not dereference last.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

template <typename Iterator, typename Value>
int occurrences(Iterator first, Iterator last, const Value& wanted) {
    int count = 0;
    for (; first != last; ++first) {
        if (*first == wanted) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::vector<int> a{2, 1, 2};
    assert(occurrences(a.begin(), a.end(), 2) == 2);
    std::string s = "aba";
    assert(occurrences(s.begin(), s.end(), 'a') == 2);
    assert(occurrences(a.end(), a.end(), 2) == 0);
    std::cout << "checks passed\n";
    return 0;
}
