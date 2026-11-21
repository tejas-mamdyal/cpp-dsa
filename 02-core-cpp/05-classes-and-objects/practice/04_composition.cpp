/*
COMPOSITION MODELS A HAS-A RELATIONSHIP
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A Rectangle contains two Side values; construct members in declaration order.
Trace: width3,height4 ->area12.
Why it works: The rectangle owns both sides and their lifetimes follow its own.
Cost: O(1) time and space.
Common mistake: The input precondition is nonnegative sides <=1000; composition is not inheritance.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Side {
    int length;
};

class Rectangle {
    Side width;
    Side height;

public:
    Rectangle(int w, int h)
        : width{w},
          height{h} {
    }

    int area() const {
        return width.length * height.length;
    }
};

int main() {
    Rectangle rectangle(3, 4);
    assert(rectangle.area() == 12);
    Rectangle zero(0, 4);
    assert(zero.area() == 0);
    std::cout << "checks passed\n";
}
