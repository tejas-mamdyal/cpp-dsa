/*
Count each distinct input value, then sort (value,frequency) records by ascending
frequency and, on ties, ascending value. Example 2,2,1 -> [{1:1},{2:2}].
A map provides deterministic key ordering; a vector permits sorting by a new key.
Comparator uses strict <, never <=, so equal records do not compare before themselves.
O(L+n log u+u log u) time and O(L+u) storage; u distinct values, n parsed values.
Count directly into the map rather than retaining a redundant vector of inputs.
The short comma parser is here in the file so the example compiles independently.
Exercise: print the original values in this order, repeating each by its frequency.
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::string line;
    if (!std::getline(std::cin, line) || line.empty() || line.back() == ',') {
        std::cerr << "Invalid comma-separated integer list.\n";
        return 1;
    }
    std::istringstream fields(line);
    std::map<int, int> frequency;
    std::string field;
    while (std::getline(fields, field, ',')) {
        std::istringstream number(field);
        int value = 0;
        char extra = ' ';
        // A successful integer followed by another character is not a whole field.
        if (!(number >> value) || (number >> extra)) {
            std::cerr << "Invalid comma-separated integer list.\n";
            return 1;
        }
        ++frequency[value];
    }

    std::vector<std::pair<int, int>> records(frequency.begin(), frequency.end());
    std::sort(records.begin(), records.end(), [](auto first, auto second) {
        if (first.second != second.second) {
            return first.second < second.second;
        }
        return first.first < second.first;
    });
    std::cout << '[';
    for (std::size_t i = 0; i < records.size(); ++i) {
        if (i > 0) {
            std::cout << ',';
        }
        std::cout << '{' << records[i].first << ':' << records[i].second << '}';
    }
    std::cout << "]\n";
}
