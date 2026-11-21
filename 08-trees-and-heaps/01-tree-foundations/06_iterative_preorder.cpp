/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

The stack holds subtree roots still to visit; push right before left so
left is processed first.

Stack[4] pops 4, pushes 6 then 2; pop 2 next and continue 4,2,1,3,6,5,7.

The explicit last-in-first-out order reproduces recursive parent-left-right
scheduling.

O(n) time, O(height) stack on binary trees plus O(n) output.

Pushing left first reverses the sibling order.
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

std::vector<int> preorder(const Node* root) {
    std::vector<int> out;
    if (!root) {
        return out;
    }
    std::stack<const Node*> pending;
    pending.push(root);
    while (!pending.empty()) {
        auto current = pending.top();
        pending.pop();
        out.push_back(current->value);
        if (current->right) {
            pending.push(current->right.get());
        }
        if (current->left) {
            pending.push(current->left.get());
        }
    }
    return out;
}

int main() {
    auto root = sample();
    assert((preorder(root.get()) == std::vector<int>{4, 2, 1, 3, 6, 5, 7}));
    assert(preorder(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
