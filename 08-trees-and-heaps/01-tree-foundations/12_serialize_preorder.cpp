/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

write emits a value followed by both child encodings, including nulls.
Baseline values-only preorder loses shape.

Root 1 with only right 2 emits 1, null,2, null, null; with only left 2 it
emits 1,2, null, null, null.

Induction gives a unique complete representation of every owned ordered tree.

O(n) time/output, O(height) frames;2n+1 tokens.

Omitting nulls makes different shapes share the same value sequence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
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

Tree read(const std::vector<std::optional<int>>& tokens, std::size_t& index, bool& ok) {
    if (index == tokens.size()) {
        ok = false;
        return nullptr;
    }
    auto token = tokens[index];
    ++index;
    if (!token) {
        return nullptr;
    }
    auto root = node(*token);
    root->left = read(tokens, index, ok);
    if (!ok) {
        return nullptr;
    }
    root->right = read(tokens, index, ok);
    if (!ok) {
        return nullptr;
    }
    return root;
}

std::optional<Tree> parse(const std::vector<std::optional<int>>& tokens) {
    std::size_t index = 0;
    bool ok = true;
    auto root = read(tokens, index, ok);
    if (!ok || index != tokens.size()) {
        return std::nullopt;
    }
    return std::optional<Tree>{std::move(root)};
}

void write(const Node* root, std::vector<std::optional<int>>& tokens) {
    if (!root) {
        tokens.push_back(std::nullopt);
        return;
    }
    tokens.push_back(root->value);
    write(root->left.get(), tokens);
    write(root->right.get(), tokens);
}

int main() {
    auto root = node(1);
    root->right = node(2);
    std::vector<std::optional<int>> tokens;
    write(root.get(), tokens);
    assert((tokens
            == std::vector<std::optional<int>>{1, std::nullopt, 2, std::nullopt, std::nullopt}));
    assert(tokens.size() == 5);
    std::cout << "checks passed\n";
    return 0;
}
