/*
TWO MAPS ENFORCE A BIJECTION PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Equal-length byte strings; compare exact char units. IDEA AND STATE: Map left->right
and right->left so neither side can collapse distinct characters. TRACE: egg/add true;ab/aa
false. CORRECTNESS: Each processed pair respects both directions of the same one-to-one
mapping. COST: Expected O(n) time,O(u) map storage; byte alphabet bounds u. PITFALL: A single
forward map permits two source characters to share a destination. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

bool isomorphic(const std::string& a, const std::string& b) {
    if (a.size() != b.size()) {
        return false;
    }
    std::unordered_map<char, char> forward;
    std::unordered_map<char, char> backward;
    for (std::size_t i = 0; i < a.size(); ++i) {
        auto f = forward.find(a[i]);
        auto r = backward.find(b[i]);
        if ((f != forward.end() && f->second != b[i])
            || (r != backward.end() && r->second != a[i])) {
            return false;
        }
        forward[a[i]] = b[i];
        backward[b[i]] = a[i];
    }
    return true;
}

int main() {
    assert(isomorphic("egg", "add"));
    assert(!isomorphic("ab", "aa"));
    assert(isomorphic("paper", "title"));
    assert(isomorphic("", ""));
    assert(!isomorphic("a", ""));
    std::cout << "checks passed\n";
    return 0;
}
