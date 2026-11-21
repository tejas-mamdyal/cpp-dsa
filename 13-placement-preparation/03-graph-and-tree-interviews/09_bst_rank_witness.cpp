/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

The BST invariant makes inorder a sorted key sequence.

1,2,3,4,6 has third key 3.

All left keys precede the root and all right keys follow it, recursively.

O(n) time/storage reference; stop an iterative inorder after k visits for O(height+k).

A general binary tree does not have sorted inorder.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
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

void inorder(const Node* p, std::vector<int>& out) {
    if (!p) {
        return;
    }
    inorder(p->left.get(), out);
    out.push_back(p->value);
    inorder(p->right.get(), out);
}

std::optional<int> kth(const Node* p, int k) {
    std::vector<int> values;
    inorder(p, values);
    if (k < 1 || k > static_cast<int>(values.size())) {
        return std::nullopt;
    }
    return values[k - 1];
}

int main() {
    auto root = sample();
    assert(kth(root.get(), 3) == 3);
    assert(!kth(root.get(), 9));
    std::cout << "checks passed\n";
    return 0;
}
