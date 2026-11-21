/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Borrowed pointers identify nodes even when values repeat; validate presence
before combining child results.

Nodes 1 and 3 split at 2; nodes 1 and 7 split at 4; an external node has no LCA.

A node with targets in both child subtrees is their lowest split; one-sided
results propagate upward until that split.

O(n) time including presence checks, O(height) stack.

The classic helper alone can return one present target when the other is absent; the
wrapper prevents that.
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

bool contains(const Node* root, const Node* target) {
    return root
           && (root == target || contains(root->left.get(), target)
               || contains(root->right.get(), target));
}

const Node* common(const Node* root, const Node* a, const Node* b) {
    if (!root || root == a || root == b) {
        return root;
    }
    auto left = common(root->left.get(), a, b);
    auto right = common(root->right.get(), a, b);
    if (left && right) {
        return root;
    }
    return left ? left : right;
}

const Node* lca(const Node* root, const Node* a, const Node* b) {
    if (!a || !b || !contains(root, a) || !contains(root, b)) {
        return nullptr;
    }
    return common(root, a, b);
}

int main() {
    auto root = sample();
    auto a = root->left->left.get();
    auto b = root->left->right.get();
    assert(lca(root.get(), a, b) == root->left.get());
    assert(lca(root.get(), a, a) == a);
    auto outside = node(1);
    assert(!lca(root.get(), a, outside.get()));
    std::cout << "checks passed\n";
    return 0;
}
