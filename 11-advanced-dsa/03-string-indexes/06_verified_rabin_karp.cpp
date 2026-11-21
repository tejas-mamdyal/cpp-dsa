/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

The hash is a fast rejection filter; only exact substring comparison can
emit a match.

Both a and r pass the tiny-modulus hash filter, but exact comparison rejects r.

True equal strings always have equal hashes; verification excludes every
collision false positive.

O(n+m+K*m) time for K hash candidates, worst-case O(n*m); O(n+m) hash storage plus
output.

Do not advertise deterministic linear time when character verification can be
repeated many times.
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

std::vector<int> verified(const std::string& text, const std::string& pattern, long long modulus) {
    std::vector<int> out;
    if (pattern.size() > text.size()) {
        return out;
    }
    Hash h(text, modulus);
    Hash p(pattern, modulus);
    long long goal = p.range(0, pattern.size());
    for (std::size_t i = 0; i + pattern.size() <= text.size(); ++i) {
        if (h.range(i, i + pattern.size()) == goal
            && text.compare(i, pattern.size(), pattern) == 0) {
            out.push_back(static_cast<int>(i));
        }
    }
    return out;
}

int main() {
    assert((verified("ar", "a", 17) == std::vector<int>{0}));
    assert((verified("aaa", "aa", 17) == std::vector<int>{0, 1}));
    assert(verified("abc", "", 17).size() == 4);
    std::cout << "checks passed\n";
    return 0;
}
