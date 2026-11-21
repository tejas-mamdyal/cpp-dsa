/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Each block caches its sum; queries scan partial boundary blocks and
consume complete block totals.

Range 1..5 combines boundary values and full blocks; changing 3 to-3 subtracts 6
from one block.

Boundary scans and full blocks partition the query without overlap; point updates
alter only one block aggregate.

O(n) build, O(1) point update, O(sqrt n) query, O(n) storage.

A partial final block cannot be read as if it had the nominal full width.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cmath>

class Blocks {
    std::vector<int> a;
    std::vector<long long> sum;
    std::size_t width;

public:
    explicit Blocks(const std::vector<int>& values)
        : a(values),
          width(static_cast<std::size_t>(
                    std::sqrt(static_cast<double>(std::max<std::size_t>(1, a.size()))))
                + 1) {
        sum.assign((a.size() + width - 1) / width, 0);
        for (std::size_t i = 0; i < a.size(); ++i) {
            sum[i / width] += a[i];
        }
    }

    void set(std::size_t i, int value) {
        sum[i / width] += value - a[i];
        a[i] = value;
    }

    long long query(std::size_t l, std::size_t r) const {
        long long total = 0;
        while (l < r && l % width != 0) {
            total += a[l];
            ++l;
        }
        while (l + width <= r) {
            total += sum[l / width];
            l += width;
        }
        while (l < r) {
            total += a[l];
            ++l;
        }
        return total;
    }
};

int main() {
    Blocks b({1, 2, 3, 4, 5});
    assert(b.query(1, 5) == 14);
    b.set(2, -3);
    assert(b.query(0, 5) == 9);
    assert(Blocks({}).query(0, 0) == 0);
    std::cout << "checks passed\n";
    return 0;
}
