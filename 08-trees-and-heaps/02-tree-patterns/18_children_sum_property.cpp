/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Each internal value must equal the sum of immediate existing
children; leaves satisfy the property without comparing to 0.

Root 10 with children 4,6 is valid; if 4 has children 1,3, its local equation is valid
too.

The global property is the conjunction of the parent equation and the two child
properties.

O(n) time, O(height) stack.

This is not subtree total equality; compare immediate child values only.
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

bool childSum(const Node* root) {
    if (!root || (!root->left && !root->right)) {
        return true;
    }
    long long sum = 0;
    if (root->left) {
        sum += root->left->value;
    }
    if (root->right) {
        sum += root->right->value;
    }
    return root->value == sum && childSum(root->left.get()) && childSum(root->right.get());
}

int main() {
    auto root = node(10);
    root->left = node(4);
    root->right = node(6);
    assert(childSum(root.get()));
    root->left->value = 5;
    assert(!childSum(root.get()));
    assert(childSum(node(-3).get()));
    std::cout << "checks passed\n";
    return 0;
}
