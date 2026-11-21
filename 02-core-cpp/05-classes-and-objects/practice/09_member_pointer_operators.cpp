/*
POINTERS TO MEMBERS USE DOT-STAR AND ARROW-STAR
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A pointer-to-data-member needs an object; it is not a normal int pointer.
Trace: member=&Score::points; object.*member and pointer->*member name the same field.
Why it works: The member pointer describes a member within a compatible class object.
Cost: O(1) time and space.
Common mistake: Member function pointer calls require parentheses around object.*method. Keep the object alive.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

struct Score {
    int points;

    int doubled() const {
        return points * 2;
    }
};

int main() {
    Score score{7};
    int Score::* member = &Score::points;
    Score* pointer = &score;
    assert(score.*member == 7);
    pointer->*member = 9;
    assert(score.points == 9);
    int (Score::*method)() const = &Score::doubled;
    assert((score.*method)() == 18);
    std::cout << "checks passed\n";
}
