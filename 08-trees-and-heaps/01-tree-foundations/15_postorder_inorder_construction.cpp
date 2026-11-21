/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Matching traversals require unique values; the last unused postorder item
is root; reverse consumption requires right before left.

post 1,3,2,5,7,6,4 reads 4, then 6 for the right partition, then 2 for the left.

The inorder root split defines both subtrees; reverse postorder visits them
right-first without mixing intervals.

O(n^2) time, O(height) stack plus tree.

Building left first consumes values belonging to the right subtree.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include <set>

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

Tree build(const std::vector<int>& post,
           const std::vector<int>& in,
           int& next,
           int left,
           int right,
           bool& ok) {
    if (left == right) {
        return nullptr;
    }
    if (next < 0) {
        ok = false;
        return nullptr;
    }
    int value = post[next];
    --next;
    int mid = left;
    while (mid < right && in[mid] != value) {
        ++mid;
    }
    if (mid == right) {
        ok = false;
        return nullptr;
    }
    auto root = node(value);
    root->right = build(post, in, next, mid + 1, right, ok);
    if (!ok) {
        return nullptr;
    }
    root->left = build(post, in, next, left, mid, ok);
    return root;
}

std::optional<Tree> reconstruct(const std::vector<int>& post, const std::vector<int>& in) {
    if (post.size() != in.size() || std::set<int>(in.begin(), in.end()).size() != in.size()
        || std::set<int>(post.begin(), post.end()) != std::set<int>(in.begin(), in.end())) {
        return std::nullopt;
    }
    int next = static_cast<int>(post.size()) - 1;
    bool ok = true;
    auto root = build(post, in, next, 0, static_cast<int>(in.size()), ok);
    if (!ok || next != -1) {
        return std::nullopt;
    }
    return std::optional<Tree>{std::move(root)};
}

int main() {
    auto root = reconstruct({1, 3, 2, 5, 7, 6, 4}, {1, 2, 3, 4, 5, 6, 7});
    assert(root && (*root)->right->left->value == 5);
    assert(!reconstruct({1, 2}, {2, 3}));
    assert(reconstruct({}, {}));
    std::cout << "checks passed\n";
    return 0;
}
