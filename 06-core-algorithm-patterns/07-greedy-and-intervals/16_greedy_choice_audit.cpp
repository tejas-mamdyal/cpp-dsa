/*
 At most 8 nonempty half-open intervals for the exhaustive audit.

IDEA AND STATE: Compare earliest-start selection with proven earliest-finish and enumerate all
compatible subsets.

TRACE: [0,10),[1,2),[2,3),[3,4): start rule 1, finish rule 3.

Earliest-start chooses[0,10) and blocks everything;earliest-finish
chooses[1,2),[2,3),[3,4),matching the subset oracle.

Every subset is inspected and pairwise overlap checked independently; exchange
proof explains why finish ordering generalizes.

Greedy O(n log n); oracle O(2^n*n*n), tiny inputs only.

Passing convenient examples never establishes a greedy-choice property.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <optional>

struct Interval {
    int start;
    int end;
};

int schedule(std::vector<Interval> a) {
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
        return x.end < y.end;
    });
    int count = 0;
    std::optional<int> finish;
    for (const auto& x : a) {
        assert(x.start < x.end);
        if (!finish || x.start >= *finish) {
            ++count;
            finish = x.end;
        }
    }
    return count;
}

int byStart(std::vector<Interval> a) {
    std::sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
        return x.start < y.start;
    });
    int count = 0;
    std::optional<int> end;
    for (auto x : a) {
        if (!end || x.start >= *end) {
            ++count;
            end = x.end;
        }
    }
    return count;
}

int oracle(const std::vector<Interval>& a) {
    int best = 0;
    for (unsigned int mask = 0; mask < (1U << a.size()); ++mask) {
        bool ok = true;
        int count = 0;
        for (std::size_t i = 0; i < a.size(); ++i) {
            if ((mask & (1U << i)) == 0U) {
                continue;
            }
            ++count;
            for (std::size_t j = i + 1; j < a.size(); ++j) {
                if ((mask & (1U << j)) != 0U
                    && std::max(a[i].start, a[j].start) < std::min(a[i].end, a[j].end)) {
                    ok = false;
                }
            }
        }
        if (ok) {
            best = std::max(best, count);
        }
    }
    return best;
}

int main() {
    std::vector<Interval> pool{{0, 10}, {1, 2}, {2, 3}, {3, 4}, {0, 1}, {2, 5}};
    assert(byStart({{0, 10}, {1, 2}, {2, 3}, {3, 4}}) == 1);
    assert(schedule({{0, 10}, {1, 2}, {2, 3}, {3, 4}}) == 3);
    for (unsigned int mask = 0; mask < (1U << pool.size()); ++mask) {
        std::vector<Interval> a;
        for (std::size_t i = 0; i < pool.size(); ++i) {
            if ((mask & (1U << i)) != 0U) {
                a.push_back(pool[i]);
            }
        }
        assert(schedule(a) == oracle(a));
    }
    std::cout << "checks passed\n";
    return 0;
}
