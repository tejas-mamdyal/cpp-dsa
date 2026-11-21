/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Compare left with right, then their opposite children recursively.

Root 1 with children 2,2 and outer children 3,3 is symmetric; changing one 3 breaks it.

Each paired position must have equal values and mirrored child equality.

O(n) time, O(height) frames.

Equal level values without positional comparison can hide asymmetric gaps.
*/
#include <iostream>
#include <cassert>
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

bool mirrors(const Node* a, const Node* b) {
    if (!a || !b) {
        return a == b;
    }
    return a->value == b->value && mirrors(a->left.get(), b->right.get())
           && mirrors(a->right.get(), b->left.get());
}

bool symmetric(const Node* root) {
    return !root || mirrors(root->left.get(), root->right.get());
}

int main() {
    auto root = node(1);
    root->left = node(2);
    root->right = node(2);
    root->left->left = node(3);
    root->right->right = node(3);
    assert(symmetric(root.get()));
    root->right->right->value = 4;
    assert(!symmetric(root.get()));
    assert(symmetric(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
