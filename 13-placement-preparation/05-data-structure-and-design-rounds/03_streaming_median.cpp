/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

All lower values<=all upper values; low has equal size or one extra.

Stream 3,1 has median 2; adding 8 makes 3 the middle.

Root transfers preserve ordering and restore the size invariant, placing middle
values at roots.

O(log n) insertion, O(1) query, O(n) storage.

Balance sizes as well as value order.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <queue>
#include <functional>

class Median {
    std::priority_queue<int> low;
    std::priority_queue<int, std::vector<int>, std::greater<int>> high;

public:
    void add(int x) {
        if (low.empty() || x <= low.top()) {
            low.push(x);
        } else {
            high.push(x);
        }
        if (low.size() > high.size() + 1) {
            high.push(low.top());
            low.pop();
        }
        if (high.size() > low.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    std::optional<double> value() const {
        if (low.empty()) {
            return std::nullopt;
        }
        if (low.size() > high.size()) {
            return low.top();
        }
        return (static_cast<double>(low.top()) + high.top()) / 2.0;
    }
};

int main() {
    Median m;
    assert(!m.value());
    m.add(3);
    m.add(1);
    assert(m.value() == 2.0);
    m.add(8);
    assert(m.value() == 3.0);
    std::cout << "checks passed\n";
    return 0;
}
