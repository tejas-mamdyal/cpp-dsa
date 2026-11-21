/*
 Byte text length<=1000; substring membership includes empty; count distinct nonempty
substrings.

Each state groups substrings with the same ending positions; length is the
longest member, suffix link reaches the next shorter class. Clone a state when extension must
split a length interval.

ababa has nine distinct substrings; following b, a, b transitions confirms bab
without scanning all starting positions.

Extensions preserve all substring transitions; clones separate incompatible
length classes without losing paths. State length minus suffix-link length counts its distinct
represented lengths.

O(n log alphabet) construction with maps and O(n) states; query O(m log alphabet); fixed
alphabet makes map factors constant.

Never retain vector element references across state insertion; clone using a copied
value and stable indices.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <cstddef>

class Automaton {
    struct State {
        int length = 0;
        int link = -1;
        std::map<char, int> next;
    };

    std::vector<State> states{{}};
    int last = 0;

    void append(char ch) {
        int current = static_cast<int>(states.size());
        State fresh;
        fresh.length = states[last].length + 1;
        states.push_back(fresh);
        int p = last;
        while (p != -1 && states[p].next.count(ch) == 0) {
            states[p].next[ch] = current;
            p = states[p].link;
        }
        if (p == -1) {
            states[current].link = 0;
        } else {
            int q = states[p].next.at(ch);
            if (states[p].length + 1 == states[q].length) {
                states[current].link = q;
            } else {
                int clone = static_cast<int>(states.size());
                State copy = states[q];
                copy.length = states[p].length + 1;
                states.push_back(copy);
                while (p != -1) {
                    auto found = states[p].next.find(ch);
                    if (found == states[p].next.end() || found->second != q) {
                        break;
                    }
                    found->second = clone;
                    p = states[p].link;
                }
                states[q].link = clone;
                states[current].link = clone;
            }
        }
        last = current;
    }

public:
    explicit Automaton(const std::string& s) {
        for (char ch : s) {
            append(ch);
        }
    }

    bool contains(const std::string& s) const {
        int p = 0;
        for (char ch : s) {
            auto found = states[p].next.find(ch);
            if (found == states[p].next.end()) {
                return false;
            }
            p = found->second;
        }
        return true;
    }

    long long distinct() const {
        long long total = 0;
        for (std::size_t i = 1; i < states.size(); ++i) {
            total += states[i].length - states[states[i].link].length;
        }
        return total;
    }
};

int main() {
    Automaton a("ababa");
    assert(a.contains("bab") && a.contains("") && !a.contains("abb"));
    assert(a.distinct() == 9);
    assert(Automaton("").distinct() == 0);
    assert(Automaton("abb").distinct() == 5);
    assert(Automaton("a").distinct() == 1);
    assert(Automaton("aaaa").distinct() == 4);
    assert(Automaton("abcd").distinct() == 10);
    Automaton repeated("ababa");
    assert(!repeated.contains("ababaa"));
    std::cout << "checks passed\n";
    return 0;
}
