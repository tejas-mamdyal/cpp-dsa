/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A strict BST has all left values smaller and all right values
larger; duplicates are not separate nodes. The seven-node sample satisfies that invariant.

Inorder yields 1 through 7; placing 5 under the left child 2 would violate root 4 even
if its direct parent comparison looked legal.

The recursive whole-subtree ordering implies strictly increasing inorder; the
converse follows from ordered traversal positions.

O(n) time, O(height) frames plus O(n) diagnostic output.

A binary tree is not automatically a BST; the tree construction unit allowed arbitrary
values.
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

bool strictlyIncreasing(const Node* root) {
    std::vector<int> values;
    ordered(root, values);
    for (std::size_t i = 1; i < values.size(); ++i) {
        if (values[i - 1] >= values[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    auto root = sample();
    assert(strictlyIncreasing(root.get()));
    root->left->right->value = 5;
    assert(!strictlyIncreasing(root.get()));
    assert(strictlyIncreasing(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
