/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Move assignment releases a previous allocation through unique_ptr and
transfers the incoming resource.

a 2 receives b 8; self-move is guarded and preserves 8.

At each completed operation every allocation has one owner or has been released.

O(1) time/storage.

Do not use the old destination pointer after replacement.
*/
#include <iostream>
#include <cassert>
#include <optional>
#include <utility>
#include <memory>

class Owner {
    std::unique_ptr<int> value;

public:
    explicit Owner(int x)
        : value(std::make_unique<int>(x)) {
    }

    Owner(const Owner& other)
        : value(other.value ? std::make_unique<int>(*other.value) : nullptr) {
    }

    Owner& operator=(const Owner& other) {
        if (this != &other) {
            Owner temporary(other);
            swap(temporary);
        }
        return *this;
    }

    Owner(Owner&& other) noexcept
        : value(std::move(other.value)) {
    }

    Owner& operator=(Owner&& other) noexcept {
        if (this != &other) {
            value = std::move(other.value);
        }
        return *this;
    }

    ~Owner() = default;

    void swap(Owner& other) noexcept {
        value.swap(other.value);
    }

    std::optional<int> get() const {
        if (!value) {
            return std::nullopt;
        }
        return *value;
    }

    void set(int x) {
        if (!value) {
            value = std::make_unique<int>(x);
        } else {
            *value = x;
        }
    }
};

int main() {
    Owner a(2);
    Owner b(8);
    a = std::move(b);
    assert(a.get() == 8 && !b.get());
    Owner* alias = &a;
    a = std::move(*alias);
    assert(a.get() == 8);
    std::cout << "checks passed\n";
    return 0;
}
