/*
 At most 30 elements/vertices, integer magnitudes<=1000; valid structural inputs. No
input required.

Matching outer pairs need no deletion; the first mismatch must lose one
endpoint.

abca becomes aba or aca by removing one middle endpoint.

Any successful single deletion at the first mismatch must remove one of those two
characters.

O(n) time, O(1) work.

Trying both choices is necessary; one greedy endpoint choice is not sufficient.
*/
#include <iostream>
#include <cassert>
#include <string>

bool palindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) {
            return false;
        }
    }
    return true;
}

bool almost(const std::string& s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return palindrome(s, left + 1, right) || palindrome(s, left, right - 1);
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    assert(almost("abca") && !almost("abc") && almost(""));
    std::cout << "checks passed\n";
    return 0;
}
