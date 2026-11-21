/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

best[word] is the longest chain ending at the word.

a-ba-bda-bdca is a length 4 chain.

Deleting the inserted character enumerates every possible immediate predecessor,
all already processed.

O(W*L^2*log(W+1)) conservative time, O(total text) storage.

Equal-length anagrams cannot extend this insertion-only chain.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstddef>

int chain(std::vector<std::string> words) {
    std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        return a.size() < b.size();
    });
    std::map<std::string, int> best;
    int answer = 0;
    for (auto& word : words) {
        int length = 1;
        for (std::size_t i = 0; i < word.size(); ++i) {
            auto previous = word.substr(0, i) + word.substr(i + 1);
            auto found = best.find(previous);
            if (found != best.end()) {
                length = std::max(length, found->second + 1);
            }
        }
        best[word] = length;
        answer = std::max(answer, length);
    }
    return answer;
}

int main() {
    assert(chain({"a", "b", "ba", "bca", "bda", "bdca"}) == 4);
    assert(chain({}) == 0);
    std::cout << "checks passed\n";
    return 0;
}
