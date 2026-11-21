/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

Unmark a terminal; while unwinding, delete an empty nonterminal child. Root
remains as an owned value.

Erase app while apple remains: the path app is retained but its terminal
clears; erasing apple can then prune the whole branch.

A child with no terminal and no children represents no remaining word, so removing
it preserves all exact/prefix answers.

O(26*L) time, O(L) recursion; frees unused owned nodes.

Deleting an entire shared prefix would destroy longer words.
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

bool emptyNode(const TrieNode& root) {
    if (root.terminal) {
        return false;
    }
    for (const auto& child : root.children) {
        if (child) {
            return false;
        }
    }
    return true;
}

bool eraseAt(TrieNode& root, const std::string& word, std::size_t index) {
    if (index == word.size()) {
        if (!root.terminal) {
            return false;
        }
        root.terminal = false;
        return true;
    }
    std::size_t edge = static_cast<std::size_t>(word[index] - 'a');
    auto& child = root.children[edge];
    if (!child || !eraseAt(*child, word, index + 1)) {
        return false;
    }
    if (emptyNode(*child)) {
        child.reset();
    }
    return true;
}

bool erase(TrieNode& root, const std::string& word) {
    if (!lowercase(word)) {
        return false;
    }
    return eraseAt(root, word, 0);
}

int main() {
    TrieNode root;
    insert(root, "app");
    insert(root, "apple");
    assert(erase(root, "app"));
    assert(!contains(root, "app") && contains(root, "apple"));
    assert(!erase(root, "app"));
    assert(erase(root, "apple"));
    assert(!locate(root, "a"));
    insert(root, "");
    assert(erase(root, "") && !contains(root, ""));
    std::cout << "checks passed\n";
    return 0;
}
