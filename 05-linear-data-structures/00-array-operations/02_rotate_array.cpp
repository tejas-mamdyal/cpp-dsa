/*
SIGNED RIGHT ROTATION WITH THREE REVERSALS PREREQUISITES: Phases1/2 C++ and STL, Phase3

order, not old filenames.

 n<=1000; signed k may be negative, meaning left rotation. IDEA AND STATE: Normalize
k modulo n, reverse all, reverse the first k and then the rest. TRACE: 1,2,3,4 right1
->4,1,2,3;right-1 ->2,3,4,1. CORRECTNESS: Reversing each block restores within-block order
after exchanging their positions. COST: O(n) time,O(1) auxiliary space. PITFALL: Handle empty
before modulo; normalize negative remainder. PRACTICE: Change the example, predict each state
update and add an empty/boundary case. No input unless explicitly stated. Assertions are the
teaching test harness and must remain enabled; success prints checks passed. These bounds
describe the helper, not a claim that a fixed-data demonstration has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

void rotateArray(std::vector<int>& a, int k) {
    if (a.empty()) {
        return;
    }
    int n = static_cast<int>(a.size());
    k %= n;
    if (k < 0) {
        k += n;
    }
    std::reverse(a.begin(), a.end());
    std::reverse(a.begin(), a.begin() + k);
    std::reverse(a.begin() + k, a.end());
}

int main() {
    for (int n = 0; n <= 8; ++n) {
        std::vector<int> original;
        for (int i = 0; i < n; ++i) {
            original.push_back(i);
        }
        for (int k = -12; k <= 12; ++k) {
            auto a = original;
            rotateArray(a, k);
            auto expected = original;
            if (n > 0) {
                int shift = ((k % n) + n) % n;
                for (int i = 0; i < n; ++i) {
                    expected[(i + shift) % n] = original[i];
                }
            }
            assert(a == expected);
        }
    }
    std::cout << "checks passed\n";
    return 0;
}
