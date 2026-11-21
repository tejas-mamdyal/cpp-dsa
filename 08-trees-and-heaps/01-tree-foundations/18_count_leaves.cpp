/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A leaf has neither child; empty tree has zero leaves.

The sample leaves 1,3,5,7 give 4; root 1 with only left 2 has just one leaf.

A nonleaf contributes no leaf itself and partitions leaves between its existing
child subtrees.

O(n) time, O(height) frames.

Using OR instead of AND would count one-child nodes as leaves.
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

int leaves(const Node* root) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return 1;
    }
    return leaves(root->left.get()) + leaves(root->right.get());
}

int main() {
    auto root = sample();
    assert(leaves(root.get()) == 4);
    root = node(1);
    root->left = node(2);
    assert(leaves(root.get()) == 1);
    assert(leaves(nullptr) == 0);
    std::cout << "checks passed\n";
    return 0;
}
