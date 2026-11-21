/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Left pass establishes rising-left requirements; right pass adds only
missing rising-right requirements.

Ratings 1,0,2 require candies 2,1,2.

Every position must satisfy the maximum of its independent left/right lower
bounds, and the two passes attain those bounds.

O(n) time, O(n) storage.

Equal ratings impose no greater-than constraint.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <numeric>

int candy(const std::vector<int>& ratings) {
    std::vector<int> count(ratings.size(), 1);
    for (std::size_t i = 1; i < ratings.size(); ++i) {
        if (ratings[i] > ratings[i - 1]) {
            count[i] = count[i - 1] + 1;
        }
    }
    for (std::size_t i = ratings.size(); i > 1; --i) {
        if (ratings[i - 2] > ratings[i - 1]) {
            count[i - 2] = std::max(count[i - 2], count[i - 1] + 1);
        }
    }
    return std::accumulate(count.begin(), count.end(), 0);
}

int main() {
    assert(candy({1, 0, 2}) == 5 && candy({1, 2, 2}) == 4 && candy({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
