/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

recent lists most recently used first; lookup or replacement moves an
entry to the front. In FastCache,position maps every key to its unique live list node.
Splice changes recency without invalidating node iterators;eviction removes both representations.

Access 1 before inserting 3 evicts 2 from capacity 2.

Every successful access updates recency; overflow removes exactly the least
recent key. The hash/list invariant is preserved by updates,splicing and paired eviction.

The vector reference costs O(capacity) per operation. The list+hash version has
expected amortized O(1) get/put and O(capacity) storage;adversarial hash collisions can make a lookup linear.

Updating an existing key must not create a duplicate or evict an unrelated entry.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <cstddef>
#include <list>
#include <unordered_map>
#include <iterator>

class Cache {
    std::size_t capacity;
    std::vector<std::pair<int, int>> recent;

public:
    explicit Cache(std::size_t n)
        : capacity(n) {
    }

    std::optional<int> get(int key) {
        for (std::size_t i = 0; i < recent.size(); ++i) {
            if (recent[i].first == key) {
                auto item = recent[i];
                recent.erase(recent.begin() + static_cast<std::ptrdiff_t>(i));
                recent.insert(recent.begin(), item);
                return item.second;
            }
        }
        return std::nullopt;
    }

    void put(int key, int value) {
        get(key);
        if (!recent.empty() && recent[0].first == key) {
            recent.erase(recent.begin());
        }
        if (capacity == 0) {
            return;
        }
        recent.insert(recent.begin(), {key, value});
        if (recent.size() > capacity) {
            recent.pop_back();
        }
    }
};

// Optimized version: list nodes remain valid when spliced to the front.
// The hash table points directly to nodes,so lookup no longer scans recency.
class FastCache {
    using Items = std::list<std::pair<int, int>>;
    std::size_t capacity;
    Items recent;
    std::unordered_map<int, Items::iterator> position;

public:
    explicit FastCache(std::size_t n)
        : capacity(n) {
    }

    // Copying these iterators would refer to the other object's list.
    // This get/put-only interface intentionally prohibits copying and moving.
    FastCache(const FastCache&) = delete;
    FastCache& operator=(const FastCache&) = delete;

    std::optional<int> get(int key) {
        auto found = position.find(key);
        if (found == position.end()) {
            return std::nullopt;
        }
        recent.splice(recent.begin(), recent, found->second);
        return found->second->second;
    }

    void put(int key, int value) {
        auto found = position.find(key);
        if (found != position.end()) {
            found->second->second = value;
            recent.splice(recent.begin(), recent, found->second);
            return;
        }
        if (capacity == 0) {
            return;
        }
        recent.push_front({key, value});
        position.emplace(key, recent.begin());
        if (recent.size() > capacity) {
            auto oldest = std::prev(recent.end());
            position.erase(oldest->first);
            recent.pop_back();
        }
    }
};

int main() {
    Cache c(2);
    c.put(1, 10);
    c.put(2, 20);
    assert(c.get(1) == 10);
    c.put(3, 30);
    assert(!c.get(2) && c.get(3) == 30);
    c.put(1, 99);
    assert(c.get(1) == 99);
    Cache zero(0);
    zero.put(1, 2);
    assert(!zero.get(1));
    for (std::size_t capacity = 0; capacity <= 5; ++capacity) {
        for (int seed = 0; seed < 20; ++seed) {
            Cache reference(capacity);
            FastCache optimized(capacity);
            for (int step = 0; step < 150; ++step) {
                int key = (seed * 7 + step * 11) % 13;
                if ((seed + step) % 3 == 0) {
                    assert(reference.get(key) == optimized.get(key));
                } else {
                    int value = (seed + step) % 43;
                    reference.put(key, value);
                    optimized.put(key, value);
                }
            }
            for (int key = 0; key < 13; ++key) {
                assert(reference.get(key) == optimized.get(key));
            }
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
