/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A helper returns height in nodes, or -1 for an unbalanced subtree. Baseline
recomputes heights at each node and may take O(n^2).

The sample returns height 3; adding a long one-sided chain creates a height
difference above 1 and propagates -1.

A tree is balanced exactly when both child trees are balanced and their heights
differ by at most 1.

O(n) time, O(height) stack.

Do not confuse -1 invalid height here with the earlier empty edge-height
convention; this helper uses empty height 0.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <memory>
#include <cstdlib>

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

int balancedHeight(const Node* root) {
    if (!root) {
        return 0;
    }
    int left = balancedHeight(root->left.get());
    if (left < 0) {
        return -1;
    }
    int right = balancedHeight(root->right.get());
    if (right < 0 || std::abs(left - right) > 1) {
        return -1;
    }
    return 1 + std::max(left, right);
}

int main() {
    auto root = sample();
    assert(balancedHeight(root.get()) == 3);
    root = node(1);
    root->left = node(2);
    root->left->left = node(3);
    assert(balancedHeight(root.get()) == -1);
    assert(balancedHeight(nullptr) == 0);
    std::cout << "checks passed\n";
    return 0;
}
