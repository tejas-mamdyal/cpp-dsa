/*
 Equal-length lowercase words, length<=8; dictionary<=30 words. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

The queue orders words by number of substitutions; erasing marks
visitation on enqueue.

hit-hot-dot-dog-cog uses 4 changes.

All edges cost one, so the first discovered target has minimum distance.

O(W*L^2*26*log(W+1)) conservative string lookup work, O(W*L) storage.

This counts changes, not number of words in the route.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <utility>
#include <queue>
#include <set>
#include <cstddef>

int ladder(std::string start, const std::string& target, std::set<std::string> words) {
    if (start == target) {
        return 0;
    }
    if (!words.count(target)) {
        return -1;
    }
    std::queue<std::pair<std::string, int>> q;
    q.push({start, 0});
    words.erase(start);
    while (!q.empty()) {
        auto [word, d] = q.front();
        q.pop();
        for (std::size_t i = 0; i < word.size(); ++i) {
            auto next = word;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                next[i] = ch;
                auto found = words.find(next);
                if (found != words.end()) {
                    if (next == target) {
                        return d + 1;
                    }
                    q.push({next, d + 1});
                    words.erase(found);
                }
            }
        }
    }
    return -1;
}

int main() {
    assert(ladder("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) == 4);
    assert(ladder("a", "a", {}) == 0);
    assert(ladder("a", "z", {}) == -1);
    std::cout << "checks passed\n";
    return 0;
}
