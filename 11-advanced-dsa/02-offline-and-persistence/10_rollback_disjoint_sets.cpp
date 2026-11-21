/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

history records attached root, parent root, and old parent size;
successful unions alone create log entries.

Rollback from merged 0,1,2 to the earlier 0,1 snapshot separates 2 again.

Undo in reverse mutation order restores every overwritten parent/size exactly;
root identities remain a valid partition forest.

O(log n) find/union from size balancing; O(1) undo per successful union; O(n+history)
storage.

Path compression would create additional unlogged parent writes; this version
intentionally omits it.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <array>
#include <cstddef>
#include <numeric>

class Rollback {
    std::vector<int> parent;
    std::vector<int> size;
    std::vector<std::array<int, 3>> history;
    int groups;

public:
    explicit Rollback(int n)
        : parent(static_cast<std::size_t>(n)),
          size(static_cast<std::size_t>(n), 1),
          groups(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) const {
        while (parent[u] != u) {
            u = parent[u];
        }
        return u;
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        history.push_back({b, a, size[a]});
        parent[b] = a;
        size[a] += size[b];
        --groups;
        return true;
    }

    std::size_t snapshot() const {
        return history.size();
    }

    void rollback(std::size_t mark) {
        assert(mark <= history.size());
        while (history.size() > mark) {
            auto entry = history.back();
            history.pop_back();
            parent[entry[0]] = entry[0];
            size[entry[1]] = entry[2];
            ++groups;
        }
    }

    int components() const {
        return groups;
    }
};

int main() {
    Rollback d(4);
    auto first = d.snapshot();
    d.unite(0, 1);
    auto second = d.snapshot();
    d.unite(1, 2);
    assert(d.components() == 2);
    d.rollback(second);
    assert(d.find(0) != d.find(2) && d.components() == 3);
    d.rollback(first);
    assert(d.components() == 4);
    std::cout << "checks passed\n";
    return 0;
}
