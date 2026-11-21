/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Visit parent then right then left using a stack; reverse the saved values
once.

Temporary sample output 4,6,7,5,2,3,1 reverses to 1,3,2,5,7,6,4.

Reversing the complete parent-right-left ordering places each left subtree before
its right subtree and parent.

O(n) time, O(height) stack plus O(n) output buffer.

This uses an output reversal rather than a complex last-visited pointer state
machine.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
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

std::vector<int> postorder(const Node* root) {
    std::vector<int> out;
    std::stack<const Node*> pending;
    if (root) {
        pending.push(root);
    }
    while (!pending.empty()) {
        auto current = pending.top();
        pending.pop();
        out.push_back(current->value);
        if (current->left) {
            pending.push(current->left.get());
        }
        if (current->right) {
            pending.push(current->right.get());
        }
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    auto root = sample();
    assert((postorder(root.get()) == std::vector<int>{1, 3, 2, 5, 7, 6, 4}));
    assert(postorder(nullptr).empty());
    std::cout << "checks passed\n";
    return 0;
}
