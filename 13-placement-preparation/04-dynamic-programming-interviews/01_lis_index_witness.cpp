/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

length[i] is the best strict subsequence ending at i; previous records its
preceding index.

1,2,5 has length 3; equal 2 cannot extend 2.

Every ending subsequence chooses an earlier smaller predecessor or only itself.

O(n^2) time, O(n) states/witness.

A sorted set of values is not necessarily an original-order subsequence.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>

std::vector<int> increasing(const std::vector<int>& a) {
    if (a.empty()) {
        return {};
    }
    std::vector<int> length(a.size(), 1);
    std::vector<int> previous(a.size(), -1);
    int best = 0;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && length[j] + 1 > length[i]) {
                length[i] = length[j] + 1;
                previous[i] = j;
            }
        }
        if (length[i] > length[best]) {
            best = i;
        }
    }
    std::vector<int> out;
    for (int at = best; at != -1; at = previous[at]) {
        out.push_back(at);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

int main() {
    std::vector<int> a{3, 1, 2, 2, 5};
    auto out = increasing(a);
    assert(out.size() == 3);
    for (std::size_t i = 1; i < out.size(); ++i) {
        assert(out[i - 1] < out[i] && a[out[i - 1]] < a[out[i]]);
    }
    assert(increasing({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
