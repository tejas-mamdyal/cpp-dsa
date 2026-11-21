
#include <cassert>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Square : public Shape {
    double side;

public:
    explicit Square(double s)
        : side(s) {
    } // Caller supplies a nonnegative side.

    double area() const override {
        return side * side;
    }
};

int main() {
    Square square(3);
    const Shape& shape = square; // Observe the derived object through its base interface.
    assert(shape.area() == 9);
}
