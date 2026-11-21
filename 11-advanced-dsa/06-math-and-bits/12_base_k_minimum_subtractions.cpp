/*
 0<=n<=1000000;1<=k<=1000000; includes a batch-processing example. Unless a different
bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated domain. No
input is required; keep assertions enabled. Success prints checks passed.

Each operation subtracts one k^j, j>=0; the optimal count for k>1 is the
sum of base-k digits.

10=1*9+0*3+1*1 uses 2 operations for k=3.

Any k copies of one power can be replaced by one next power, reducing the count;
the normalized coefficients are exactly the unique base-k digits.

O(log_k(n+1)) time, O(1) helper storage for k>1; constant time for k=1.

For k=1 division would never reduce n; handle it separately.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

int minOperations(int n, int k) {
    assert(n >= 0 && k >= 1);
    if (k == 1) {
        return n;
    }
    int count = 0;
    while (n) {
        count += n % k;
        n /= k;
    }
    return count;
}

int main() {
    assert(minOperations(10, 3) == 2 && minOperations(10, 1) == 10 && minOperations(0, 7) == 0
           && minOperations(27, 3) == 1);
    std::vector<std::pair<int, int>> batch{{10, 3}, {10, 1}, {0, 7}};
    std::vector<int> results;
    for (auto [n, k] : batch) {
        results.push_back(minOperations(n, k));
    }
    assert((results == std::vector<int>{2, 10, 0}));
    // Optional original batch CLI: t,then t pairs n k. Validate all before printing.
    if (std::cin.peek() != std::char_traits<char>::eof()) {
        int count;
        if (!(std::cin >> count) || count < 0 || count > 1000) {
            std::cerr << "invalid input\n";
            return 1;
        }
        std::vector<int> answers;
        for (int i = 0; i < count; ++i) {
            int n;
            int k;
            if (!(std::cin >> n >> k) || n < 0 || k < 1) {
                std::cerr << "invalid input\n";
                return 1;
            }
            answers.push_back(minOperations(n, k));
        }
        char extra;
        if (std::cin >> extra) {
            std::cerr << "invalid input\n";
            return 1;
        }
        for (int answer : answers) {
            std::cout << answer << '\n';
        }
        return 0;
    }
    std::cout << "checks passed\n";
    return 0;
}
