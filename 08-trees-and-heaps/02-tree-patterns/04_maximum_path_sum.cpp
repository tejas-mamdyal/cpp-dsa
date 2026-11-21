/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Return the best downward contribution; negative child contributions are
discarded, while the saved answer is nonempty.

-10 with children 9 and 20, and 20 children 15,7 yields 15+20+7=42.

Every path has a highest node; its two downward positive contributions determine
its score, but a parent can extend only one side.

O(n) time, O(height) stack.

Initializing global best to 0 is wrong for all-negative trees; empty tree returns
absence.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <optional>
#include <limits>
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

long long gain(const Node* root, long long& best) {
    if (!root) {
        return 0;
    }
    long long left = std::max(0LL, gain(root->left.get(), best));
    long long right = std::max(0LL, gain(root->right.get(), best));
    best = std::max(best, root->value + left + right);
    return root->value + std::max(left, right);
}

std::optional<long long> maximumPath(const Node* root) {
    if (!root) {
        return std::nullopt;
    }
    long long best = std::numeric_limits<long long>::lowest();
    gain(root, best);
    return best;
}

int main() {
    auto root = node(-10);
    root->left = node(9);
    root->right = node(20);
    root->right->left = node(15);
    root->right->right = node(7);
    assert(maximumPath(root.get()) == 42);
    assert(!maximumPath(nullptr));
    root = node(-3);
    assert(maximumPath(root.get()) == -3);
    std::cout << "checks passed\n";
    return 0;
}
