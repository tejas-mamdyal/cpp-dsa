/*
Prerequisite: variables, conditionals, loops.
Integers represent exact whole numbers within a finite range; doubles are
approximate and cannot represent every decimal exactly. Integer overflow on
signed types is undefined behavior, not a reliable wraparound rule.
7/2 is 3 because both operands are integers; convert BEFORE division for 3.5.
cin >> word stops at whitespace; getline reads the remainder of a line.
After >>, a newline remains: discard it before a following getline.
Debugging method: reproduce -> predict -> trace variables -> find the first
incorrect state -> fix the cause -> rerun normal and boundary cases.
Assertions check programmer assumptions; validate external input explicitly.
Exercise: trace -7/2 and -7%2; explain why assigning 7/2 to double still gives 3.
Time O(L), space O(L), where L is the length of the input name.
*/
#include <cassert>
#include <iostream>
#include <limits>
#include <string>

int main() {
    assert(7 / 2 == 3);
    assert(7 % 2 == 1); // Remainder: 7 = (7/2)*2 + 7%2.
    assert(static_cast<double>(7) / 2 == 3.5);
    // Multiply in the wider type: widening only after an overflowing int product is too late.
    long long square = 1LL * 100000 * 100000;
    assert(square == 10000000000LL);
    int age = 0;
    std::string name;
    std::cout << "Enter age, then your full name on the next line:\n";
    if (!(std::cin >> age) || age < 0 || age > 120) {
        std::cerr << "Expected age in 0..120.\n";
        return 1;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!std::getline(std::cin, name) || name.empty()) {
        std::cerr << "Expected a nonempty full name.\n";
        return 1;
    }
    std::cout << name << " is " << age << " years old.\n";
}
