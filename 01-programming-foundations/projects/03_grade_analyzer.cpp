/*
PROJECT 3 — STREAMING GRADE ANALYZER
Input: student count n in [1,1000], then n integer marks in [0,100]. Output:
minimum maximum mean (two decimals) pass-count, where passing means mark>=40.
Malformed, missing or out-of-range input -> stderr Invalid input and exit 1.
Example: 4 30 40 80 100 ->30 100 62.50 3.

Keep only necessary aggregates: after i marks, total/minimum/maximum/passes refer
to exactly those marks. Initialize min/max from the first actual mark, avoiding
imaginary candidates. No array is needed when the output needs only aggregates.
gradePassed is a predicate; main coordinates extraction and summary updates.
Use integer total for exact accumulation and convert before mean division.
O(n) time/O(1) auxiliary space. Reject zero students because the mean is undefined.
Follow-ups: count A/B/C/D/F categories; add separate subject totals without arrays.
Later in Phase 2, retain records in a vector when individual lookup is required.
*/
#include <iomanip>
#include <iostream>

bool gradePassed(int mark) {
    return mark >= 40;
}

int main() {
    int n = 0;
    if (!(std::cin >> n) || n < 1 || n > 1000) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    int minimum = 0;
    int maximum = 0;
    int passes = 0;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int mark = 0;
        if (!(std::cin >> mark) || mark < 0 || mark > 100) {
            std::cerr << "Invalid input\n";
            return 1;
        }
        if (i == 0 || mark < minimum) {
            minimum = mark;
        }
        if (i == 0 || mark > maximum) {
            maximum = mark;
        }
        total += mark;
        if (gradePassed(mark)) {
            ++passes;
        }
    }
    double mean = static_cast<double>(total) / n;
    std::cout << minimum << ' ' << maximum << ' ' << std::fixed << std::setprecision(2) << mean
              << ' ' << passes << '\n';
}
