/*
OVERLOAD ADDITION AND EQUALITY FOR A VALUE TYPE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Define + and == for small 2D integer points. Each coordinate is within [-1000,1000].
Trace: (1,2)+(3,4)=(4,6); inputs are not changed.
Why it works: Componentwise addition returns a new Point without mutating either operand.
Cost: O(1) time and space.
Common mistake: Overloading changes meaning for class operands, not operator precedence, arity or evaluation rules; do not invent surprising meanings.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Point {
    int x;
    int y;

    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    Point a{1, 2};
    Point b{3, 4};
    Point result = a + b;
    assert((result == Point{4, 6}));
    assert((a == Point{1, 2}));
    assert(!(a == b));
    std::cout << "checks passed\n";
}
