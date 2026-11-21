/*
COMPARE PARTITION SORTING WITH BOUNDED-VALUE COUNTING PREREQUISITES: Phases1/2 C++ and STL,

README order, not old filenames.

 Small ints[-10,10];compare two different sorting mechanisms. IDEA AND STATE: Quick
sort partitions around a last pivot; counting reconstructs values by their multiplicities.
TRACE: 3,-1,3 ->counts{-1:1,3:2} ->-1,3,3. CORRECTNESS: Partition places each chosen pivot
correctly; counting emits exactly each input multiplicity in key order. COST: Quick sort
O(n^2) worst/O(n log n) average under suitable inputs, O(n) worst stack. Counting O(n+21)
time,O(21) counts. PITFALL: Last-element pivots degrade on sorted/equal input; counting
assumes the stated range and does not establish record stability. PRACTICE: Change the
example, predict each state update and add an empty/boundary case. No input unless explicitly
stated. Assertions are the teaching test harness and must remain enabled; success prints
checks passed. These bounds describe the helper, not a claim that a fixed-data demonstration
has growing runtime input.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& a, int left, int right) {
    int pivot = a[right];
    int write = left;
    for (int i = left; i < right; ++i) {
        if (a[i] < pivot) {
            std::swap(a[i], a[write]);
            ++write;
        }
    }
    std::swap(a[write], a[right]);
    return write;
}

void quick(std::vector<int>& a, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(a, left, right);
    quick(a, left, pivot - 1);
    quick(a, pivot + 1, right);
}

void counted(std::vector<int>& a) {
    int count[21] = {};
    for (int value : a) {
        ++count[value + 10];
    }
    std::size_t write = 0;
    for (int i = 0; i < 21; ++i) {
        while (count[i] > 0) {
            a[write++] = i - 10;
            --count[i];
        }
    }
}

int main() {
    for (std::vector<int> a : std::vector<std::vector<int>>{{}, {3, -1, 3}, {1, 2, 3}, {2, 2, 2}}) {
        auto expected = a;
        std::sort(expected.begin(), expected.end());
        auto copy = a;
        quick(a, 0, static_cast<int>(a.size()) - 1);
        counted(copy);
        assert(a == expected && copy == expected);
    }
    std::cout << "checks passed\n";
    return 0;
}
