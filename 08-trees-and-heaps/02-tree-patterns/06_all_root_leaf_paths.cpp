/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A shared vector stores the current route; all four sample leaves create
separate saved paths.

The first sample route is 4,2,1; pop 1 before exploring 4,2,3.

Induction and choose/undo preserve the exact ancestor route for every leaf.

O(n*height) upper-bound output-copy time, O(height) auxiliary plus output.

Output intentionally accumulates; only the work path is restored.
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

void paths(const Node* root, std::vector<int>& path, std::vector<std::vector<int>>& out) {
    if (!root) {
        return;
    }
    path.push_back(root->value); // Choose this route element before exploring its completions.
    if (!root->left && !root->right) {
        out.push_back(path);
    } else {
        paths(root->left.get(), path, out);
        paths(root->right.get(), path, out);
    }
    path.pop_back(); // Undo so the next sibling sees the same entry prefix.
}

int main() {
    auto root = sample();
    std::vector<int> path;
    std::vector<std::vector<int>> out;
    paths(root.get(), path, out);
    assert((out == std::vector<std::vector<int>>{{4, 2, 1}, {4, 2, 3}, {4, 6, 5}, {4, 6, 7}}));
    assert(path.empty());
    std::cout << "checks passed\n";
    return 0;
}
