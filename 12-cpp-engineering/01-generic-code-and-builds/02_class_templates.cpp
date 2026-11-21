/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Box<T> owns a T; get returns a nonowning const reference.

Box<string> retains its string while the Box lives.

Construction stores a complete owned value; const access does not mutate it.

O(cost of moving T) construction, O(1) access.

A reference returned from a destroyed temporary box would dangle.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <utility>

template <typename T> class Box {
    T value;

public:
    explicit Box(T initial)
        : value(std::move(initial)) {
    }

    const T& get() const {
        return value;
    }
};

int main() {
    Box<int> i(7);
    Box<std::string> s("word");
    assert(i.get() == 7 && s.get() == "word");
    std::cout << "checks passed\n";
    return 0;
}
