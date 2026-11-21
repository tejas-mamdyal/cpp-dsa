/*
 At most 100 distinct lowercase words of length<=30; empty word is supported unless
narrowed. Invalid uppercase or nonletter input is rejected before indexing. Unless narrowed,
at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume valid
acyclic owned structures; exponential searches use the smaller bounds stated here. No input;
keep assertions enabled. Success prints checks passed.

The root represents empty prefix; children[0] means a and children[25]
means z. terminal marks complete words independently of prefix existence.

Manually link c, a, t; only t is terminal, so ca exists as a prefix but is not a
stored word.

Every root-to-node label sequence names exactly one prefix; child ownership gives
one allocation owner per edge.

O(length) path creation/search; O(total created prefixes) storage with 26 child slots per
node.

A binary-search tree and a trie use different ordering models; do not infer terminal
from having no children.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <memory>
#include <array>

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

int main() {
    TrieNode root;
    root.children[2] = std::make_unique<TrieNode>();
    auto c = root.children[2].get();
    c->children[0] = std::make_unique<TrieNode>();
    auto a = c->children[0].get();
    a->children[19] = std::make_unique<TrieNode>();
    a->children[19]->terminal = true;
    assert(!a->terminal && a->children[19]->terminal);
    assert(lowercase("cat") && !lowercase("Cat"));
    std::cout << "checks passed\n";
    return 0;
}
