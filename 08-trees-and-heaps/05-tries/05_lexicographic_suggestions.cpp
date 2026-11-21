/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

After locating prefix, save terminal before longer extensions and visit
children a..z; stop once limit answers are collected.

With app, apple, ape, prefix ap and limit 2 yields ape, app.

Prefix-first and alphabetic child order is lexicographic; early stopping removes
only later-ranked answers.

O(P+26*S+output characters) time for actually visited nodes S; O(L) path/stack plus
output.

Limit 0 must return no suggestions; missing/invalid prefix returns an empty vector.
*/
#include <iostream>
#include <cassert>
#include <vector>
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

void collect(const TrieNode* root,
             std::string& path,
             std::size_t limit,
             std::vector<std::string>& out) {
    if (!root || out.size() >= limit) {
        return;
    }
    if (root->terminal) {
        out.push_back(path);
    }
    for (std::size_t i = 0; i < 26 && out.size() < limit; ++i) {
        if (root->children[i]) {
            path.push_back(static_cast<char>(
                'a' + i)); // Choose this route element before exploring its completions.
            collect(root->children[i].get(), path, limit, out);
            path.pop_back(); // Undo so the next sibling sees the same entry prefix.
        }
    }
}

std::vector<std::string>
suggest(const TrieNode& root, const std::string& prefix, std::size_t limit) {
    std::string path = prefix;
    std::vector<std::string> out;
    collect(locate(root, prefix), path, limit, out);
    return out;
}

int main() {
    TrieNode root;
    for (const auto& word : {"app", "apple", "ape"}) {
        insert(root, word);
    }
    assert((suggest(root, "ap", 2) == std::vector<std::string>{"ape", "app"}));
    assert(suggest(root, "ap", 0).empty());
    assert(suggest(root, "z", 3).empty());
    std::cout << "checks passed\n";
    return 0;
}
