/*
 Choose k digits from 1..9, k 1..9; return strictly increasing-digit numbers. Unless
narrowed, at most 100 nodes/elements with values in [-1000,1000]. Recursive examples assume
valid acyclic owned structures; exponential searches use the smaller bounds stated here. No
input; keep assertions enabled. Success prints checks passed.

Carry a numeric prefix rather than a vector; append via value*10+digit.

k 2 begins 12,13,...19,23; there are 36 outputs.

Each number has one increasing digit route and cannot have leading zero under the
contract.

O(9*2^9) upper-bound time; O(9) frames plus output.

The nine-digit maximum 123456789 fits int; larger digit alphabets would need a new
representation.
*/
#include <iostream>
#include <cassert>
#include <vector>

void visit(int next, int need, int prefix, std::vector<int>& out) {
    if (need == 0) {
        out.push_back(prefix);
        return;
    }
    for (int d = next; d <= 10 - need; ++d) {
        visit(d + 1, need - 1, prefix * 10 + d, out);
    }
}

std::vector<int> numbers(int k) {
    assert(k >= 1 && k <= 9);
    std::vector<int> out;
    visit(1, k, 0, out);
    return out;
}

int main() {
    assert(numbers(2).size() == 36);
    assert(numbers(2).front() == 12);
    assert(numbers(2).back() == 89);
    assert(numbers(9) == std::vector<int>{123456789});
    std::cout << "checks passed\n";
    return 0;
}
