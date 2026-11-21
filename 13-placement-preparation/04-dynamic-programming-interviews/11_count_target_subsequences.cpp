/*
 Source length<=30; counts fit signed 64 bits.

count[j] counts index subsets spelling the first j target characters.

Any one of three b occurrences may be omitted in rabbbit.

A matching character either supplies the final target position or is skipped;
descending j prevents reusing it.

O(n*m) time, O(m) storage.

Count index choices, not distinct resulting text strings.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

long long subsequences(const std::string& source, const std::string& target) {
    std::vector<long long> count(target.size() + 1);
    count[0] = 1;
    for (char ch : source) {
        for (std::size_t j = target.size(); j > 0; --j) {
            if (ch == target[j - 1]) {
                count[j] += count[j - 1];
            }
        }
    }
    return count.back();
}

int main() {
    assert(subsequences("rabbbit", "rabbit") == 3);
    assert(subsequences("abc", "") == 1);
    assert(subsequences("", "a") == 0);
    std::cout << "checks passed\n";
    return 0;
}
