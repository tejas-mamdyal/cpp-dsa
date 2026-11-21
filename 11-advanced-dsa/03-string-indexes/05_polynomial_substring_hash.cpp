/*
 Byte strings<=1000; modulus 2..1000000007; intermediate products fit long long.

prefix[i] hashes first i bytes with multiply-by 31 then add; powers[len]
shifts a preceding prefix into the same position for subtraction.

aba at positions 0 and 2 has equal normalized hashes; a and r collide modulo 17
despite being unequal.

Expanding the polynomial cancels exactly the left prefix and leaves the requested
substring polynomial.

O(n) build/storage, O(1) hash query.

Equal hashes are not proof of equal strings; the explicit collision is intentional.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

class Hash {
    long long mod;
    std::vector<long long> powers;
    std::vector<long long> prefix;

public:
    explicit Hash(const std::string& text, long long modulus = 1000000007)
        : mod(modulus),
          powers(text.size() + 1, 1),
          prefix(text.size() + 1, 0) {
        assert(mod >= 2 && mod <= 1000000007);
        for (std::size_t i = 0; i < text.size(); ++i) {
            powers[i + 1] = powers[i] * 31 % mod;
            prefix[i + 1] = (prefix[i] * 31 + static_cast<unsigned char>(text[i]) + 1) % mod;
        }
    }

    long long range(std::size_t l, std::size_t r) const {
        assert(l <= r && r < prefix.size());
        return (prefix[r] - prefix[l] * powers[r - l] % mod + mod) % mod;
    }
};

int main() {
    Hash h("ababa");
    assert(h.range(0, 3) == h.range(2, 5));
    assert(h.range(1, 1) == 0);
    Hash tiny("ar", 17);
    assert(tiny.range(0, 1) == tiny.range(1, 2));
    assert(std::string("a") != "r");
    std::cout << "checks passed\n";
    return 0;
}
