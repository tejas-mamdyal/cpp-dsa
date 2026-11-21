/*
 Positive widths L, M; return maximum total of two disjoint windows or absence when
they cannot fit. Signed values allowed.

IDEA AND STATE: Prefix sums evaluate windows; scan both possible width orders while retaining
the best completed left sum.

TRACE: 0,6,5,2,2,5,1,9,4 with 1,2 ->20.

For width1 before width2,the best completed left value is combined with each right pair;the
reverse order covers the other arrangement.

For a fixed right start, all eligible left windows are summarized by their
maximum; both orders cover every legal arrangement.

O(n) time, O(n) prefix storage.

Initialize from real sums, not 0, when all values may be negative.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <optional>

std::vector<long long> prefix(const std::vector<int>& a) {
    std::vector<long long> p(a.size() + 1, 0);
    for (std::size_t i = 0; i < a.size(); ++i) {
        p[i + 1] = p[i] + a[i];
    }
    return p;
}

long long ordered(const std::vector<long long>& p, int first, int second) {
    long long bestLeft = p[first] - p[0];
    long long answer = std::numeric_limits<long long>::lowest();
    int n = static_cast<int>(p.size()) - 1;
    for (int start = first; start + second <= n; ++start) {
        bestLeft = std::max(bestLeft, p[start] - p[start - first]);
        answer = std::max(answer, bestLeft + p[start + second] - p[start]);
    }
    return answer;
}

std::optional<long long> twoWindows(const std::vector<int>& a, int l, int m) {
    if (l < 1 || m < 1 || l > static_cast<int>(a.size()) || m > static_cast<int>(a.size()) - l) {
        return std::nullopt;
    }
    auto p = prefix(a);
    return std::max(ordered(p, l, m), ordered(p, m, l));
}

int main() {
    assert(twoWindows({0, 6, 5, 2, 2, 5, 1, 9, 4}, 1, 2) == 20);
    assert(twoWindows({-1, -2, -3, -4}, 1, 1) == -3);
    assert(!twoWindows({1}, 1, 1));
    std::cout << "checks passed\n";
    return 0;
}
