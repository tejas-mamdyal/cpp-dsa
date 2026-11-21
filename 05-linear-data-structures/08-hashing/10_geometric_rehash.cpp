/*
REHASH ALL KEYS WHEN BUCKET COUNT CHANGES PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Unique int keys; start with3 buckets,grow to2*b+1 when size exceeds2*b. IDEA AND
STATE: Compute each old key hash using the new bucket count and move its value. TRACE: After
several inserts the same keys remain findable under a larger bucket array. CORRECTNESS: Rehash
redistributes every key according to the new modulus; no key disappears or duplicates. COST:
Expected amortized O(1) insertion under distributed hashing; O(n+B) rehash; O(n+B) storage;
O(n) worst lookup. PITFALL: Changing the bucket count without redistributing keys makes old
keys unreachable. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class GrowingSet {
    std::vector<std::vector<int>> buckets = std::vector<std::vector<int>>(3);
    std::size_t count = 0;

    std::size_t index(int key, std::size_t size) const {
        long long h = static_cast<long long>(key) % static_cast<long long>(size);
        if (h < 0) {
            h += static_cast<long long>(size);
        }
        return static_cast<std::size_t>(h);
    }

    void grow() {
        std::vector<std::vector<int>> replacement(2 * buckets.size() + 1);
        for (const auto& bucket : buckets) {
            for (int value : bucket) {
                replacement[index(value, replacement.size())].push_back(value);
            }
        }
        buckets.swap(replacement);
    }

public:
    bool contains(int key) const {
        const auto& b = buckets[index(key, buckets.size())];
        return std::find(b.begin(), b.end(), key) != b.end();
    }

    bool insert(int key) {
        if (contains(key)) {
            return false;
        }
        buckets[index(key, buckets.size())].push_back(key);
        ++count;
        if (count > 2 * buckets.size()) {
            grow();
        }
        return true;
    }
};

int main() {
    GrowingSet set;
    for (int value = -100; value <= 100; ++value) {
        assert(set.insert(value));
    }
    for (int value = -110; value <= 110; ++value) {
        assert(set.contains(value) == (value >= -100 && value <= 100));
    }
    assert(!set.insert(7));
    std::cout << "checks passed\n";
    return 0;
}
