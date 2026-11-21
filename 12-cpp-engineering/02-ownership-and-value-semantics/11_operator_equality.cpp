/*
 Small deterministic in-memory examples; keep assertions enabled. No input or
external services.

Equality compares all identity-relevant value fields.

Scores 3,2 and 3,1 differ despite equal correct counts.

Field equality is reflexive, symmetric and transitive, so the composite relation
is too.

O(1) time/storage.

Equality and ordering used in containers should describe compatible value semantics.
*/
#include <iostream>
#include <cassert>

struct Score {
    int correct;
    int penalty;

    bool operator==(const Score& b) const {
        return correct == b.correct && penalty == b.penalty;
    }

    bool operator!=(const Score& b) const {
        return !(*this == b);
    }
};

int main() {
    Score a{3, 2};
    Score b{3, 2};
    Score d{3, 1};
    assert(a == b && a != d && !(a != b));
    std::cout << "checks passed\n";
    return 0;
}
