/*
 Uppercase addends/result of length 1..8; at most 8 distinct letters. Return a first
mapping for x+y=z or absence. Unless narrowed, at most 100 nodes/elements with values in
[-1000,1000]. Recursive examples assume valid acyclic owned structures; exponential searches
use the smaller bounds stated here. No input; keep assertions enabled. Success prints checks
passed.

A 26-entry map holds digits or -1; used prevents two letters sharing a
digit. Leading multi-digit letters cannot be zero. Baseline enumerates digit injections; column
pruning is a follow-up.

SEND+MORE=MONEY admits 9567+1085=10652; I+BB=ILL admits 1+99=100.

Every permitted injective mapping is tried; the leaf arithmetic equality selects
exactly solutions.

O(P(10, L)*W) time with L<=8 and total word length W<=24; O(L+26) work plus mapping.

This bounded enumeration is not a fast arbitrary-length solver; use long long when
reconstructing values.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <optional>
#include <array>
#include <cstddef>

long long value(const std::string& s, const std::array<int, 26>& digit) {
    long long out = 0;
    for (char ch : s) {
        out = out * 10 + digit[ch - 'A'];
    }
    return out;
}

bool assign(const std::vector<int>& letters,
            std::size_t i,
            const std::array<bool, 26>& leading,
            std::array<int, 26>& digit,
            std::array<bool, 10>& used,
            const std::string& x,
            const std::string& y,
            const std::string& z) {
    if (i == letters.size()) {
        return value(x, digit) + value(y, digit) == value(z, digit);
    }
    int letter = letters[i];
    for (int d = 0; d <= 9; ++d) {
        if (used[d] || (d == 0 && leading[letter])) {
            continue;
        }
        used[d] = true;
        digit[letter] = d;
        if (assign(letters, i + 1, leading, digit, used, x, y, z)) {
            return true;
        }
        digit[letter] = -1;
        used[d] = false;
    }
    return false;
}

std::optional<std::array<int, 26>>
crypt(const std::string& x, const std::string& y, const std::string& z) {
    std::array<int, 26> digit;
    digit.fill(-1);
    std::array<bool, 26> seen{};
    std::array<bool, 26> leading{};
    std::vector<int> letters;
    for (const auto& word : std::vector<std::string>{x, y, z}) {
        assert(!word.empty() && word.size() <= 8);
        if (word.size() > 1) {
            leading[word[0] - 'A'] = true;
        }
        for (char ch : word) {
            assert(ch >= 'A' && ch <= 'Z');
            int index = ch - 'A';
            if (!seen[index]) {
                seen[index] = true;
                letters.push_back(index);
            }
        }
    }
    assert(letters.size() <= 8);
    std::array<bool, 10> used{};
    if (assign(letters, 0, leading, digit, used, x, y, z)) {
        return digit;
    }
    return std::nullopt;
}

int main() {
    auto a = crypt("I", "BB", "ILL");
    assert(a && value("I", *a) == 1 && value("BB", *a) == 99);
    auto b = crypt("SEND", "MORE", "MONEY");
    assert(b && value("SEND", *b) + value("MORE", *b) == value("MONEY", *b));
    assert(!crypt("A", "B", "AA"));
    std::cout << "checks passed\n";
    return 0;
}
