/*
COMMENTS EXPLAIN INTENT
Route: Core | Prerequisites: None; read 00-start-here first.

The compiler ignores // comments to the end of a line and block comments between
slash-star and star-slash.

O(1) time/space.

Comments do not disable punctuation outside their boundaries. Block comments cannot
nest.
*/
#include <iostream>

int main() {
    // A comment explains a decision to a reader.
    /*
This block can span
       several source lines.
*/
    std::cout << 42 << '\n'; // Numbers need no quotes when printed as values.
}
