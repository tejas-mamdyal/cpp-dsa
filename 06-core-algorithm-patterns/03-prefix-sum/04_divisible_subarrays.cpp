/*
 Positive divisor k<=1000; values may be signed.

IDEA AND STATE: Count previous prefix remainders after normalizing into[0, k).

TRACE: 4,5,0,-2,-3,1 with k 5 ->7.

Normalized remainder4 repeats after5 and0;equal remainder pairs accumulate the seven divisible
ranges.

Two prefixes differ by a multiple of k exactly when their normalized remainders
match.

O(n+k) time, O(k) storage.

C++ signed remainder can be negative; normalization is part of correctness.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

long long divisible(const std::vector<int>& a, int k) {
    assert(k > 0 && k <= 1000);
    std::vector<long long> frequency(static_cast<std::size_t>(k), 0);
    frequency[0] = 1;
    long long sum = 0;
    long long answer = 0;
    for (int value : a) {
        sum += value;
        int remainder = static_cast<int>((sum % k + k) % k);
        answer += frequency[remainder];
        ++frequency[remainder];
    }
    return answer;
}

int main() {
    assert(divisible({4, 5, 0, -2, -3, 1}, 5) == 7);
    assert(divisible({-1, 1}, 2) == 1);
    assert(divisible({}, 1) == 0);
    assert(divisible({1, 2, 3}, 1) == 6);
    std::cout << "checks passed\n";
    return 0;
}
