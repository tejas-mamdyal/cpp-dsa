/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

Query lowercase length<=30; return longest stored word that prefixes it, or
absence.

With a, app, apple, query applesauce returns apple; query banana has no answer.

Each query prefix has one trie position; the last visited terminal is exactly the
longest matching stored prefix.

O(query length) time, O(1) auxiliary plus returned string.

An empty stored word is a valid empty prefix, distinct from no stored prefix.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <optional>
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

std::optional<std::string> longest(const TrieNode& root, const std::string& query) {
    if (!lowercase(query)) {
        return std::nullopt;
    }
    const TrieNode* current = &root;
    std::optional<std::size_t> best;
    if (root.terminal) {
        best = 0;
    }
    for (std::size_t i = 0; i < query.size(); ++i) {
        current = current->children[query[i] - 'a'].get();
        if (!current) {
            break;
        }
        if (current->terminal) {
            best = i + 1;
        }
    }
    if (!best) {
        return std::nullopt;
    }
    return query.substr(0, *best);
}

int main() {
    TrieNode root;
    for (const auto& word : {"a", "app", "apple"}) {
        insert(root, word);
    }
    assert(longest(root, "applesauce") == "apple");
    assert(!longest(root, "banana"));
    insert(root, "");
    assert(longest(root, "banana") == "");
    std::cout << "checks passed\n";
    return 0;
}
