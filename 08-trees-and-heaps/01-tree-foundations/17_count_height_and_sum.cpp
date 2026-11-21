/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Return count, sum, and height measured in edges; empty height is -1 and leaf
height 0.

A leaf returns count 1, height 0; the complete seven-node sample returns
count 7, height 2, sum 28.

Every node belongs to root or one disjoint child subtree; maximum child edge
height plus 1 defines parent height.

O(n) time, O(height) frames, O(1) summary per frame.

State edge-versus-node height before comparing results with other lessons.
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

struct Summary {
    int count;
    int height;
    long long sum;
};

Summary inspect(const Node* root) {
    if (!root) {
        return {0, -1, 0};
    }
    auto left = inspect(root->left.get());
    auto right = inspect(root->right.get());
    return {1 + left.count + right.count,
            1 + std::max(left.height, right.height),
            root->value + left.sum + right.sum};
}

int main() {
    auto root = sample();
    auto s = inspect(root.get());
    assert(s.count == 7 && s.height == 2 && s.sum == 28);
    assert(inspect(nullptr).height == -1);
    std::cout << "checks passed\n";
    return 0;
}
