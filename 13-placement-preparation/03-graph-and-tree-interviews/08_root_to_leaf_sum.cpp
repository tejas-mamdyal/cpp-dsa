/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

target excludes the already visited prefix values.

4+2+1 reaches 7;4+2 is not a leaf route.

Every root-to-leaf path follows one recursive child choice until the terminal
leaf.

O(n) time, O(height) stack.

Zero remaining at an internal node is insufficient.
*/
#include <iostream>
#include <cassert>
#include <memory>

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

bool hasSum(const Node* p, int target) {
    if (!p) {
        return false;
    }
    target -= p->value;
    if (!p->left && !p->right) {
        return target == 0;
    }
    return hasSum(p->left.get(), target) || hasSum(p->right.get(), target);
}

int main() {
    auto root = sample();
    assert(hasSum(root.get(), 7));
    assert(!hasSum(root.get(), 6));
    assert(!hasSum(nullptr, 0));
    std::cout << "checks passed\n";
    return 0;
}
