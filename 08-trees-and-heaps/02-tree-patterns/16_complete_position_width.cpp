/*
 Owned binary tree with at most 100 nodes and edge-height at most 30; return
complete-position width including interior null gaps. Unless narrowed, at most 100
nodes/elements with values in [-1000,1000]. Recursive examples assume valid acyclic owned
structures; exponential searches use the smaller bounds stated here. No input; keep assertions
enabled. Success prints checks passed.

BFS carries complete-tree indices; normalize each level by its first index
to avoid unnecessary growth.

Root with left-left and right-right grandchildren has width 4 despite only two real
nodes at that depth.

Positions encode missing interior slots; last-first+1 is exactly the stated
inclusive width.

O(n) time, O(width of actual queued nodes) auxiliary.

True positional widths can grow exponentially; this lesson explicitly restricts height
to at most 30 so arithmetic fits.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <memory>
#include <queue>
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

unsigned long long width(const Node* root) {
    if (!root) {
        return 0;
    }
    std::queue<std::pair<const Node*, unsigned long long>> q;
    q.emplace(root, 0);
    unsigned long long best = 0;
    while (!q.empty()) {
        std::size_t size = q.size();
        auto base = q.front().second;
        unsigned long long last = 0;
        for (std::size_t i = 0; i < size; ++i) {
            auto [current, index] = q.front();
            q.pop();
            index -= base;
            last = index;
            if (current->left) {
                q.emplace(current->left.get(), 2 * index + 1);
            }
            if (current->right) {
                q.emplace(current->right.get(), 2 * index + 2);
            }
        }
        best = std::max(best, last + 1);
    }
    return best;
}

int main() {
    auto root = node(1);
    root->left = node(2);
    root->right = node(3);
    root->left->left = node(4);
    root->right->right = node(5);
    assert(width(root.get()) == 4);
    assert(width(nullptr) == 0);
    std::cout << "checks passed\n";
    return 0;
}
