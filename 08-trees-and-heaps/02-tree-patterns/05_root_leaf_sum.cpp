/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Subtract current value from remaining target; accept only at a leaf.

The sample has root 4, left 2, left 1 sum 7; target 4 alone at the root does not qualify.

Every root-to-leaf route consumes its values exactly once and checks equality at
its true endpoint.

O(n) time, O(height) stack.

Negative values prevent an unproved remaining<0 cutoff.
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

bool hasSum(const Node* root, long long target) {
    if (!root) {
        return false;
    }
    target -= root->value;
    if (!root->left && !root->right) {
        return target == 0;
    }
    return hasSum(root->left.get(), target) || hasSum(root->right.get(), target);
}

int main() {
    auto root = sample();
    assert(hasSum(root.get(), 7));
    assert(!hasSum(root.get(), 4));
    assert(!hasSum(nullptr, 0));
    std::cout << "checks passed\n";
    return 0;
}
