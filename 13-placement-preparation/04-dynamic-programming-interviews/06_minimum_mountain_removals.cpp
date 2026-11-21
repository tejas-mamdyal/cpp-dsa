/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

left/right give strict subsequence lengths ending/starting at the peak.

The sample keeps a length 5 mountain and removes 3.

Every mountain splits at one shared peak into an increasing and decreasing
subsequence.

O(n^2) time, O(n) storage.

Both sides must have an edge; an endpoint cannot be a mountain peak.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int removals(const std::vector<int>& a) {
    int n = static_cast<int>(a.size());
    std::vector<int> left(n, 1);
    std::vector<int> right(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                left[i] = std::max(left[i], left[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[i]) {
                right[i] = std::max(right[i], right[j] + 1);
            }
        }
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        if (left[i] > 1 && right[i] > 1) {
            best = std::max(best, left[i] + right[i] - 1);
        }
    }
    return best == 0 ? -1 : n - best;
}

int main() {
    assert(removals({2, 1, 1, 5, 6, 2, 3, 1}) == 3);
    assert(removals({1, 2, 3}) == -1);
    std::cout << "checks passed\n";
    return 0;
}
