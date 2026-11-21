/*
 Disjoint sorted singly linked lists; consume their unique_ptr heads and relink the
existing nodes, without copying values into new nodes. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

Each heap item borrows a head and records its owning list index; pop moves
that head into the result and replaces the head by its successor.

Lists 1->4,1->3,2->6 become 1->1->2->3->4->6; all original head owners end null.

The minimum-frontier proof gives sorted order; each node is moved once from
exactly one owner into the result chain.

O(N log(k+1)+k) time, O(k) heap beyond owned nodes; recursive unique_ptr destruction uses
O(N) depth for the bounded lists.

Never put an owning unique_ptr copy into two places; the heap only borrows while list
heads own.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <cstddef>

struct ListNode {
    int value;
    std::unique_ptr<ListNode> next;

    explicit ListNode(int x)
        : value(x) {
    }
};

using List = std::unique_ptr<ListNode>;

List make(const std::vector<int>& a) {
    List head;
    auto slot = &head;
    for (int x : a) {
        *slot = std::make_unique<ListNode>(x);
        slot = &((*slot)->next);
    }
    return head;
}

struct Item {
    const ListNode* node;
    std::size_t list;
};

struct Later {
    bool operator()(const Item& a, const Item& b) const {
        return a.node->value > b.node->value;
    }
};

List merge(std::vector<List>& heads) {
    std::priority_queue<Item, std::vector<Item>, Later> q;
    for (std::size_t i = 0; i < heads.size(); ++i) {
        if (heads[i]) {
            q.push({heads[i].get(), i});
        }
    }
    List result;
    auto slot = &result;
    while (!q.empty()) {
        auto item = q.top();
        q.pop();
        auto chosen = std::move(heads[item.list]);
        heads[item.list] = std::move(chosen->next);
        if (heads[item.list]) {
            q.push({heads[item.list].get(), item.list});
        }
        *slot = std::move(chosen);
        slot = &((*slot)->next);
    }
    return result;
}

int main() {
    std::vector<List> heads;
    heads.push_back(make({1, 4}));
    heads.push_back(make({1, 3}));
    heads.push_back(make({2, 6}));
    auto root = merge(heads);
    std::vector<int> out;
    for (auto p = root.get(); p; p = p->next.get()) {
        out.push_back(p->value);
    }
    assert((out == std::vector<int>{1, 1, 2, 3, 4, 6}));
    for (const auto& head : heads) {
        assert(!head);
    }
    std::cout << "checks passed\n";
    return 0;
}
