/*
std::move enables move overload selection by casting an expression to an rvalue; the cast itself transfers nothing. The selected constructor or assignment performs any transfer. A moved-from standard object stays valid but its contents may be unspecified.
*/

#include <cassert>
#include <memory>
#include <utility>
#include <vector>

int main() {
    std::vector<int> original{1, 2, 3};
    auto copy = original; // Independent allocation and values.
    copy[0] = 99;
    assert(original[0] == 1);
    auto owner = std::make_unique<int>(42); // Automatically released at scope exit.
    int* observer = owner.get();            // Valid while the owned int remains alive.
    auto newOwner = std::move(owner);       // Exactly one owner remains.
    assert(!owner && *newOwner == 42 && *observer == 42);
    // No delete: the unique_ptr destructor performs it exactly once.
}
