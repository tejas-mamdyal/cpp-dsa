/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Recursively flatten both sides and return the tail; move the old right
owner after the flattened left tail.

Sample becomes 4->2->1->3->6->5->7, with every left child null.

The flattened left chain must follow root, then its old right chain; tail links
preserve exactly preorder without allocating copies.

O(n) time, O(height) stack, in-place nodes.

Use std:: move to transfer unique ownership; borrowed tails must remain owned through
the splice.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

Node* flatten(Node* root) {
    if (!root) {
        return nullptr;
    }
    Node* leftTail = flatten(root->left.get());
    Node* rightTail = flatten(root->right.get());
    if (root->left) {
        auto oldRight = std::move(root->right);
        root->right = std::move(root->left);
        leftTail->right = std::move(oldRight);
    }
    if (rightTail) {
        return rightTail;
    }
    if (leftTail) {
        return leftTail;
    }
    return root;
}

int main() {
    auto root = sample();
    flatten(root.get());
    std::vector<int> out;
    for (auto p = root.get(); p; p = p->right.get()) {
        assert(!p->left);
        out.push_back(p->value);
    }
    assert((out == std::vector<int>{4, 2, 1, 3, 6, 5, 7}));
    assert(!flatten(nullptr));
    std::cout << "checks passed\n";
    return 0;
}
