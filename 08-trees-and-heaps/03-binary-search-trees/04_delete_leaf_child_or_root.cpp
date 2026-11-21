/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Find the target; replace zero/one-child nodes by the existing child; for two
children copy the inorder successor value and delete that successor.

Deleting root 4 from the sample copies 5, then removes original 5 from the right
subtree.

The successor is the smallest right value, so it fits between both remaining
subtrees; child replacement preserves all outer bounds.

O(height) time/stack; no allocation required.

Move a child into a temporary before destroying its parent; borrowed pointers to
erased nodes become invalid.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
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

void erase(Tree& root, int value) {
    if (!root) {
        return;
    }
    if (value < root->value) {
        erase(root->left, value);
        return;
    }
    if (value > root->value) {
        erase(root->right, value);
        return;
    }
    if (!root->left) {
        auto replacement = std::move(root->right);
        root = std::move(
            replacement); // The separate temporary stays alive while the old parent is destroyed.
        return;
    }
    if (!root->right) {
        auto replacement = std::move(root->left);
        root = std::move(
            replacement); // The separate temporary stays alive while the old parent is destroyed.
        return;
    }
    auto successor = root->right.get();
    while (successor->left) {
        successor = successor->left.get();
    }
    root->value = successor->value;
    erase(root->right, successor->value);
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
    erase(root, 4);
    assert(root->value == 5 && valid(root.get(), {}, {}));
    erase(root, 1);
    erase(root, 2);
    erase(root, 99);
    std::vector<int> values;
    ordered(root.get(), values);
    assert((values == std::vector<int>{3, 5, 6, 7}));
    Tree single = node(1);
    erase(single, 1);
    assert(!single);
    std::cout << "checks passed\n";
    return 0;
}
