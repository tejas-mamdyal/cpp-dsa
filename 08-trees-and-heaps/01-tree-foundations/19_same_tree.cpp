/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Nulls match only nulls; nonnull nodes need equal values and equal ordered
children.

Root 1 with left 2 differs from root 1 with right 2 even though both contain values 1
and 2.

Recursive paired-position equality is exactly equality of ordered labeled trees.

O(n+m) upper-bound time, O(max height) stack with early mismatch exits.

Value multisets do not encode shape.
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

bool same(const Node* a, const Node* b) {
    if (!a || !b) {
        return a == b;
    }
    return a->value == b->value && same(a->left.get(), b->left.get())
           && same(a->right.get(), b->right.get());
}

int main() {
    auto a = sample();
    auto b = sample();
    assert(same(a.get(), b.get()));
    b->left->value = 9;
    assert(!same(a.get(), b.get()));
    assert(same(nullptr, nullptr));
    std::cout << "checks passed\n";
    return 0;
}
