/*
TRANSFORM COPY AND PREDICATE ALGORITHMS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Pre-size destinations or use an output inserter; all_of on an empty range is true.
Trace: 1,2,3 doubles2,4,6 and filtering retains2,3.
Why it works: transform writes one result per source element; back_inserter grows the destination safely.
Cost: O(n) calls and O(n) destination storage.
Common mistake: Writing through emptyVector.begin() is invalid; reserve alone does not create output elements.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> source = {1, 2, 3};
    std::vector<int> doubled(source.size());
    std::transform(source.begin(), source.end(), doubled.begin(), [](int x) {
        return x * 2;
    });
    assert((doubled == std::vector<int>{2, 4, 6}));
    std::vector<int> selected;
    std::copy_if(source.begin(), source.end(), std::back_inserter(selected), [](int x) {
        return x > 1;
    });
    assert((selected == std::vector<int>{2, 3}));
    assert(std::all_of(selected.begin(), selected.end(), [](int x) {
        return x > 0;
    }));
    assert(std::none_of(source.begin(), source.end(), [](int x) {
        return x < 0;
    }));
    std::cout << "checks passed\n";
}
