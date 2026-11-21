/*
 At most 30 elements/vertices; integer magnitudes<=1000 unless narrowed;
indices/ranges satisfy the stated domain.

Each center radius counts all smaller palindromes with the same center;
track longest start/length while summing radii.

abba contributes four singletons, bb, and abba, total 6.

Every nonempty palindrome has one unique odd character center or even gap center
and one radius size.

O(n) time/storage plus returned longest substring.

Counting distinct palindrome values is a different problem from counting positional
occurrences.
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cstddef>

std::pair<std::vector<int>, std::vector<int>> radii(const std::string& text) {
    int length = static_cast<int>(text.size());
    std::vector<int> oddRadius(length);
    std::vector<int> evenRadius(length);

    int oddLeft = 0;
    int oddRight = -1;
    for (int center = 0; center < length; ++center) {
        int radius = 1; // Every character is an odd palindrome of length one.
        if (center <= oddRight) {
            int mirroredCenter = oddLeft + oddRight - center;
            int knownInsideWindow = oddRight - center + 1;
            radius = std::min(oddRadius[mirroredCenter], knownInsideWindow);
        }
        while (center - radius >= 0 && center + radius < length
               && text[center - radius] == text[center + radius]) {
            ++radius;
        }
        oddRadius[center] = radius;
        int rightEdge = center + radius - 1;
        if (rightEdge > oddRight) {
            oddLeft = center - radius + 1;
            oddRight = rightEdge;
        }
    }

    int evenLeft = 0;
    int evenRight = -1;
    for (int center = 0; center < length; ++center) {
        int radius = 0; // An even palindrome starts at the gap before center.
        if (center <= evenRight) {
            int mirroredCenter = evenLeft + evenRight - center + 1;
            int knownInsideWindow = evenRight - center + 1;
            radius = std::min(evenRadius[mirroredCenter], knownInsideWindow);
        }
        while (center - radius - 1 >= 0 && center + radius < length
               && text[center - radius - 1] == text[center + radius]) {
            ++radius;
        }
        evenRadius[center] = radius;
        int rightEdge = center + radius - 1;
        if (rightEdge > evenRight) {
            evenLeft = center - radius;
            evenRight = rightEdge;
        }
    }
    return {oddRadius, evenRadius};
}

std::pair<long long, std::string> palindromes(const std::string& s) {
    auto [odd, even] = radii(s);
    long long count = 0;
    int start = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        count += odd[i] + even[i];
        int oddLength = 2 * odd[i] - 1;
        if (oddLength > best) {
            best = oddLength;
            start = i - odd[i] + 1;
        }
        int evenLength = 2 * even[i];
        if (evenLength > best) {
            best = evenLength;
            start = i - even[i];
        }
    }
    return {count, s.substr(static_cast<std::size_t>(start), static_cast<std::size_t>(best))};
}

int main() {
    assert((palindromes("abba") == std::pair<long long, std::string>{6, "abba"}));
    assert(palindromes("aaaa").first == 10);
    assert(palindromes("").second.empty());
    std::cout << "checks passed\n";
    return 0;
}
