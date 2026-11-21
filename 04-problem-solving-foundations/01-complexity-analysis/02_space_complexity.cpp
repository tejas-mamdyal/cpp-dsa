/*
SEPARATE INPUT OUTPUT AND WORKING STORAGE
PREREQUISITES
Phase1 loops/functions/validation and Phase2 vector/reference/library interfaces.
Read this unit's NOTES.md before the programs. No recursion is used here.

PROBLEM AND CONTRACT
No input. Copy {1,2,3}, double the original in place, and print both sequences. doubleValues accepts ints in [-1000000,1000000].

IDEA
Copying owns a separate vector. In-place mutation uses a loop index and no second sequence. Count the input, returned output and auxiliary working memory explicitly.

TRACE
copy remains1,2,3 while input becomes2,4,6. Empty input remains empty.

WHY IT WORKS
Each copied element is independent; mutating the original does not change the copied allocation. Each in-place update touches one existing element.

Copy Theta(n) time and Theta(n) returned storage, O(1) working state beyond result. In-place doubling Theta(n) time and O(1) auxiliary space. Entire main retains O(n) sequences.

PITFALL AND PRACTICE
If a convention includes returned output in auxiliary space, call copying O(n) auxiliary and state that convention. Do not say the whole program uses O(1) just because one helper does.
Change the traced size, predict the result, and test the smallest valid size.
*/
#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createCopy(const std::vector<int>& values) {
    std::vector<int> result;
    result.reserve(values.size());
    for (int value : values) {
        result.push_back(value);
    }
    return result;
}

void doubleValues(std::vector<int>& values) {
    for (int& value : values) {
        value *= 2;
    }
}

int main() {
    std::vector<int> values = {1, 2, 3};
    std::vector<int> copy = createCopy(values);
    doubleValues(values);
    assert((copy == std::vector<int>{1, 2, 3}));
    assert((values == std::vector<int>{2, 4, 6}));
    std::vector<int> empty;
    doubleValues(empty);
    assert(createCopy(empty).empty());
    for (std::size_t i = 0; i < copy.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << copy[i];
    }
    std::cout << '\n';
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << values[i];
    }
    std::cout << '\n';
    return 0;
}
