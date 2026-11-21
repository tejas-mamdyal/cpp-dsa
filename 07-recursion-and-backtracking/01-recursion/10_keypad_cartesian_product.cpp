/*
 At most8 digits. Digits2..9 map to standard phone letters;other bytes return
absence. Empty input returns one empty combination. No input is required. Keep assertions
enabled; a successful run prints checks passed. Tiny bounds are intentional because output
grows exponentially or factorially.

At level i choose one letter from the ith digit mapping. This is a
Cartesian product:every choice from one list combines with every choice from each later list.
No lambda or generic framework is required.

23 chooses a with d,e,f,then b with d,e,f,then c with d,e,f,producing nine strings
from ad through cf.

Every result chooses exactly one legal letter at each level. Distinct branch
letters make routes disjoint and cover the whole product.

O((n+1)*4^n) worst-case time and output;O(n) auxiliary frames/path plus constant mapping
storage.

Never index the mapping before validating digits. This unit intentionally defines the
empty product as one empty string.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <array>
#include <optional>

void visit(const std::string& digits,
           std::size_t i,
           const std::array<std::string, 10>& letters,
           std::string& path,
           std::vector<std::string>& out) {
    if (i == digits.size()) {
        out.push_back(path);
        return;
    }
    int digit = digits[i] - '0'; // The wrapper already validated every byte.
    for (char letter : letters[digit]) {
        path.push_back(letter);
        visit(digits, i + 1, letters, path, out);
        path.pop_back();
    }
}

std::optional<std::vector<std::string>> keypad(const std::string& digits) {
    assert(digits.size() <= 8);
    for (char ch : digits) {
        if (ch < '2' || ch > '9') {
            return std::nullopt;
        }
    }
    const std::array<std::string, 10> letters{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::string path;
    std::vector<std::string> out;
    visit(digits, 0, letters, path, out);
    return out;
}

int main() {
    auto out = keypad("23");
    assert(out && out->size() == 9 && out->front() == "ad" && out->back() == "cf");
    assert(keypad("79")->size() == 16);
    assert(!keypad("20"));
    auto empty = keypad("");
    assert((empty == std::optional<std::vector<std::string>>{{""}}));
    std::cout << "checks passed\n";
    return 0;
}
