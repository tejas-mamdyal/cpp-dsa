/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Minimum follows left children; maximum follows right; empty returns absence.

The sample extreme paths 4->2->1 and 4->6->7 give 1,7.

Any value in a right subtree exceeds its ancestor; continuing left cannot miss a
smaller value.

O(height) time, O(1) auxiliary.

Do not dereference the root before checking emptiness.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <utility>
#include <memory>

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

std::optional<std::pair<int, int>> extremes(const Node* root) {
    if (!root) {
        return std::nullopt;
    }
    auto low = root;
    auto high = root;
    while (low->left) {
        low = low->left.get();
    }
    while (high->right) {
        high = high->right.get();
    }
    return std::pair<int, int>{low->value, high->value};
}

int main() {
    auto root = sample();
    assert((extremes(root.get()) == std::optional<std::pair<int, int>>{{1, 7}}));
    assert(!extremes(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
