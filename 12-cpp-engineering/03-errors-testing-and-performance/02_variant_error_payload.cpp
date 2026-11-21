/*
 Operands magnitude<=1000000; integer division truncates toward zero. Unless a
different bound is stated: n<=30, integer magnitudes<=1000000, inputs satisfy the stated
domain.

variant stores exactly one alternative, which is inspected before access.

12/0 returns a Failure while 12/3 returns int 4.

Validation prevents division by zero and preserves a diagnostic.

O(1) successful work, diagnostic string storage.

std:: get for the inactive alternative throws; check the result category first.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <tuple>
#include <variant>

struct Failure {
    std::string message;
};

using Result = std::variant<int, Failure>;

Result divide(int a, int b) {
    if (b == 0) {
        return Failure{"zero divisor"};
    }
    return a / b;
}

int main() {
    auto good = divide(12, 3);
    auto bad = divide(12, 0);
    assert(std::get<int>(good) == 4);
    assert(std::get<Failure>(bad).message == "zero divisor");
    std::cout << "checks passed\n";
    return 0;
}
