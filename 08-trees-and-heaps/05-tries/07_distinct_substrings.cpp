/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

For lowercase text length<=30, count nonempty substrings: every substring is
a prefix of some suffix. Create suffix routes and count only new nodes, ignoring terminal
markers.

ababa has 9 distinct nonempty substrings despite 15 positional substrings.

Each node route is one distinct substring; all substrings occur on a suffix
route, so new-node count is exact.

O(n^2) time and O(n^2) trie nodes; each node has 26 slots.

This is a small-input trie baseline, not an advanced suffix-array or suffix-automaton
implementation.
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

long long distinct(const std::string& text) {
    assert(lowercase(text) && text.size() <= 30);
    TrieNode root;
    long long count = 0;
    for (std::size_t start = 0; start < text.size(); ++start) {
        auto current = &root;
        for (std::size_t i = start; i < text.size(); ++i) {
            std::size_t edge = static_cast<std::size_t>(text[i] - 'a');
            if (!current->children[edge]) {
                current->children[edge] = std::make_unique<TrieNode>();
                ++count;
            }
            current = current->children[edge].get();
        }
    }
    return count;
}

int main() {
    assert(distinct("ababa") == 9);
    assert(distinct("aaa") == 3);
    assert(distinct("") == 0);
    for (const auto& s : std::vector<std::string>{"abc", "aab", "abab"}) {
        std::set<std::string> reference;
        for (std::size_t l = 0; l < s.size(); ++l) {
            for (std::size_t r = l + 1; r <= s.size(); ++r) {
                reference.insert(s.substr(l, r - l));
            }
        }
        assert(distinct(s) == static_cast<long long>(reference.size()));
    }
    std::cout << "checks passed\n";
    return 0;
}
