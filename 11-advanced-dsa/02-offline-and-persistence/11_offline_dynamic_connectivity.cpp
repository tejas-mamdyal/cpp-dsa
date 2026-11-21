/*
 Undirected simple graph, V<=30, T<=100; valid+,-,? events; no duplicate active add
or inactive remove.

Each edge is active on half-open time intervals; tree nodes cache edges
active throughout their time block; DSU snapshot scopes those edges to the current DFS branch.

0-1 alone cannot connect 0 to 2; adding 1-2 connects them; removing 0-1 breaks the
route.

Every query leaf inherits exactly the edges active at its time; rollback removes
ancestor-branch changes before visiting a sibling interval.

O(T log T log n) upper-bound time, O(T log T+n) storage for bounded valid batches.

A remove must match an active simple edge; parallel active copies need multiplicity
tracking.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
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

struct Event {
    char kind;
    int u;
    int v;
};

void insertInterval(std::vector<std::vector<std::pair<int, int>>>& tree,
                    int p,
                    int l,
                    int r,
                    int ql,
                    int qr,
                    std::pair<int, int> edge) {
    if (qr <= l || r <= ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        tree[p].push_back(edge);
        return;
    }
    int mid = l + (r - l) / 2;
    insertInterval(tree, 2 * p, l, mid, ql, qr, edge);
    insertInterval(tree, 2 * p + 1, mid, r, ql, qr, edge);
}

void visit(const std::vector<Event>& events,
           const std::vector<std::vector<std::pair<int, int>>>& tree,
           int p,
           int l,
           int r,
           Rollback& dsu,
           std::vector<bool>& out) {
    auto mark = dsu.snapshot();
    for (auto edge : tree[p]) {
        dsu.unite(edge.first, edge.second);
    }
    if (r - l == 1) {
        if (events[l].kind == '?') {
            out.push_back(dsu.find(events[l].u) == dsu.find(events[l].v));
        }
    } else {
        int mid = l + (r - l) / 2;
        visit(events, tree, 2 * p, l, mid, dsu, out);
        visit(events, tree, 2 * p + 1, mid, r, dsu, out);
    }
    dsu.rollback(mark);
}

std::vector<bool> connectivity(int n, const std::vector<Event>& events) {
    if (events.empty()) {
        return {};
    }
    int times = static_cast<int>(events.size());
    std::vector<std::vector<std::pair<int, int>>> tree(static_cast<std::size_t>(4 * times));
    std::map<std::pair<int, int>, int> active;
    for (int t = 0; t < times; ++t) {
        auto event = events[t];
        std::pair<int, int> edge{std::min(event.u, event.v), std::max(event.u, event.v)};
        if (event.kind == '+') {
            assert(active.count(edge) == 0);
            active[edge] = t;
        } else if (event.kind == '-') {
            auto found = active.find(edge);
            assert(found != active.end());
            insertInterval(tree, 1, 0, times, found->second, t, edge);
            active.erase(found);
        }
    }
    for (auto item : active) {
        insertInterval(tree, 1, 0, times, item.second, times, item.first);
    }
    Rollback dsu(n);
    std::vector<bool> out;
    visit(events, tree, 1, 0, times, dsu, out);
    return out;
}

int main() {
    assert((connectivity(
                3, {{'+', 0, 1}, {'?', 0, 2}, {'+', 1, 2}, {'?', 0, 2}, {'-', 0, 1}, {'?', 0, 2}})
            == std::vector<bool>{false, true, false}));
    assert(connectivity(0, {}).empty());
    std::cout << "checks passed\n";
    return 0;
}
