/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

Use a deterministic word pool, duplicate insertions, erasures and several
prefixes; reference filters a sorted set.

After insert app, apple, ape and erase app, prefix ap yields ape, apple in both
models.

Set membership independently models exact words; filtering by string prefix
independently models ordered suggestions.

O(operations*(26*S+model words*L)) bounded diagnostic time; O(total prefixes+model words)
space.

Check intermediate results after every mutation, not only the final dictionary.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <memory>
#include <set>
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
    std::set<std::string> model;
    std::vector<std::string> pool{"", "a", "app", "apple", "ape", "bat", "bad"};
    for (int step = 0; step < 60; ++step) {
        const auto& word = pool[static_cast<std::size_t>(step) % pool.size()];
        if (step % 3 == 0) {
            assert(erase(root, word) == (model.erase(word) > 0));
        } else {
            assert(insert(root, word) == model.insert(word).second);
        }
        for (const auto& prefix : std::vector<std::string>{"", "a", "ap", "b", "z"}) {
            std::vector<std::string> expected;
            for (const auto& value : model) {
                if (value.compare(0, prefix.size(), prefix) == 0) {
                    expected.push_back(value);
                }
            }
            assert(suggest(root, prefix, 100) == expected);
        }
        for (const auto& value : pool) {
            assert(contains(root, value) == (model.count(value) > 0));
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
