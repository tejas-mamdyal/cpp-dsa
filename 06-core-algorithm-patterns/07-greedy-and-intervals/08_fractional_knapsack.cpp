/*
 At most 1000 items; weights 1..1000000, values 0..1000000; capacity 0..1000000; fractions
allowed.

IDEA AND STATE: Sort by value/weight using exact cross-products, then take a full item or the
remaining fraction.

TRACE: (weight 10, value 60),(20,100),(30,120), capacity 50 ->240.

Take weight10 at density6,then20 at density5,and20 of the final30 at
density4;value60+100+80=240.

Replacing any lower-density taken weight by available higher-density weight never
decreases value; repeat to obtain sorted filling.

O(n log n) time, O(n) copied input.

This proof permits splitting items and does not establish a 0/1 knapsack algorithm.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

struct Item {
    int weight;
    int value;
};

double fractional(std::vector<Item> a, int capacity) {
    assert(capacity >= 0);
    std::sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
        return 1LL * x.value * y.weight > 1LL * y.value * x.weight;
    });
    double value = 0.0;
    for (const auto& x : a) {
        assert(x.weight > 0 && x.value >= 0);
        int used = std::min(capacity, x.weight);
        value += static_cast<double>(used) * x.value / x.weight;
        capacity -= used;
    }
    return value;
}

int main() {
    assert(std::abs(fractional({{10, 60}, {20, 100}, {30, 120}}, 50) - 240.0) < 1e-9);
    assert(fractional({}, 10) == 0.0);
    assert(fractional({{2, 3}}, 0) == 0.0);
    std::cout << "checks passed\n";
    return 0;
}
