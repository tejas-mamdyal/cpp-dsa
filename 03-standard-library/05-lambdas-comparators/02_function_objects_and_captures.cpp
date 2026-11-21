/*
CALLABLE OBJECTS AND CAPTURES
Prerequisites: functions, classes/const methods, references, auto and basic lambdas.
Read 01_lambdas.cpp first; recursion is not needed for this lesson.

A callable can be used with function-call syntax. operator() defines that behavior
for a class. A lambda is also a callable object. [] captures nothing, [offset]
stores a copy of offset, and [&offset] observes the existing variable by reference.
The lambda's body executes on a CALL, not when the lambda object is created.

std::function<int(int)> (functional header) is a wrapper holding a callable that
accepts an int and returns an int. It lets later recursive examples declare a
named callable before assigning a capturing lambda. The wrapper does not make a
captured reference own its referent: never call after that referent's lifetime ends.

Trace: offset10 -> create both captures -> offset20. Copied capture applied to1
gives11, reference capture gives21. Multiplier{3} applied to4 gives12.
No input; assertions check the trace; output is captures passed.
All work/storage is bounded here: O(1). Exercise: change offset twice and predict
both answers. Then wrap the multiplier in std::function without changing its result.
*/
#include <cassert>
#include <functional>
#include <iostream>

struct Multiplier {
    int factor;

    int operator()(int value) const {
        return factor * value;
    }
};

int main() {
    Multiplier triple{3};
    assert(triple(4) == 12);
    int offset = 10;
    auto copied = [offset](int x) {
        return x + offset;
    };
    auto observed = [&offset](int x) {
        return x + offset;
    };
    offset = 20;
    assert(copied(1) == 11 && observed(1) == 21);
    std::function<int(int)> wrapped = observed;
    assert(wrapped(1) == 21);
    std::cout << "captures passed\n";
}
