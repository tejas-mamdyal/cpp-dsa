/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Mutating inversion swaps left/right ownership at every node.

Sample root 4 swaps children 2 and 6; their child order is mirrored too; inverting
again restores the original shape.

Each subtree is recursively mirrored, and swapping the two mirrors gives the
definition of a mirror at the parent.

O(n) time, O(height) frames, in-place ownership changes.

Use std:: swap on unique_ptr owners; do not create duplicate owners from get().
*/
#include <iostream>
#include <cassert>
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

void invert(Node* root) {
    if (!root) {
        return;
    }
    invert(root->left.get());
    invert(root->right.get());
    std::swap(root->left, root->right);
}

int main() {
    auto root = sample();
    invert(root.get());
    assert(root->left->value == 6 && root->left->left->value == 7);
    invert(root.get());
    assert(root->left->value == 2 && root->left->left->value == 1);
    invert(nullptr);
    std::cout << "checks passed\n";
    return 0;
}
