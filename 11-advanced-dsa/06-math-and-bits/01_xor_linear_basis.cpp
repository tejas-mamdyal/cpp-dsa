/*
 Unsigned integers in[0,65535], any subset including empty. Unless a different bound
is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No input is
required; keep assertions enabled. Success prints checks passed.

Each pivot has a unique highest bit; insertion cancels matching leading
bits.

3 xor 5=6, so inserting 6 adds no independent vector;8 adds a new pivot.

XOR cancellation preserves the generated span; descending greedy choices maximize
the first bit where alternatives differ.

O(16) insertion/query, O(16) storage.

A linear basis answers subset XOR questions, not contiguous-subarray XOR.
*/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <array>

class Basis {
    std::array<unsigned, 16> pivot{};

public:
    void insert(unsigned value) {
        assert(value < 65536);
        for (int b = 15; b >= 0; --b) {
            if ((value & (1U << b)) == 0) {
                continue;
            }
            if (pivot[b]) {
                value ^= pivot[b];
            } else {
                pivot[b] = value;
                return;
            }
        }
    }

    unsigned maximum() const {
        unsigned result = 0;
        for (int b = 15; b >= 0; --b) {
            result = std::max(result, result ^ pivot[b]);
        }
        return result;
    }
};

int main() {
    Basis b;
    b.insert(3);
    b.insert(5);
    b.insert(6);
    assert(b.maximum() == 6);
    b.insert(8);
    assert(b.maximum() == 14);
    assert(Basis().maximum() == 0);
    std::cout << "checks passed\n";
    return 0;
}
