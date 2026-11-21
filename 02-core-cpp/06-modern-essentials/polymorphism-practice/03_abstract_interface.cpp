/*
PURE VIRTUAL FUNCTIONS DEFINE A CONTRACT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: An abstract Shape cannot be instantiated; concrete implementations supply area.
Trace: rectangle3x4 and square5 produce12 and25.
Why it works: measure depends only on the interface, so each concrete shape supplies its own computation.
Cost: O(1) time and space.
Common mistake: The example assumes dimensions0..1000. A pure virtual destructor, if declared, still needs a definition.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Shape {
    virtual ~Shape() = default;
    virtual int area() const = 0;
};

struct Rectangle : public Shape {
    int width;
    int height;

    Rectangle(int w, int h)
        : width(w),
          height(h) {
    }

    int area() const override {
        return width * height;
    }
};

struct Square : public Shape {
    int side;

    explicit Square(int value)
        : side(value) {
    }

    int area() const override {
        return side * side;
    }
};

int measure(const Shape& shape) {
    return shape.area();
}

int main() {
    Rectangle rectangle(3, 4);
    Square square(5);
    assert(measure(rectangle) == 12);
    assert(measure(square) == 25);
    std::cout << "checks passed\n";
}
