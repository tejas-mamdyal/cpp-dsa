/*
DISTINCT INTERSECTION AND UNION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Hash sets remove duplicates; output sorted order is established separately.
Trace: 1,2,2 and2,3 intersect at2 and union to1,2,3.
Why it works: Sets encode distinct membership; each first-set key is considered only once.
Cost: Expected O(n+m+k log k), worst hashing may be quadratic; O(n+m) storage.
Common mistake: A set intersection ignores multiplicity; multiset intersection is a different question.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::unordered_set<int> first = {1, 2, 2};
    std::unordered_set<int> second = {2, 3};
    std::vector<int> intersection;
    for (int value : first) {
        if (second.count(value) != 0) {
            intersection.push_back(value);
        }
    }
    std::sort(intersection.begin(), intersection.end());
    assert((intersection == std::vector<int>{2}));
    first.insert(second.begin(), second.end());
    assert(first.size() == 3);
    std::cout << "checks passed\n";
}
