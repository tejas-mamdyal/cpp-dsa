/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A borrowed const pointer observes a subtree; out accumulates values and is
intentionally not undone.

The seven-node sample yields 1,2,3,4,5,6,7; each null child immediately returns.

Induct on subtree size: visit the root exactly once and recurse into disjoint
left/right subtrees in the stated order.

O(n) time, O(height) active frames plus O(n) output.

Inorder is sorted only for a valid BST; an arbitrary binary tree has no ordering
guarantee.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

void walk(const Node* root, std::vector<int>& out) {
    if (!root) {
        return;
    }
    walk(root->left.get(), out);
    out.push_back(root->value);
    walk(root->right.get(), out);
}

int main() {
    auto root = sample();
    std::vector<int> out;
    walk(root.get(), out);
    assert((out == std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
    out.clear();
    walk(nullptr, out);
    assert(out.empty());
    std::cout << "checks passed\n";
    return 0;
}
