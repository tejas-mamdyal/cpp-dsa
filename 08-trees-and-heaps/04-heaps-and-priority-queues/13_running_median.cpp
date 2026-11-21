/*
 At most 1000 bounded integers; duplicates allowed; empty operations return explicit
absence. Unless narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive
examples assume valid acyclic owned structures; exponential searches use the smaller bounds
stated here. No input; keep assertions enabled. Success prints checks passed.

After each insertion, lower has equal size to upper or one extra; all lower
values<=upper values.

Input 5,15,1,3 gives medians 5,10,5,4.

Insert by the partition boundary, then move one extreme if sizes differ too
much; the middle values remain heap extremes.

O(log(n+1)) insertion, O(1) median, O(n) storage.

Convert before averaging to avoid int overflow; empty median is absent.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <optional>
#include <queue>
#include <functional>

class Medians {
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;

public:
    void add(int x) {
        if (lower.empty() || x <= lower.top()) {
            lower.push(x);
        } else {
            upper.push(x);
        }
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    std::optional<double> median() const {
        if (lower.empty()) {
            return std::nullopt;
        }
        if (lower.size() > upper.size()) {
            return lower.top();
        }
        return (static_cast<double>(lower.top()) + static_cast<double>(upper.top())) / 2.0;
    }
};

int main() {
    Medians m;
    assert(!m.median());
    m.add(5);
    assert(m.median() == 5.0);
    m.add(15);
    assert(m.median() == 10.0);
    m.add(1);
    assert(m.median() == 5.0);
    m.add(3);
    assert(m.median() == 4.0);
    std::cout << "checks passed\n";
    return 0;
}
