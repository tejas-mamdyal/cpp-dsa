/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

Insertion walks or creates the word route, then marks terminal; returns
false on invalid or already-present input.

Insert app and apple; both endpoints become terminal; ap remains prefix-only.

A successful exact search requires both every edge and the terminal marker, which
insertion sets exactly for stored words.

O(L) time per operation, O(L) new nodes per insertion in worst case.

Validate the full string before mutating, so invalid input cannot leave a partial
inserted prefix.
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

int main() {
    TrieNode root;
    assert(insert(root, "app"));
    assert(insert(root, "apple"));
    assert(!insert(root, "app"));
    assert(contains(root, "app") && !contains(root, "ap"));
    assert(!insert(root, "bad!"));
    assert(!locate(root, "bad"));
    assert(insert(root, "") && contains(root, ""));
    std::cout << "checks passed\n";
    return 0;
}
