/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

index is the next unread token; nullopt describes a missing child.
optional<Tree> distinguishes invalid encoding from a valid empty tree.

Tokens 1,2, null, null,3, null, null build root 1 with children 2 and 3; missing final null
is invalid.

Each nonnull token consumes exactly one recursively encoded left and right
subtree; the final index rejects trailing tokens.

O(n) time, O(height) stack plus owned tree.

No numeric sentinel is reserved, so every int value remains usable; partial trees clean
up automatically.
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
    auto tree = parse({1, 2, std::nullopt, std::nullopt, 3, std::nullopt, std::nullopt});
    assert(tree && (*tree)->left->value == 2 && (*tree)->right->value == 3);
    assert(!parse({1, std::nullopt}));
    assert(!parse({std::nullopt, 2}));
    auto empty = parse({std::nullopt});
    assert(empty && !(*empty));
    std::cout << "checks passed\n";
    return 0;
}
