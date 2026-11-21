/*
SEPARATE CHAINING MAKES COLLISIONS VISIBLE PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Set of int keys with5 buckets; duplicate insertions are ignored. IDEA AND STATE:
Normalize a remainder to a bucket, then search only that bucket. TRACE: 1,6,11 collide in
bucket1 but remain distinct keys. CORRECTNESS: Every key stays in the bucket selected by its
hash; equality resolves collisions. COST: O(1+load) expected lookup with distributed keys,O(n)
worst; O(n+5) storage. PITFALL: A collision does not mean equality; negative remainders need
normalization. PRACTICE: Change the example, predict each state update and add an
empty/boundary case. No input unless explicitly stated. Assertions are the teaching test
harness and must remain enabled; success prints checks passed. These bounds describe the
helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class ChainedSet {
    std::vector<std::vector<int>> buckets = std::vector<std::vector<int>>(5);

    std::size_t index(int key) const {
        int value = key % 5;
        if (value < 0) {
            value += 5;
        }
        return static_cast<std::size_t>(value);
    }

public:
    bool contains(int key) const {
        const auto& bucket = buckets[index(key)];
        return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
    }

    bool insert(int key) {
        if (contains(key)) {
            return false;
        }
        buckets[index(key)].push_back(key);
        return true;
    }

    bool erase(int key) {
        auto& bucket = buckets[index(key)];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it == bucket.end()) {
            return false;
        }
        bucket.erase(it);
        return true;
    }
};

int main() {
    ChainedSet set;
    assert(set.insert(1));
    assert(set.insert(6));
    assert(set.insert(11));
    assert(set.contains(6));
    assert(!set.insert(6));
    assert(set.erase(6));
    assert(!set.contains(6));
    assert(set.contains(11));
    assert(set.insert(-4));
    assert(set.contains(-4));
    std::cout << "checks passed\n";
    return 0;
}
