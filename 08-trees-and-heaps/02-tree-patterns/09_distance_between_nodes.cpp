/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Return absence for missing target; otherwise distance is measured in edges.

Between sample nodes 1 and 7, the LCA 4 is two edges from each, so distance 4.

The unique connecting path rises to LCA then descends; the two disjoint lengths
sum to its edge count.

O(n) time, O(height) stack.

Equal values do not identify the same node; use borrowed identities.
*/
#include <iostream>
#include <cassert>
#include <optional>
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

int depth(const Node* root, const Node* target) {
    if (!root) {
        return -1;
    }
    if (root == target) {
        return 0;
    }
    int left = depth(root->left.get(), target);
    if (left >= 0) {
        return left + 1;
    }
    int right = depth(root->right.get(), target);
    return right < 0 ? -1 : right + 1;
}

std::optional<int> distance(const Node* root, const Node* a, const Node* b) {
    auto ancestor = lca(root, a, b);
    if (!ancestor) {
        return std::nullopt;
    }
    return depth(ancestor, a) + depth(ancestor, b);
}

int main() {
    auto root = sample();
    assert(distance(root.get(), root->left->left.get(), root->right->right.get()) == 4);
    assert(distance(root.get(), root.get(), root.get()) == 0);
    assert(!distance(nullptr, nullptr, nullptr));
    std::cout << "checks passed\n";
    return 0;
}
