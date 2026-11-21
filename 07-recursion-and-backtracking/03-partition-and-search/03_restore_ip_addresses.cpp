/*
 Digits only, length<=12; return dotted IPv 4 strings with four segments 0..255, no
leading zeros except 0. Unless narrowed, at most 100 nodes/elements with values in
[-1000,1000]. Recursive examples assume valid acyclic owned structures; exponential searches
use the smaller bounds stated here. No input; keep assertions enabled. Success prints checks
passed.

start and pieces determine remaining work; reject when remaining characters
cannot fill the remaining 1..3-digit segments.

25525511135 ->255.255.11.135 and 255.255.111.35.

Every valid address has exactly four legal pieces; trying lengths 1..3 covers its
unique cut positions.

O(3^4*12) bounded time; O(12) work plus output.

A segment 00 is invalid even though its numeric value is 0.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstddef>

void visit(const std::string& s,
           std::size_t start,
           std::vector<std::string>& path,
           std::vector<std::string>& out) {
    std::size_t need = 4 - path.size();
    std::size_t left = s.size() - start;
    if (left < need || left > 3 * need) {
        return;
    }
    if (need == 0) {
        std::string address = path[0];
        for (std::size_t i = 1; i < 4; ++i) {
            address += '.';
            address += path[i];
        }
        out.push_back(address);
        return;
    }
    int value = 0;
    for (std::size_t end = start; end < s.size() && end < start + 3; ++end) {
        if (end > start && s[start] == '0') {
            break;
        }
        value = value * 10 + s[end] - '0';
        if (value > 255) {
            break;
        }
        path.push_back(s.substr(
            start, end - start + 1)); // Choose this route element before exploring its completions.
        visit(s, end + 1, path, out);
        path.pop_back(); // Undo so the next sibling sees the same entry prefix.
    }
}

std::vector<std::string> addresses(const std::string& s) {
    std::vector<std::string> path;
    std::vector<std::string> out;
    visit(s, 0, path, out);
    return out;
}

int main() {
    assert(
        (addresses("25525511135") == std::vector<std::string>{"255.255.11.135", "255.255.111.35"}));
    assert((addresses("0000") == std::vector<std::string>{"0.0.0.0"}));
    assert(addresses("123").empty());
    std::cout << "checks passed\n";
    return 0;
}
