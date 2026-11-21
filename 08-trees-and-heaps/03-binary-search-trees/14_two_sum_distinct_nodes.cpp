/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Two different nodes must sum to target; inorder gives sorted keys; reuse the
Phase 4 two-pointer proof with left<right.

Sample target 10 finds 3+7 or 4+6; singleton 5 cannot supply target 10 by reusing
itself.

Ordering permits endpoint elimination, and strict index separation enforces
distinct nodes.

O(n) time, O(n) saved keys plus O(height) traversal stack.

A one-node tree cannot use the same node twice.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

bool pairSum(const Node* root, long long target) {
    std::vector<int> values;
    ordered(root, values);
    int left = 0;
    int right = static_cast<int>(values.size()) - 1;
    while (left < right) {
        long long sum = 1LL * values[left] + values[right];
        if (sum == target) {
            return true;
        }
        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    return false;
}

int main() {
    auto root = sample();
    assert(pairSum(root.get(), 10));
    assert(!pairSum(root.get(), 20));
    root = node(5);
    assert(!pairSum(root.get(), 10));
    std::cout << "checks passed\n";
    return 0;
}
