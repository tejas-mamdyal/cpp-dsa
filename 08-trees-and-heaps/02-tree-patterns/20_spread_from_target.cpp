/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

First record each borrowed node parent; then BFS from a present target
across parent and children with a visited set.

Starting at sample leaf 1 reaches 2 in 1,4 and 3 in 2,6 in 3, and 5,7 in 4; total 4 steps.

Each BFS layer is one additional edge away; visited prevents immediately returning
across the same edge.

O(n log(n+1)) time with ordered map/set, O(n) storage.

The parent map borrows nodes; it must not outlive the owned tree. This local wave
model precedes general graph BFS in Phase 6.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <memory>
#include <queue>
#include <map>
#include <set>
#include <cstddef>

// Each child is owned by exactly one unique_ptr. Raw Node* below only borrows.
struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int x)
        : value(x) {
    }
};

using Tree = std::unique_ptr<Node>;

Tree node(int value) {
    return std::make_unique<Node>(value);
}

Tree sample() {
    auto root = node(4);
    root->left = node(2);
    root->right = node(6);
    root->left->left = node(1);
    root->left->right = node(3);
    root->right->left = node(5);
    root->right->right = node(7);
    return root;
}

std::optional<int> spread(const Node* root, const Node* target) {
    if (!root || !target) {
        return std::nullopt;
    }
    std::map<const Node*, const Node*> parent;
    std::queue<const Node*> q;
    parent[root] = nullptr;
    q.push(root);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (auto child : {p->left.get(), p->right.get()}) {
            if (child) {
                parent[child] = p;
                q.push(child);
            }
        }
    }
    if (parent.count(target) == 0) {
        return std::nullopt;
    }
    std::set<const Node*> seen{target};
    q.push(target);
    int time = -1;
    while (!q.empty()) {
        std::size_t size = q.size();
        ++time;
        for (std::size_t i = 0; i < size; ++i) {
            auto p = q.front();
            q.pop();
            for (const Node* next :
                 std::vector<const Node*>{p->left.get(), p->right.get(), parent[p]}) {
                if (next && seen.insert(next).second) {
                    q.push(next);
                }
            }
        }
    }
    return time;
}

int main() {
    auto root = sample();
    assert(spread(root.get(), root->left->left.get()) == 4);
    auto external = node(8);
    assert(!spread(root.get(), external.get()));
    assert(!spread(nullptr, nullptr));
    std::cout << "checks passed\n";
    return 0;
}
