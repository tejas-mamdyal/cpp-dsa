/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

Locate the prefix node, then count complete word endpoints in its subtree.

With app, apple, ape and bat, prefix ap contains three words, app contains two.

A stored word starts with the prefix exactly when its terminal lies in that
subtree.

O(P+26*S) time for prefix length P and visited subtree nodes S; O(max word length)
recursion.

Prefix count counts words, not character nodes or repeated insertion attempts.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include <array>
#include <cstddef>

struct TrieNode {
    bool terminal = false;
    std::array<std::unique_ptr<TrieNode>, 26> children{};
};

bool lowercase(const std::string& word) {
    for (char ch : word) {
        if (ch < 'a' || ch > 'z') {
            return false;
        }
    }
    return true;
}

bool insert(TrieNode& root, const std::string& word) {
    if (!lowercase(word)) {
        return false;
    }
    auto current = &root;
    for (char ch : word) {
        std::size_t index = static_cast<std::size_t>(ch - 'a');
        if (!current->children[index]) {
            current->children[index] = std::make_unique<TrieNode>();
        }
        current = current->children[index].get();
    }
    bool added = !current->terminal;
    current->terminal = true; // A complete word endpoint is independent of having children.
    return added;
}

const TrieNode* locate(const TrieNode& root, const std::string& prefix) {
    if (!lowercase(prefix)) {
        return nullptr;
    }
    auto current = &root;
    for (char ch : prefix) {
        current = current->children[static_cast<std::size_t>(ch - 'a')].get();
        if (!current) {
            return nullptr;
        }
    }
    return current;
}

bool contains(const TrieNode& root, const std::string& word) {
    auto node = locate(root, word);
    return node && node->terminal;
}

int terminals(const TrieNode* root) {
    if (!root) {
        return 0;
    }
    int total = root->terminal ? 1 : 0;
    for (const auto& child : root->children) {
        total += terminals(child.get());
    }
    return total;
}

int prefixCount(const TrieNode& root, const std::string& prefix) {
    return terminals(locate(root, prefix));
}

int main() {
    TrieNode root;
    for (const auto& word : {"app", "apple", "ape", "bat"}) {
        insert(root, word);
    }
    assert(prefixCount(root, "ap") == 3);
    assert(prefixCount(root, "app") == 2);
    assert(prefixCount(root, "missing") == 0);
    std::cout << "checks passed\n";
    return 0;
}
