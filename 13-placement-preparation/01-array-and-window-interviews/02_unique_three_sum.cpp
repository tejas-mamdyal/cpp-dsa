/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

For each distinct first value, two pointers search the sorted suffix.

-1 pairs with 0,1 and-1,2 once each.

If sum is too small, no smaller right with that left helps; the symmetric
exclusion handles large sums.

O(n^2) time, O(n) sort copy plus output.

Skip duplicate values without excluding distinct valid triples.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <array>

std::vector<std::array<int, 3>> triples(std::vector<int> a) {
    std::sort(a.begin(), a.end());
    std::vector<std::array<int, 3>> out;
    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (i && a[i] == a[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = static_cast<int>(a.size()) - 1;
        while (left < right) {
            int sum = a[i] + a[left] + a[right];
            if (sum < 0) {
                ++left;
            } else if (sum > 0) {
                --right;
            } else {
                out.push_back({a[i], a[left], a[right]});
                int value = a[left];
                while (left < right && a[left] == value) {
                    ++left;
                }
            }
        }
    }
    return out;
}

int main() {
    assert(triples({-1, 0, 1, 2, -1, -4}).size() == 2);
    assert(triples({0, 0, 0, 0}).size() == 1);
    assert(triples({}).empty());
    std::cout << "checks passed\n";
    return 0;
}
