/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

seen contains only earlier indices.

Two 3 values satisfy 6; one 3 cannot pair with itself.

Any returned complement precedes the current index; every earlier candidate is
represented.

O(n log n) time, O(n) map storage.

Inserting before lookup can reuse the same index.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <utility>
#include <map>

std::optional<std::pair<int, int>> pairSum(const std::vector<int>& a, int target) {
    std::map<int, int> seen;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        auto found = seen.find(target - a[i]);
        if (found != seen.end()) {
            return std::pair<int, int>{found->second, i};
        }
        seen.emplace(a[i], i);
    }
    return std::nullopt;
}

int main() {
    auto p = pairSum({3, 3}, 6);
    assert(p && p->first == 0 && p->second == 1);
    assert(!pairSum({3}, 6));
    std::cout << "checks passed\n";
    return 0;
}
