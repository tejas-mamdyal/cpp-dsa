/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Search chooses one ordered side; insertion creates a leaf at the first null
owner. Repeated values leave the tree unchanged.

Insert 4,2,6,3; search 3 follows 4->2->3; search 5 reaches a null left child of 6.

The invariant excludes the opposite side at each comparison; inserting at the
selected null preserves all ancestor bounds.

O(height) time per operation; insertion O(height) stack; unbalanced worst-case height n.

Do not claim O(log n) unless balance is guaranteed.
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

int main() {
    Tree root;
    for (int x : {4, 2, 6, 3, 3}) {
        insert(root, x);
    }
    assert(contains(root.get(), 3));
    assert(!contains(root.get(), 5));
    std::vector<int> values;
    ordered(root.get(), values);
    assert((values == std::vector<int>{2, 3, 4, 6}));
    assert(!contains(nullptr, 1));
    std::cout << "checks passed\n";
    return 0;
}
