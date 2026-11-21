/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Return edge-height while updating the best leftHeight+rightHeight+2; empty
height -1. This adopts the old diameter algorithm.

Each sample child has edge-height 1; through root the path has 1+1+2=4 edges.

Every longest path has a highest node and lies in its two child branches or one
branch; all such peaks are examined.

O(n) time, O(height) stack.

Diameter counts edges, not nodes, and need not pass through the root.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
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

int height(const Node* root, int& best) {
    if (!root) {
        return -1;
    }
    int left = height(root->left.get(), best);
    int right = height(root->right.get(), best);
    best = std::max(best, left + right + 2);
    return 1 + std::max(left, right);
}

int diameter(const Node* root) {
    int best = 0;
    height(root, best);
    return best;
}

int main() {
    auto root = sample();
    assert(diameter(root.get()) == 4);
    assert(diameter(nullptr) == 0);
    root = node(9);
    assert(diameter(root.get()) == 0);
    std::cout << "checks passed\n";
    return 0;
}
