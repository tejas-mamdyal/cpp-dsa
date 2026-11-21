/*
STRING VIEW BORROWS CHARACTERS WITHOUT OWNING THEM
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: A string_view observes existing storage and substr returns another view. Keep the owner alive and avoid reallocation.
Trace: cat viewed as cat; source[0]=C changes the view to Cat.
Why it works: The view stores a location and length instead of copying the owned text.
Cost: O(1) view construction/subview, O(n) string comparison; O(1) view handles.
Common mistake: A view can dangle after owner destruction/reallocation. data() is not guaranteed to point to a null-terminated view-sized string.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <string_view>

int main() {
    std::string owner = "cat";
    std::string_view view(owner);
    assert(view == "cat");
    owner[0] = 'C';
    assert(view == "Cat");
    std::string_view suffix = view.substr(1);
    assert(suffix == "at");
    std::string independent(view);
    owner[0] = 'B';
    assert(independent == "Cat");
    assert(view == "Bat");
    std::cout << "checks passed\n";
}
