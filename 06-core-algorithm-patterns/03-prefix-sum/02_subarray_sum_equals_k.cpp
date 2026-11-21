/*
 Signed values; count nonempty subarrays summing to target.

IDEA AND STATE: For current prefix s, each previous s-target begins one valid range; query
before inserting s.

TRACE: 1,-1,0 target 0 ->3.

Prefixes1,0,0 find respectively0,1,2 earlier matching prefixes for target0,total3.

A range sum is the difference of its ending and preceding prefix; frequency
retains every possible start.

Expected O(n) time, O(n) map storage; worst hashing can be quadratic.

Seed frequency 0 as 1 and do not insert the current prefix before querying.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

long long countSum(const std::vector<int>& a, long long target) {
    std::unordered_map<long long, long long> frequency;
    frequency[0] = 1;
    long long sum = 0;
    long long result = 0;
    for (int value : a) {
        sum += value;
        auto it = frequency.find(sum - target);
        if (it != frequency.end()) {
            result += it->second;
        }
        ++frequency[sum];
    }
    return result;
}

int main() {
    assert(countSum({1, -1, 0}, 0) == 3);
    assert(countSum({1, 1, 1}, 2) == 2);
    assert(countSum({0, 0}, 0) == 3);
    assert(countSum({}, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
