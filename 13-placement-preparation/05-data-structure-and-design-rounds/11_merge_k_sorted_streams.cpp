/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

The heap holds the smallest unconsumed item of every nonexhausted stream.

The two leading 1 values are emitted before 3 and 4.

Every other unconsumed item is no smaller than its own stream head, so the global
head minimum is safe.

O(N log(k+1)) time, O(k) heap plus O(N) output.

Do not drop duplicate values; this is multiset merge.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
#include <cstddef>

std::vector<int> mergeAll(const std::vector<std::vector<int>>& streams) {
    using Item = std::tuple<int, std::size_t, std::size_t>;
    std::priority_queue<Item, std::vector<Item>, std::greater<Item>> heap;
    for (std::size_t i = 0; i < streams.size(); ++i) {
        if (!streams[i].empty()) {
            heap.emplace(streams[i][0], i, 0);
        }
    }
    std::vector<int> out;
    while (!heap.empty()) {
        auto [value, stream, index] = heap.top();
        heap.pop();
        out.push_back(value);
        ++index;
        if (index < streams[stream].size()) {
            heap.emplace(streams[stream][index], stream, index);
        }
    }
    return out;
}

int main() {
    assert((mergeAll({{1, 4}, {}, {1, 3, 5}}) == std::vector<int>{1, 1, 3, 4, 5}));
    assert(mergeAll({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
