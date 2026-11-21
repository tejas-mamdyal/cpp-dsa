/*
list::splice relinks existing list nodes instead of copying their values. The single-element operation used here is constant time and preserves iterators to moved elements. Cross-list splicing requires compatible allocators; range forms can have different complexity.
*/
/*
SPLICE LIST NODES WITHOUT COPYING ELEMENTS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Move one node between standard lists with compatible allocators. Existing iterators to the moved element remain valid.
Trace: move2 from1,2,3 to end of4 ->1,3 and4,2.
Why it works: Relinking the selected node preserves its value and identity.
Cost: O(1) single-node splice; O(n) stored nodes.
Common mistake: The destination position belongs to the destination list; source and destination allocator compatibility is required.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <list>

int main() {
    std::list<int> source = {1, 2, 3};
    std::list<int> destination = {4};
    auto moved = source.begin();
    ++moved;
    destination.splice(destination.end(), source, moved);
    assert(*moved == 2);
    assert(source.size() == 2 && destination.size() == 2);
    assert(source.front() == 1 && source.back() == 3);
    assert(destination.front() == 4 && destination.back() == 2);
    std::cout << "checks passed\n";
}
