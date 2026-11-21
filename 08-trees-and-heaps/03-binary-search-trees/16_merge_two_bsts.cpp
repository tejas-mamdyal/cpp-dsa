/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

For strict BST inputs, extract both sequences, then merge with two indices
and suppress equal output values.

Keys 1,3 and 2,3 merge to 1,2,3.

Each sequence is sorted; the smaller current head is the next union value, and
duplicate suppression matches set semantics.

O(n+m) time, O(n+m) saved sequences/output.

A multiset union would need another duplicate policy; state it before coding.
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

void insert(Tree& root, int value) {
    if (!root) {
        root = node(value);
        return;
    }
    if (value < root->value) {
        insert(root->left, value);
    } else if (value > root->value) {
        insert(root->right, value);
    }
}

bool contains(const Node* root, int value) {
    while (root) {
        if (value == root->value) {
            return true;
        }
        root = value < root->value ? root->left.get() : root->right.get();
    }
    return false;
}

void ordered(const Node* root, std::vector<int>& out) {
    if (!root) {
        return;
    }
    ordered(root->left.get(), out);
    out.push_back(root->value);
    ordered(root->right.get(), out);
}

std::vector<int> merge(const Node* a, const Node* b) {
    std::vector<int> x;
    std::vector<int> y;
    ordered(a, x);
    ordered(b, y);
    std::vector<int> out;
    std::size_t i = 0;
    std::size_t j = 0;
    while (i < x.size() || j < y.size()) {
        int value;
        if (j == y.size() || (i < x.size() && x[i] <= y[j])) {
            value = x[i];
            ++i;
        } else {
            value = y[j];
            ++j;
        }
        if (out.empty() || out.back() != value) {
            out.push_back(value);
        }
    }
    return out;
}

int main() {
    Tree a;
    Tree b;
    for (int x : {1, 3}) {
        insert(a, x);
    }
    for (int x : {2, 3}) {
        insert(b, x);
    }
    assert((merge(a.get(), b.get()) == std::vector<int>{1, 2, 3}));
    assert(merge(nullptr, nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
