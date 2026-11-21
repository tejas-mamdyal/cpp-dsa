/*
 Owned binary tree with at most 100 nodes; empty tree is a null unique_ptr; int values
may repeat. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

Serialize a fixture, parse it, then recursively compare both shapes and
values.

The sample emits 15 tokens; parse recreates a separate seven-node ownership tree
with the same shape.

The serializer and parser consume the same recursive grammar; structural equality
checks more than an inorder sequence.

O(n) time, O(n) encoded/copied tree storage and O(height) frames.

Compare shape explicitly: inorder values alone cannot certify roundtrip correctness.
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

bool equal(const Node* a, const Node* b) {
    if (!a || !b) {
        return a == b;
    }
    return a->value == b->value && equal(a->left.get(), b->left.get())
           && equal(a->right.get(), b->right.get());
}

int main() {
    auto root = sample();
    std::vector<std::optional<int>> tokens;
    write(root.get(), tokens);
    auto copy = parse(tokens);
    assert(copy && equal(root.get(), copy->get()));
    assert(root.get() != copy->get());
    assert(tokens.size() == 15);
    std::cout << "checks passed\n";
    return 0;
}
