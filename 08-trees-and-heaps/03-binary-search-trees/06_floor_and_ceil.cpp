/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Floor is greatest value<=key; ceil is least value>=key; either may be
absent.

Sample key 0 has no floor and ceil 1; key 4 has both 4.

When moving right, a smaller root is a valid floor candidate; the excluded left
subtree cannot improve it. The ceil proof is symmetric.

O(height) time, O(1) auxiliary.

Missing is different from numeric 0, which may itself be a valid key.
*/
#include <iostream>
#include <cassert>
#include <optional>
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

std::pair<std::optional<int>, std::optional<int>> bounds(const Node* root, int key) {
    std::optional<int> floor;
    std::optional<int> ceil;
    while (root) {
        if (root->value == key) {
            return {key, key};
        }
        if (root->value < key) {
            floor = root->value;
            root = root->right.get();
        } else {
            ceil = root->value;
            root = root->left.get();
        }
    }
    return {floor, ceil};
}

int main() {
    auto root = sample();
    auto a = bounds(root.get(), 0);
    assert(!a.first && a.second == 1);
    auto b = bounds(root.get(), 4);
    assert(b.first == 4 && b.second == 4);
    assert(!bounds(nullptr, 3).second);
    std::cout << "checks passed\n";
    return 0;
}
