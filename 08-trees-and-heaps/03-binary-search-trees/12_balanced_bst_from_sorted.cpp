/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Strictly increasing sorted vector; build a new balanced BST using half-open
intervals.

For 1..7, mid index 3 becomes 4, left 1..3 becomes 2, right 5..7 becomes 6.

Every left interval value is smaller and every right value larger; halving sizes
keeps height logarithmic.

O(n) time, O(log(n+1)) construction frames plus O(n) result.

Repeated values violate this strict-BST contract; validate or reject them in an
input-facing wrapper.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <memory>
#include <cstddef>

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

Tree build(const std::vector<int>& a, std::size_t left, std::size_t right) {
    if (left == right) {
        return nullptr;
    }
    std::size_t mid = left + (right - left) / 2;
    auto root = node(a[mid]);
    root->left = build(a, left, mid);
    root->right = build(a, mid + 1, right);
    return root;
}

int main() {
    auto root = build({1, 2, 3, 4, 5, 6, 7}, 0, 7);
    assert(root->value == 4 && root->left->value == 2);
    assert(!build({}, 0, 0));
    std::cout << "checks passed\n";
    return 0;
}
