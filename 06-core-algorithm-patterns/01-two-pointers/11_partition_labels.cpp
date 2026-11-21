/*
 Byte text; return maximum-count contiguous block lengths such that each character
belongs to only one block.

IDEA AND STATE: Precompute last positions and expand the current block end for each seen
character.

TRACE: ababcbacadefegdehijhklij ->9,7,8.

The first a requires reaching index8;bytes inside that span do not extend it further,so close
length9,then lengths7 and8.

A block cannot end before the last occurrence of any character it
contains; closing at the earliest allowed end leaves maximum room for more blocks.

O(n+256) time, O(256) working storage plus output.

Index byte tables using unsigned char; this does not segment Unicode characters.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

std::vector<int> partitionLabels(const std::string& text) {
    std::array<int, 256> last{};
    for (int i = 0; i < static_cast<int>(text.size()); ++i) {
        last[static_cast<unsigned char>(text[i])] = i;
    }
    std::vector<int> out;
    int start = 0;
    int end = 0;
    for (int i = 0; i < static_cast<int>(text.size()); ++i) {
        end = std::max(end, last[static_cast<unsigned char>(text[i])]);
        if (i == end) {
            out.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return out;
}

int main() {
    assert((partitionLabels("ababcbacadefegdehijhklij") == std::vector<int>{9, 7, 8}));
    assert(partitionLabels("").empty());
    assert((partitionLabels("aaaa") == std::vector<int>{4}));
    assert((partitionLabels("abc") == std::vector<int>{1, 1, 1}));
    std::cout << "checks passed\n";
    return 0;
}
