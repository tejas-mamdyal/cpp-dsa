/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

sorted holds distinct values; rank[i] identifies original a[i] in that
order.

Values-5,7,100 map to 0,1,2; both 100 positions retain rank 2.

Sorting unique values gives a bijection preserving equality and strict
comparison.

O(n log(n+1)) time, O(n) copied/rank storage.

Rank distance does not preserve numeric or geometric distance.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstddef>

std::pair<std::vector<int>, std::vector<int>> compress(const std::vector<int>& a) {
    auto sorted = a;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    std::vector<int> ranks;
    for (int x : a) {
        ranks.push_back(
            static_cast<int>(std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()));
    }
    return {ranks, sorted};
}

int main() {
    auto [rank, values] = compress({100, -5, 100, 7});
    assert((rank == std::vector<int>{2, 0, 2, 1}));
    for (std::size_t i = 0; i < rank.size(); ++i) {
        assert(values[rank[i]] == std::vector<int>({100, -5, 100, 7})[i]);
    }
    assert(compress({}).first.empty());
    std::cout << "checks passed\n";
    return 0;
}
