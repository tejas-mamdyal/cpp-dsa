/*
 Initially zero array, n<=30; valid half-open updates and point queries. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

a[i] stores explicit partial updates; lazy[block] stores additions applied
uniformly to its whole block.

Adding 2 everywhere then-1 to 2..6 leaves outside values 2 and inside 1.

Each update is decomposed into explicit partial positions and uniform full
blocks; point access sums exactly both contribution classes.

O(sqrt n) range add, O(1) point query, O(n) storage.

Applying a full-block tag without checking full containment would update positions
outside the request.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cmath>

class RangeBlocks {
    std::vector<long long> a;
    std::vector<long long> lazy;
    std::size_t width;

public:
    explicit RangeBlocks(std::size_t n)
        : a(n, 0),
          width(
              static_cast<std::size_t>(std::sqrt(static_cast<double>(std::max<std::size_t>(1, n))))
              + 1) {
        lazy.assign((n + width - 1) / width, 0);
    }

    void add(std::size_t l, std::size_t r, long long value) {
        while (l < r && l % width != 0) {
            a[l] += value;
            ++l;
        }
        while (l + width <= r) {
            lazy[l / width] += value;
            l += width;
        }
        while (l < r) {
            a[l] += value;
            ++l;
        }
    }

    long long at(std::size_t i) const {
        return a[i] + lazy[i / width];
    }
};

int main() {
    RangeBlocks b(8);
    b.add(0, 8, 2);
    b.add(2, 6, -1);
    assert(b.at(0) == 2 && b.at(3) == 1 && b.at(7) == 2);
    std::cout << "checks passed\n";
    return 0;
}
