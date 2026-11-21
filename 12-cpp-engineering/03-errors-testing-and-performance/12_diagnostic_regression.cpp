/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Empty is an explicit valid boundary outcome; nonempty returns the final
value.

An incorrect size()-1 access fails first on the empty vector.

The guard guarantees back is only called for a nonempty container.

O(1) time/storage.

Undefined behavior is not reliably caught by a normal run; use address/undefined
sanitizers where available.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>

std::optional<int> last(const std::vector<int>& a) {
    if (a.empty()) {
        return std::nullopt;
    }
    return a.back();
}

int main() {
    assert(!last({}));
    assert(last({7}) == 7);
    assert(last({7, 9}) == 9);
    std::cout << "checks passed\n";
    return 0;
}
