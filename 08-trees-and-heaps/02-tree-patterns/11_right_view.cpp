/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Use the already taught level-order rows and take one boundary element per
nonempty row.

The sample view is 4,6,7; one saved value represents each depth.

At one depth, queue order is left-to-right; the requested boundary is exactly its
first or last item.

O(n) time, O(n) saved level rows plus view; queue O(width).

This readable baseline saves full levels; an optional follow-up collects the boundary
during BFS.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

std::vector<int> view(const Node* root) {
    std::vector<int> out;
    for (const auto& row : levels(root)) {
        out.push_back(row.back());
    }
    return out;
}

int main() {
    auto root = sample();
    assert((view(root.get()) == std::vector<int>{4, 6, 7}));
    assert(view(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
