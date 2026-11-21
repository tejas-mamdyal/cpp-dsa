/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Unique-value preorder and inorder must describe the same tree; the next
preorder value is the root; find it in the current inorder interval. Read left then right
partitions.

pre 4,2,1,3,6,5,7 and sorted inorder split at 4; left values 1,2,3 form the left
subtree.

Inorder fixes the disjoint child intervals; preorder gives each child root in the
correct sequence.

O(n^2) time with simple interval scans, O(height) frames plus owned result.

Duplicate values make this reconstruction ambiguous; reject rather than silently
guessing.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include <set>
#include <cstddef>

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

Tree build(const std::vector<int>& pre,
           const std::vector<int>& in,
           std::size_t& next,
           int left,
           int right,
           bool& ok) {
    if (left == right) {
        return nullptr;
    }
    if (next == pre.size()) {
        ok = false;
        return nullptr;
    }
    int value = pre[next];
    ++next;
    int mid = left;
    while (mid < right && in[mid] != value) {
        ++mid;
    }
    if (mid == right) {
        ok = false;
        return nullptr;
    }
    auto root = node(value);
    root->left = build(pre, in, next, left, mid, ok);
    if (!ok) {
        return nullptr;
    }
    root->right = build(pre, in, next, mid + 1, right, ok);
    return root;
}

std::optional<Tree> reconstruct(const std::vector<int>& pre, const std::vector<int>& in) {
    if (pre.size() != in.size() || std::set<int>(in.begin(), in.end()).size() != in.size()
        || std::set<int>(pre.begin(), pre.end()) != std::set<int>(in.begin(), in.end())) {
        return std::nullopt;
    }
    std::size_t next = 0;
    bool ok = true;
    auto root = build(pre, in, next, 0, static_cast<int>(in.size()), ok);
    if (!ok || next != pre.size()) {
        return std::nullopt;
    }
    return std::optional<Tree>{std::move(root)};
}

int main() {
    auto root = reconstruct({4, 2, 1, 3, 6, 5, 7}, {1, 2, 3, 4, 5, 6, 7});
    assert(root && (*root)->left->right->value == 3);
    assert(!reconstruct({1, 2}, {2, 3}));
    assert(!reconstruct({1, 1}, {1, 1}));
    assert(reconstruct({}, {}));
    std::cout << "checks passed\n";
    return 0;
}
