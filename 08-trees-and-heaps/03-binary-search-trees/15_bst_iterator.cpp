/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

An ascending iterator borrows a live unchanged tree; store the left
spine; after popping one node, push the left spine of its right child.

First next on the sample returns 1; after 2 it exposes 3 without restarting at root 4.

The pending stack represents exactly the unvisited inorder ancestors; each node is
pushed/popped once.

O(n) time over n next calls; O(height) space; individual next may take O(height), amortized
O(1).

Mutating or destroying the tree invalidates borrowed iterator pointers.
*/
#include <iostream>
#include <cassert>
#include <optional>
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

class Iterator {
    std::stack<const Node*> pending;

    void leftSpine(const Node* root) {
        while (root) {
            pending.push(root);
            root = root->left.get();
        }
    }

public:
    explicit Iterator(const Node* root) {
        leftSpine(root);
    }

    std::optional<int> next() {
        if (pending.empty()) {
            return std::nullopt;
        }
        auto current = pending.top();
        pending.pop();
        leftSpine(current->right.get());
        return current->value;
    }
};

int main() {
    auto root = sample();
    Iterator it(root.get());
    for (int x = 1; x <= 7; ++x) {
        assert(it.next() == x);
    }
    assert(!it.next());
    Iterator empty(nullptr);
    assert(!empty.next());
    std::cout << "checks passed\n";
    return 0;
}
