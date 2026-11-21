/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Output root, nonleaf left boundary, all leaves left-to-right, then reversed
nonleaf right boundary.

Sample boundary 4,2,1,3,5,7,6 includes each boundary node once.

Every boundary node belongs to the root, a side nonleaf, or a leaf; the categories
are disjoint by construction.

O(n) time, O(height) recursion/right-boundary buffer plus output.

A single leaf root is output once; side walks fall back to the existing child.
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

bool leaf(const Node* root) {
    return root && !root->left && !root->right;
}

void addLeaves(const Node* root, std::vector<int>& out) {
    if (!root) {
        return;
    }
    if (leaf(root)) {
        out.push_back(root->value);
        return;
    }
    addLeaves(root->left.get(), out);
    addLeaves(root->right.get(), out);
}

std::vector<int> boundary(const Node* root) {
    if (!root) {
        return {};
    }
    if (leaf(root)) {
        return {root->value};
    }
    std::vector<int> out{root->value};
    auto current = root->left.get();
    while (current) {
        if (!leaf(current)) {
            out.push_back(current->value);
        }
        current = current->left ? current->left.get() : current->right.get();
    }
    addLeaves(root, out);
    std::vector<int> right;
    current = root->right.get();
    while (current) {
        if (!leaf(current)) {
            right.push_back(current->value);
        }
        current = current->right ? current->right.get() : current->left.get();
    }
    out.insert(out.end(), right.rbegin(), right.rend());
    return out;
}

int main() {
    auto root = sample();
    assert((boundary(root.get()) == std::vector<int>{4, 2, 1, 3, 5, 7, 6}));
    assert(boundary(node(8).get()) == std::vector<int>{8});
    assert(boundary(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
