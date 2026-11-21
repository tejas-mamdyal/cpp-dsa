/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Distinct-key BST; return borrowed LCA pointer for two present
keys, otherwise null.

Sample 1 and 3 are both below 4, then split at 2;1 and 7 split at 4.

If both keys lie strictly on one side, the LCA must lie there; the first split or
target equals the ancestor.

O(height) time including two searches, O(1) auxiliary.

The presence checks make absent keys a defined failure instead of returning a
plausible split.
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

const Node* ancestor(const Node* root, int a, int b) {
    if (!contains(root, a) || !contains(root, b)) {
        return nullptr;
    }
    while (root) {
        if (a < root->value && b < root->value) {
            root = root->left.get();
        } else if (a > root->value && b > root->value) {
            root = root->right.get();
        } else {
            return root;
        }
    }
    return nullptr;
}

int main() {
    auto root = sample();
    assert(ancestor(root.get(), 1, 3) == root->left.get());
    assert(ancestor(root.get(), 4, 4) == root.get());
    assert(!ancestor(root.get(), 1, 99));
    std::cout << "checks passed\n";
    return 0;
}
