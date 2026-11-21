/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

answer=sum choose(freq[value],2); adding an occurrence creates freq old
equal partners, removing destroys the remaining freq partners.

Three 1 values contribute 3 pairs; two 1 values plus 2 contribute 1.

Each unordered equal index pair is introduced when its second endpoint enters and
removed when either endpoint leaves.

Same Mo endpoint-movement bound, O(1) aggregate updates and O(n+Q) storage.

Distinct-count transition formulas cannot be reused for a different frequency
aggregate.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cmath>

struct Query {
    int left;
    int right;
    int id;
};

std::vector<long long> mo(const std::vector<int>& input, std::vector<Query> queries) {
    auto values = input;
    std::sort(values.begin(), values.end());
    values.erase(std::unique(values.begin(), values.end()), values.end());
    std::vector<int> rank;
    for (int x : input) {
        rank.push_back(
            static_cast<int>(std::lower_bound(values.begin(), values.end(), x) - values.begin()));
    }
    int width = std::max(
        1,
        static_cast<int>(std::sqrt(static_cast<double>(std::max<std::size_t>(1, input.size())))));
    std::sort(queries.begin(), queries.end(), [width](const Query& a, const Query& b) {
        if (a.left / width != b.left / width) {
            return a.left / width < b.left / width;
        }
        return a.right < b.right;
    });
    std::vector<int> frequency(values.size(), 0);
    long long answer = 0;
    auto add = [&](int i) {
        int x = rank[i];
        answer += frequency[x];
        ++frequency[x];
    };
    auto remove = [&](int i) {
        int x = rank[i];
        --frequency[x];
        answer -= frequency[x];
    };
    int left = 0;
    int right = 0;
    std::vector<long long> out(queries.size(), 0);
    for (auto q : queries) {
        while (left > q.left) {
            --left;
            add(left);
        }
        while (right < q.right) {
            add(right);
            ++right;
        }
        while (left < q.left) {
            remove(left);
            ++left;
        }
        while (right > q.right) {
            --right;
            remove(right);
        }
        out[q.id] = answer;
    }
    return out;
}

int main() {
    assert(
        (mo({1, 1, 1, 2}, {{0, 3, 0}, {1, 4, 1}, {0, 4, 2}}) == std::vector<long long>{3, 1, 3}));
    std::cout << "checks passed\n";
    return 0;
}
