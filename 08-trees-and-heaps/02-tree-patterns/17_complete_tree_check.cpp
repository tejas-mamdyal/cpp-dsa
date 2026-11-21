/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Queue both real and null children; gap records the first missing BFS
position.

A root with only right child has a missing left slot before a real right slot, so
it is incomplete.

Complete trees occupy an uninterrupted prefix of level-order positions; the gap
rule tests exactly that property.

O(n) time, O(n) queue in this explicit-null baseline.

Completeness differs from height balance and from a perfect tree.
*/
#include <iostream>
#include <cassert>
#include <memory>
#include <queue>

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

bool complete(const Node* root) {
    std::queue<const Node*> q;
    q.push(root);
    bool gap = false;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        if (!current) {
            gap = true;
            continue;
        }
        if (gap) {
            return false;
        }
        q.push(current->left.get());
        q.push(current->right.get());
    }
    return true;
}

int main() {
    auto root = sample();
    assert(complete(root.get()));
    root = node(1);
    root->right = node(2);
    assert(!complete(root.get()));
    assert(complete(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
