/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

The explicit postorder algorithm expands the inherited raw-pointer cleanup
example using unique ownership; order records the deletion sequence.

In the sample, clear 1,3,2,5,7,6,4; the root owner ends null.

Each child subtree is cleared before its owner node; every node is released once
and no freed child is dereferenced.

O(n) time, O(height) stack plus O(n) demonstration log.

RAII already destroys owned children automatically; explicit clear is here to teach
postorder, not a requirement for every caller.
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

void clear(Tree& root, std::vector<int>& order) {
    if (!root) {
        return;
    }
    clear(root->left, order);
    clear(root->right, order);
    order.push_back(root->value);
    root.reset();
}

int main() {
    auto root = sample();
    std::vector<int> order;
    clear(root, order);
    assert(!root);
    assert((order == std::vector<int>{1, 3, 2, 5, 7, 6, 4}));
    clear(root, order);
    assert(order.size() == 7);
    std::cout << "checks passed\n";
    return 0;
}
