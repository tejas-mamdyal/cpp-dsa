/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Run two ordered walks for greatest value<key and least value>key.

For sample key 4, the answers are 3 and 5; key 8 has predecessor 7 and no successor.

Each candidate satisfies the strict inequality; moving toward the key improves it
or proves no closer ordered value exists.

O(height) time, O(1) auxiliary.

This differs from floor/ceil when key is present.
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

std::pair<std::optional<int>, std::optional<int>> neighbors(const Node* root, int key) {
    std::optional<int> before;
    std::optional<int> after;
    auto p = root;
    while (p) {
        if (p->value < key) {
            before = p->value;
            p = p->right.get();
        } else {
            p = p->left.get();
        }
    }
    p = root;
    while (p) {
        if (p->value > key) {
            after = p->value;
            p = p->left.get();
        } else {
            p = p->right.get();
        }
    }
    return {before, after};
}

int main() {
    auto root = sample();
    auto a = neighbors(root.get(), 4);
    assert(a.first == 3 && a.second == 5);
    auto b = neighbors(root.get(), 8);
    assert(b.first == 7 && !b.second);
    std::cout << "checks passed\n";
    return 0;
}
