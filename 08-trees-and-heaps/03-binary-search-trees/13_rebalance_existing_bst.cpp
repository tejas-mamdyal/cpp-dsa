/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Input is a strict BST; return a separate balanced tree and keep input
unchanged.

A chain 1->2->3->4 becomes a new middle-rooted tree with the same inorder keys.

Inorder preserves all keys exactly once; the sorted builder preserves ordering and
halves subproblem sizes.

O(n) time, O(n) key buffer plus new tree; input traversal may have O(n) depth.

This is a batch rebuild, not a dynamically self-balancing AVL or red-black
implementation.
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

Tree build(const std::vector<int>& a, std::size_t l, std::size_t r) {
    if (l == r) {
        return nullptr;
    }
    std::size_t mid = l + (r - l) / 2;
    auto root = node(a[mid]);
    root->left = build(a, l, mid);
    root->right = build(a, mid + 1, r);
    return root;
}

Tree rebalance(const Node* root) {
    std::vector<int> values;
    ordered(root, values);
    return build(values, 0, values.size());
}

int main() {
    Tree root;
    for (int x : {1, 2, 3, 4}) {
        insert(root, x);
    }
    auto copy = rebalance(root.get());
    assert(copy->value == 3 && root->value == 1);
    std::vector<int> a;
    std::vector<int> b;
    ordered(root.get(), a);
    ordered(copy.get(), b);
    assert(a == b);
    std::cout << "checks passed\n";
    return 0;
}
