/*
 Unsigned byte-sized values; count nonempty ranges with requested XOR.

IDEA AND STATE: Current prefix XOR previous prefix equals target, so query frequency[current
XOR target].

TRACE: 4,2,2,6,4 target 6 ->4.

With target6,the prefix XOR6 finds initial XOR0;later repeated complementary prefixes
contribute four ranges overall.

Self-XOR cancels every prefix element before a range; frequencies retain all
starts.

Expected O(n) time, O(n) map space.

Seed the empty prefix and query before insertion.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

long long countXor(const std::vector<unsigned int>& a, unsigned int target) {
    std::unordered_map<unsigned int, long long> counts;
    counts[0] = 1;
    unsigned int value = 0;
    long long out = 0;
    for (unsigned int x : a) {
        value ^= x;
        auto found = counts.find(value ^ target);
        if (found != counts.end()) {
            out += found->second;
        }
        ++counts[value];
    }
    return out;
}

int main() {
    assert(countXor({4, 2, 2, 6, 4}, 6U) == 4);
    assert(countXor({0, 0}, 0U) == 3);
    assert(countXor({}, 0U) == 0);
    std::cout << "checks passed\n";
    return 0;
}
