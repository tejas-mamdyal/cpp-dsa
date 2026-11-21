/*
 Nonempty lowercase patterns, total length<=300, at most 30 patterns; lowercase
text<=1000; output(patternID, startIndex).

The scan state is the longest trie prefix matching the current text
suffix. Failure links shorten that prefix; output links jump directly to the next terminal
suffix.

Scanning she reports both she and its suffix he; separate pattern IDs preserve
duplicate-pattern occurrences.

Failure transitions retain the longest possible suffix continuation;
terminal/output chains enumerate every pattern ending here without revisiting irrelevant
suffixes.

O(26*total trie nodes+text length+reported matches) time, O(26*nodes+patterns+output)
storage.

Build the full trie before filling fallback transitions; adding patterns afterward
would confuse trie edges with completed automaton moves.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <array>

class Matcher {
    struct Node {
        std::array<int, 26> go;
        int failure = 0;
        int output = 0;
        std::vector<int> ids;

        Node() {
            go.fill(-1);
        }
    };

    std::vector<Node> nodes{1};
    std::vector<int> length;

public:
    explicit Matcher(const std::vector<std::string>& patterns) {
        for (int id = 0; id < static_cast<int>(patterns.size()); ++id) {
            assert(!patterns[id].empty());
            length.push_back(static_cast<int>(patterns[id].size()));
            int p = 0;
            for (char ch : patterns[id]) {
                assert(ch >= 'a' && ch <= 'z');
                int letter = ch - 'a';
                int next = nodes[p].go[letter];
                if (next == -1) {
                    next = static_cast<int>(nodes.size());
                    nodes[p].go[letter] = next;
                    nodes.emplace_back();
                }
                p = next;
            }
            nodes[p].ids.push_back(id);
        }
        std::queue<int> q;
        for (int letter = 0; letter < 26; ++letter) {
            int child = nodes[0].go[letter];
            if (child == -1) {
                nodes[0].go[letter] = 0;
            } else {
                q.push(child);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (int letter = 0; letter < 26; ++letter) {
                int child = nodes[p].go[letter];
                if (child == -1) {
                    nodes[p].go[letter] = nodes[nodes[p].failure].go[letter];
                } else {
                    int fallback = nodes[nodes[p].failure].go[letter];
                    nodes[child].failure = fallback;
                    nodes[child].output =
                        nodes[fallback].ids.empty() ? nodes[fallback].output : fallback;
                    q.push(child);
                }
            }
        }
    }

    std::vector<std::pair<int, int>> matches(const std::string& text) const {
        std::vector<std::pair<int, int>> out;
        int state = 0;
        for (int i = 0; i < static_cast<int>(text.size()); ++i) {
            assert(text[i] >= 'a' && text[i] <= 'z');
            state = nodes[state].go[text[i] - 'a'];
            for (int p = state; p != 0; p = nodes[p].output) {
                for (int id : nodes[p].ids) {
                    out.emplace_back(id, i + 1 - length[id]);
                }
            }
        }
        return out;
    }
};

int main() {
    Matcher m({"he", "she", "his", "hers"});
    auto out = m.matches("ahishers");
    std::sort(out.begin(), out.end());
    assert((out == std::vector<std::pair<int, int>>{{0, 4}, {1, 3}, {2, 1}, {3, 4}}));
    assert(Matcher({}).matches("abc").empty());
    assert(Matcher({"a", "a"}).matches("a").size() == 2);
    Matcher overlap({"a", "aa"});
    auto matches = overlap.matches("aaa");
    std::sort(matches.begin(), matches.end());
    assert((matches == std::vector<std::pair<int, int>>{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}}));
    std::cout << "checks passed\n";
    return 0;
}
