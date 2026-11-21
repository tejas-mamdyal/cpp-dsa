/*
 At least 2 sorted distinct integer positions 0..1000000;0<=extra<=1000.

IDEA AND STATE: A gap needs ceil(gap/limit)-1 new stations; repeat 80 midpoint refinements.

TRACE: 0,10 with one extra ->approximately 5.

At maximum gap5,the length10 gap needs one station;smaller limits require at least two,so the
boundary is5.

Allowed maximum gap is monotone; each refinement retains a feasible upper bound
and halves uncertainty.

O(80*n) time, O(1) space; floating arithmetic is approximate.

Never compare floating results for exact equality; bound the quotient before
converting it to an integer.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

double gasGap(const std::vector<int>& p, int extra) {
    assert(p.size() >= 2 && extra >= 0 && extra <= 1000);
    double low = 0.0;
    double high = 0.0;
    for (std::size_t i = 1; i < p.size(); ++i) {
        assert(p[i] > p[i - 1]);
        high = std::max(high, static_cast<double>(p[i] - p[i - 1]));
    }
    for (int step = 0; step < 80; ++step) {
        double mid = (low + high) / 2.0;
        int used = 0;
        bool ok = true;
        for (std::size_t i = 1; i < p.size(); ++i) {
            double required = std::ceil((p[i] - p[i - 1]) / mid) - 1.0;
            if (required > extra - used) {
                ok = false;
                break;
            }
            used += static_cast<int>(required);
        }
        if (ok) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    assert(std::abs(gasGap({0, 10}, 1) - 5.0) < 1e-6);
    assert(std::abs(gasGap({0, 3, 10}, 0) - 7.0) < 1e-6);
    assert(std::abs(gasGap({0, 9}, 2) - 3.0) < 1e-6);
    std::cout << "checks passed\n";
    return 0;
}
