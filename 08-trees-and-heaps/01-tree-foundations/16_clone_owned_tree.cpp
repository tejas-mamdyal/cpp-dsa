/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

A clone creates new owners for both cloned subtrees; default unique_ptr
copying is deliberately unavailable.

Cloning the sample then changing cloned left value to 99 leaves original left
value 2.

Inductively each subtree copy has identical values/shape and disjoint
allocations.

O(n) time/result storage, O(height) frames.

A shallow raw-pointer copy would alias children and make ownership unsafe.
*/
#include <iostream>
#include <cassert>
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

Tree clone(const Node* root) {
    if (!root) {
        return nullptr;
    }
    auto copy = node(root->value);
    copy->left = clone(root->left.get());
    copy->right = clone(root->right.get());
    return copy;
}

int main() {
    auto original = sample();
    auto copy = clone(original.get());
    assert(copy.get() != original.get());
    copy->left->value = 99;
    assert(original->left->value == 2);
    assert(!clone(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
