/*
 Output<=1000 bytes; invalid grammar or excessive expansion returns absence. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

Each group is a lowercase letter followed by a positive decimal count;
limit each partial count before multiplying again.

a 2b 3 emits aa then bbb.

Every accepted group is complete and the output limit is checked before
allocation.

O(input+output) time, O(output) storage.

Unbounded decimal accumulation can overflow before a final range check.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <optional>
#include <cstddef>

std::optional<std::string> expand(const std::string& encoded) {
    std::string out;
    std::size_t i = 0;
    while (i < encoded.size()) {
        char ch = encoded[i++];
        if (ch < 'a' || ch > 'z') {
            return std::nullopt;
        }
        int count = 0;
        bool digit = false;
        while (i < encoded.size() && encoded[i] >= '0' && encoded[i] <= '9') {
            digit = true;
            count = count * 10 + encoded[i++] - '0';
            if (count > 1000) {
                return std::nullopt;
            }
        }
        if (!digit || count == 0 || out.size() + count > 1000) {
            return std::nullopt;
        }
        out.append(static_cast<std::size_t>(count), ch);
    }
    return out;
}

int main() {
    assert(expand("a2b3") == "aabbb");
    assert(!expand("a0") && !expand("2a") && !expand("a999999999999"));
    assert(expand("") == "");
    std::cout << "checks passed\n";
    return 0;
}
