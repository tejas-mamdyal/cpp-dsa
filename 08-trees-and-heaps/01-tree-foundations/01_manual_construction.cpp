/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A tree has one root; each node has up to two ordered children. Unlike a
general graph, no child has two owners and no cycle is permitted.

Create root 10, left 5, right 15; borrow left with get(); after observing 5, root still
owns every allocation.

Each make_unique creates one owner; moving child owners transfers ownership
without copying nodes.

O(n) construction/destruction time, O(n) owned storage; borrowed pointers O(1).

Never delete a borrowed get() pointer or keep it after its owner is reset. Automatic
recursive destruction has O(height) call depth.
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

int count(const Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + count(root->left.get()) + count(root->right.get());
}

int main() {
    auto root = node(10);
    root->left = node(5);
    root->right = node(15);
    const Node* borrowed = root->left.get();
    assert(borrowed->value == 5 && count(root.get()) == 3);
    root.reset();
    assert(!root);
    assert(count(nullptr) == 0);
    std::cout << "checks passed\n";
    return 0;
}
