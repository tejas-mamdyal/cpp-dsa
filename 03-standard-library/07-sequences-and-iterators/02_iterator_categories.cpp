/*
ITERATOR CAPABILITIES DEPEND ON THE CONTAINER
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Vector iterators support addition/subtraction; list iterators require stepping with advance/distance.
Trace: vector begin+2 reads30; list advanced2 also reads30.
Why it works: Both ranges are half-open, but only random-access iterators support arithmetic.
Cost: Vector jumps/distance O(1); list advance/distance O(n).
Common mistake: Do not write list.begin()+2; container interfaces reveal different traversal costs.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <iterator>

int main() {
    std::vector<int> values = {10, 20, 30};
    assert(*(values.begin() + 2) == 30);
    assert(values.end() - values.begin() == 3);
    std::list<int> linked = {10, 20, 30};
    auto it = linked.begin();
    std::advance(it, 2);
    assert(*it == 30);
    assert(std::distance(linked.begin(), linked.end()) == 3);
    std::cout << "checks passed\n";
}
