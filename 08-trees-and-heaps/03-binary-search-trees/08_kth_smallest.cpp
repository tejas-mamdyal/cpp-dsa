/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

k is 1-based; an explicit pending-ancestor stack emits the ordered keys
until rank k; invalid k returns absence.

On the sample, k 3 returns 3; k 8 is absent.

The stack traversal emits every key in the required monotone order, so its kth
emitted key has rank k.

O(height+k) time until success, O(height) auxiliary; O(n) on out-of-range rank.

Restarting a full traversal for every iterator step would lose this bound.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <memory>
#include <stack>

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

std::optional<int> kth(const Node* root, int k) {
    if (k < 1) {
        return std::nullopt;
    }
    std::stack<const Node*> pending;
    auto current = root;
    while (current || !pending.empty()) {
        while (current) {
            pending.push(current);
            current = current->left.get();
        }
        current = pending.top();
        pending.pop();
        --k;
        if (k == 0) {
            return current->value;
        }
        current = current->right.get();
    }
    return std::nullopt;
}

int main() {
    auto root = sample();
    assert(kth(root.get(), 3) == 3);
    assert(!kth(root.get(), 8));
    assert(!kth(root.get(), 0));
    assert(!kth(nullptr, 1));
    std::cout << "checks passed\n";
    return 0;
}
