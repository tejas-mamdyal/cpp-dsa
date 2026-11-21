/*
 Lowercase text; valid half-open queries; ask whether its characters can be permuted
into a palindrome.

IDEA AND STATE: Toggle one of 26 bits per character; XOR two prefix masks to obtain odd-count
letters.

TRACE: aabbc permits a palindrome; ab does not.

For aabbc,paired a and b toggles cancel and only c remains odd;ab instead leaves two odd bits.

At most one odd-frequency character is exactly the palindrome-permutation
condition.

O(n) preprocessing, O(1) fixed-width query, O(n) masks.

This does not test whether the original substring itself is a palindrome.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

std::vector<unsigned int> parityPrefix(const std::string& text) {
    std::vector<unsigned int> p(text.size() + 1, 0U);
    for (std::size_t i = 0; i < text.size(); ++i) {
        assert(text[i] >= 'a' && text[i] <= 'z');
        p[i + 1] = p[i] ^ (1U << (text[i] - 'a'));
    }
    return p;
}

bool canPermute(const std::vector<unsigned int>& p, std::size_t l, std::size_t r) {
    unsigned int mask = p[r] ^ p[l];
    return mask == 0U || (mask & (mask - 1U)) == 0U;
}

int main() {
    auto p = parityPrefix("aabbc");
    assert(canPermute(p, 0, 5));
    assert(canPermute(p, 0, 4));
    assert(!canPermute(parityPrefix("ab"), 0, 2));
    assert(canPermute(p, 2, 2));
    std::cout << "checks passed\n";
    return 0;
}
