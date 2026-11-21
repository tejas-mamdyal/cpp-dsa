/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Column starts at 0; left subtracts 1, right adds 1. An ordered map outputs
columns from left to right.

Sample columns-2,-1,0,1,2 display 1,2,5,6,7; for bottom ties the later BFS
right-side node wins.

BFS is nondecreasing in depth; first is topmost, last is bottommost under the
stated tie rule.

O(n log(n+1)) time, O(n) map/queue/output.

Equal-depth column ties are explicitly BFS left-to-right, last-wins for the bottom
view.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
#include <memory>
#include <queue>
#include <map>

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

std::vector<int> view(const Node* root) {
    std::map<int, int> values;
    std::queue<std::pair<const Node*, int>> q;
    if (root) {
        q.emplace(root, 0);
    }
    while (!q.empty()) {
        auto [current, column] = q.front();
        q.pop();
        values[column] = current->value;
        if (current->left) {
            q.emplace(current->left.get(), column - 1);
        }
        if (current->right) {
            q.emplace(current->right.get(), column + 1);
        }
    }
    std::vector<int> out;
    for (auto item : values) {
        out.push_back(item.second);
    }
    return out;
}

int main() {
    auto root = sample();
    assert((view(root.get()) == std::vector<int>{1, 2, 5, 6, 7}));
    assert(view(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
