/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

ok[i][j] forms the first i+j result characters from source prefixes i, j.

Each final character must come from the end of one chosen prefix.

The two transitions enumerate every legal last-source choice while preserving
each source order.

O(n*m) time/storage.

Matching only total character frequencies does not preserve source order.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

bool interleaves(const std::string& a, const std::string& b, const std::string& s) {
    if (a.size() + b.size() != s.size()) {
        return false;
    }
    std::vector<std::vector<bool>> ok(a.size() + 1, std::vector<bool>(b.size() + 1));
    ok[0][0] = true;
    for (std::size_t i = 0; i <= a.size(); ++i) {
        for (std::size_t j = 0; j <= b.size(); ++j) {
            if (i > 0 && a[i - 1] == s[i + j - 1]) {
                ok[i][j] = ok[i][j] || ok[i - 1][j];
            }
            if (j > 0 && b[j - 1] == s[i + j - 1]) {
                ok[i][j] = ok[i][j] || ok[i][j - 1];
            }
        }
    }
    return ok.back().back();
}

int main() {
    assert(interleaves("aabcc", "dbbca", "aadbbcbcac"));
    assert(!interleaves("aabcc", "dbbca", "aadbbbaccc"));
    assert(interleaves("", "", ""));
    std::cout << "checks passed\n";
    return 0;
}
