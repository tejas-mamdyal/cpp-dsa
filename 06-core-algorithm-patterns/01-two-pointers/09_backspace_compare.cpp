/*
 The# character deletes one preceding surviving character; deleting from empty is
harmless.

IDEA AND STATE: Scan backward with a skip count to find each next surviving character.

TRACE: ab#c and ad#c both become ac.

From the right,compare c with c;each # hides its preceding letter,leaving a matched with a.

Each deletion consumes one earlier ordinary character; surviving reverse sequences
determine equality.

O(n+m) time, O(1) space.

A skip count can exceed the number of earlier letters and must simply reach the
beginning.
*/
#include <iostream>
#include <cassert>
#include <string>

int visible(const std::string& text, int index) {
    int skip = 0;
    while (index >= 0) {
        if (text[index] == '#') {
            ++skip;
            --index;
        } else if (skip > 0) {
            --skip;
            --index;
        } else {
            break;
        }
    }
    return index;
}

bool sameEdited(const std::string& a, const std::string& b) {
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    while (i >= 0 || j >= 0) {
        i = visible(a, i);
        j = visible(b, j);
        if (i < 0 || j < 0) {
            return i == j;
        }
        if (a[i] != b[j]) {
            return false;
        }
        --i;
        --j;
    }
    return true;
}

int main() {
    assert(sameEdited("ab#c", "ad#c"));
    assert(sameEdited("a##c", "#a#c"));
    assert(sameEdited("###", ""));
    assert(!sameEdited("a#c", "b"));
    std::cout << "checks passed\n";
    return 0;
}
