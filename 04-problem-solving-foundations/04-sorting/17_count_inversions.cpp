/*
COUNT INVERSIONS WHILE MERGING PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 Count index pairs i<j with a[i]>a[j], sorting a as a side effect. IDEA AND STATE:
When a right value precedes a left value, every remaining left value forms an inversion with
it. TRACE: 2,4,1,3,5 has3 inversions. CORRECTNESS: Both halves count their internal
inversions; the merge counts each cross-half inversion exactly once. COST: O(n log(n+1))
time,O(n) buffer plus O(log(n+1)) stack; long long count. PITFALL: Equal values are not
inversions. n<=1000 keeps index conversions safe. PRACTICE: Change the example, predict each
state update and add an empty/boundary case. No input unless explicitly stated. Assertions are
the teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long countRange(std::vector<int>& a, std::vector<int>& out, int l, int r) {
    if (r - l < 2) {
        return 0;
    }
    int m = l + (r - l) / 2;
    long long count = countRange(a, out, l, m) + countRange(a, out, m, r);
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            out[k++] = a[i++];
        } else {
            count += m - i;
            out[k++] = a[j++];
        }
    }
    while (i < m) {
        out[k++] = a[i++];
    }
    while (j < r) {
        out[k++] = a[j++];
    }
    for (int p = l; p < r; ++p) {
        a[p] = out[p];
    }
    return count;
}

long long inversions(std::vector<int>& a) {
    std::vector<int> out(a.size());
    return countRange(a, out, 0, static_cast<int>(a.size()));
}

int main() {
    for (int n = 0; n <= 5; ++n) {
        int total = 1;
        for (int i = 0; i < n; ++i) {
            total *= 3;
        }
        for (int code = 0; code < total; ++code) {
            int x = code;
            std::vector<int> a(static_cast<std::size_t>(n));
            for (int& value : a) {
                value = x % 3;
                x /= 3;
            }
            long long expected = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (a[i] > a[j]) {
                        ++expected;
                    }
                }
            }
            assert(inversions(a) == expected);
            assert(std::is_sorted(a.begin(), a.end()));
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
