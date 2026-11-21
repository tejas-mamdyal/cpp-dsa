/*
 Static array<=30; valid half-open queries with IDs 0..Q-1 each used once. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

The current half-open window stores value frequencies and its distinct
count; query IDs restore original output order after sorting.

Window[0,3) has values 1,2,1 and distinct 2; moving to[1,4) yields 2,1,3 and
distinct 3.

Each endpoint move adds/removes exactly one input occurrence and updates distinct
only at 0-to 1 or 1-to 0 frequency transitions.

O(n log n+Q log Q+(n+Q)*sqrt(n)) conventional bound with sqrt blocks; O(n+Q) storage.

Mo requires the full query batch and a reversible aggregate; it is not an online
query structure.
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
        if (frequency[x] == 0) {
            ++answer;
        }
        ++frequency[x];
    };
    auto remove = [&](int i) {
        int x = rank[i];
        --frequency[x];
        if (frequency[x] == 0) {
            --answer;
        }
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
        (mo({1, 2, 1, 3}, {{0, 3, 0}, {1, 4, 1}, {2, 2, 2}}) == std::vector<long long>{2, 3, 0}));
    assert(mo({}, {}).empty());
    std::cout << "checks passed\n";
    return 0;
}
