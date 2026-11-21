/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Build ordinary left-to-right levels, then reverse odd-numbered rows; root
depth 0.

The sample displays[4],[6,2],[1,3,5,7].

Queue traversal remains correct; reversing the selected saved rows implements the
specified alternating order.

O(n) time, O(width) queue plus output.

Reversing queue insertions inconsistently can alter future levels; keep traversal and
presentation separate.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <memory>
#include <queue>
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

std::vector<std::vector<int>> levels(const Node* root) {
    std::vector<std::vector<int>> out;
    if (!root) {
        return out;
    }
    std::queue<const Node*> q;
    q.push(root);
    while (!q.empty()) {
        std::size_t width = q.size();
        std::vector<int> row;
        for (std::size_t i = 0; i < width; ++i) {
            auto current = q.front();
            q.pop();
            row.push_back(current->value);
            if (current->left) {
                q.push(current->left.get());
            }
            if (current->right) {
                q.push(current->right.get());
            }
        }
        out.push_back(row);
    }
    return out;
}

std::vector<std::vector<int>> zigzag(const Node* root) {
    auto out = levels(root);
    for (std::size_t i = 1; i < out.size(); i += 2) {
        std::reverse(out[i].begin(), out[i].end());
    }
    return out;
}

int main() {
    auto root = sample();
    assert((zigzag(root.get()) == std::vector<std::vector<int>>{{4}, {6, 2}, {1, 3, 5, 7}}));
    std::cout << "checks passed\n";
    return 0;
}
