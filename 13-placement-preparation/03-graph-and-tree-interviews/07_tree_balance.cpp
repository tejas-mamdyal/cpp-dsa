/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

A nonnegative result is subtree height;-1 means a local or descendant
imbalance.

Adding a fourth-level node makes root child heights 3 and 1.

Postorder checks both descendant validity and the root height condition.

O(n) time, O(height) stack.

A balanced root height difference alone does not rule out a deeper imbalance.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <memory>
#include <cstdlib>

struct Node {
    int value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    explicit Node(int x)
        : value(x) {
    }
};

std::unique_ptr<Node> sample() {
    auto root = std::make_unique<Node>(4);
    root->left = std::make_unique<Node>(2);
    root->right = std::make_unique<Node>(6);
    root->left->left = std::make_unique<Node>(1);
    root->left->right = std::make_unique<Node>(3);
    return root;
}

int height(const Node* p) {
    if (!p) {
        return 0;
    }
    int a = height(p->left.get());
    int b = height(p->right.get());
    if (a < 0 || b < 0 || std::abs(a - b) > 1) {
        return -1;
    }
    return 1 + std::max(a, b);
}

int main() {
    auto root = sample();
    assert(height(root.get()) == 3);
    root->left->left->left = std::make_unique<Node>(0);
    assert(height(root.get()) == -1);
    assert(height(nullptr) == 0);
    std::cout << "checks passed\n";
    return 0;
}
