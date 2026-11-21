/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Descend left while stacking nodes; pop a pending parent, visit it, then
descend its right subtree.

Push 4,2,1; pop 1, then 2; push 3; the output begins 1,2,3,4.

A popped node has completed its left subtree and not yet its right, exactly the
inorder visit point.

O(n) time, O(height) stack plus output.

Continue while current is nonnull OR stack is nonempty; using AND loses pending work.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <memory>
#include <stack>

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

std::vector<int> inorder(const Node* root) {
    std::vector<int> out;
    std::stack<const Node*> pending;
    auto current = root;
    while (current || !pending.empty()) {
        while (current) {
            pending.push(current);
            current = current->left.get();
        }
        current = pending.top();
        pending.pop();
        out.push_back(current->value);
        current = current->right.get();
    }
    return out;
}

int main() {
    auto root = sample();
    assert((inorder(root.get()) == std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
    assert(inorder(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
