/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Collect values in ascending order between low and high; low>high returns
empty.

Sample interval 3..6 emits 3,4,5,6 and never explores leaf 1.

If root<low, its entire left subtree is too small; the analogous rule excludes
too-large right subtrees.

O(n) worst-case time, O(height) auxiliary plus output; balanced selective queries can be
faster.

Do not promise O(log n) when the output itself may contain n values.
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

void query(const Node* root, int low, int high, std::vector<int>& out) {
    if (!root || low > high) {
        return;
    }
    if (root->value > low) {
        query(root->left.get(), low, high, out);
    }
    if (low <= root->value && root->value <= high) {
        out.push_back(root->value);
    }
    if (root->value < high) {
        query(root->right.get(), low, high, out);
    }
}

int main() {
    auto root = sample();
    std::vector<int> out;
    query(root.get(), 3, 6, out);
    assert((out == std::vector<int>{3, 4, 5, 6}));
    out.clear();
    query(root.get(), 6, 3, out);
    assert(out.empty());
    std::cout << "checks passed\n";
    return 0;
}
