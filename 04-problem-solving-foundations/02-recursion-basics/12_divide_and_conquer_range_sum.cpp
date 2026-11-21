/*
SPLIT A RANGE INTO TWO DISJOINT SMALLER PROBLEMS
PREREQUISITES
Phase1 functions/loops/validation, Phase2 references/strings/vectors, and Phase3
complexity. Follow this unit's README order; the first factorial lesson introduces
recursion and the later lessons build on it. No capturing lambda is required.

CONTRACT
No input. Sum every prefix of a32-element bounded vector with balanced range recursion and compare with an independent linear loop. Include empty and singleton ranges. Print checked33 ranges.

IDEA AND STATE
For [left,right), return0 if empty and the element if singleton. Otherwise split at left+(right-left)/2 and add the sums of the two halves. Each recursive call has its own interval.

TRACE
[0,4) ->[0,2)+[2,4) ->four singleton leaves. Total calls7, not4*log2(4).

WHY IT WORKS AND TERMINATES
The two halves partition the original range without overlap or omission. Each nonbase half is shorter; their correct sums add to the complete sum.

Theta(n+1) time: a nonempty range has n leaves and n-1 internal calls. O(1+log(n+1)) maximum stack depth for balanced splits. The vector is borrowed; no slices are copied.

PITFALL AND PRACTICE
Two recursive calls do not automatically mean exponential time: their input sizes shrink. This prepares divide-and-conquer sorting, but sum by a simple loop is still easier for an isolated sum.
Predict a new small trace and test a boundary before changing the contract.
*/
#include <iostream>
#include <cassert>
#include <vector>

long long rangeSum(const std::vector<int>& values, std::size_t left, std::size_t right) {
    if (left == right) {
        return 0;
    }
    if (right - left == 1) {
        return values[left];
    }
    std::size_t middle = left + (right - left) / 2;
    long long first = rangeSum(values, left, middle);
    long long second = rangeSum(values, middle, right);
    return first + second;
}

int main() {
    std::vector<int> values;
    for (int i = 0; i < 32; ++i) {
        values.push_back(i - 16);
    }
    long long expected = 0;
    int checked = 0;
    for (std::size_t length = 0; length <= values.size(); ++length) {
        assert(rangeSum(values, 0, length) == expected);
        ++checked;
        if (length < values.size()) {
            expected += values[length];
        }
    }
    assert(rangeSum(values, 7, 7) == 0);
    assert(rangeSum(values, 7, 8) == values[7]);
    assert(checked == 33);
    std::cout << "checked " << checked << " ranges\n";
    return 0;
}
