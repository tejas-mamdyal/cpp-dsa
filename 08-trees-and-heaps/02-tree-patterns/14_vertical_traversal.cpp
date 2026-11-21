/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Record(column, row, value) tuples, sort lexicographically, and group equal
columns. This definition differs from simple BFS vertical order.

Sample column 0 contains 4 at row 0 then 3 and 5 at row 2, so[4,3,5].

Sorting by the specified keys directly implements column, row, and same-position
value ordering.

O(n log(n+1)) time, O(n) saved triples/output plus O(height) recursion.

Do not use traversal arrival order when the specification requires value-sorted ties.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>
#include <memory>
#include <tuple>

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

void record(const Node* root, int row, int col, std::vector<std::tuple<int, int, int>>& data) {
    if (!root) {
        return;
    }
    data.emplace_back(col, row, root->value);
    record(root->left.get(), row + 1, col - 1, data);
    record(root->right.get(), row + 1, col + 1, data);
}

std::vector<std::vector<int>> vertical(const Node* root) {
    std::vector<std::tuple<int, int, int>> data;
    record(root, 0, 0, data);
    std::sort(data.begin(), data.end());
    std::vector<std::vector<int>> out;
    std::optional<int> previous;
    for (auto [col, row, value] : data) {
        (void)row;
        if (!previous || col != *previous) {
            out.push_back({});
            previous = col;
        }
        out.back().push_back(value);
    }
    return out;
}

int main() {
    auto root = sample();
    assert((vertical(root.get()) == std::vector<std::vector<int>>{{1}, {2}, {4, 3, 5}, {6}, {7}}));
    assert(vertical(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
