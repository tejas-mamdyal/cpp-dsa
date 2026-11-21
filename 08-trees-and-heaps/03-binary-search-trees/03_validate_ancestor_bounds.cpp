/*
 All representable int key values are supported, including INT_MIN and INT_MAX. Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless a different bound is explicitly stated, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Optional low/high bounds are absent when unbounded; every recursive call
narrows one bound.

Root 4, left 2 with right 5 fails the inherited high 4 bound; INT_MIN can be a legal
root because no artificial int sentinel is reserved.

Each node satisfies every ancestor inequality exactly when it lies inside the
propagated open interval.

O(n) time, O(height) stack.

Checking only immediate parent-child comparisons misses ancestor violations.
*/
#include <iostream>
#include <cassert>
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

bool valid(const Node* root, std::optional<int> low, std::optional<int> high) {
    if (!root) {
        return true;
    }
    if ((low && root->value <= *low) || (high && root->value >= *high)) {
        return false;
    }
    return valid(root->left.get(), low, root->value) && valid(root->right.get(), root->value, high);
}

int main() {
    auto root = sample();
    assert(valid(root.get(), {}, {}));
    root->left->right->value = 5;
    assert(!valid(root.get(), {}, {}));
    root = node(std::numeric_limits<int>::min());
    root->right = node(std::numeric_limits<int>::max());
    assert(valid(root.get(), {}, {}));
    std::cout << "checks passed\n";
    return 0;
}
