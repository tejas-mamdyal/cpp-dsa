/*
FIXED PRECISION AND QUOTED TEXT SERIALIZATION
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Stream manipulators control formatting; quoted text preserves spaces and quotes.
Trace: 3.5 becomes3.50; a quoted name is read back exactly.
Why it works: The writer escapes embedded quotes and the matching reader reverses that encoding.
Cost: O(L) time and storage for serialized text.
Common mistake: Formatting flags persist on a stream; specify them intentionally. Use binary-safe/versioned formats for more demanding persistence.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <string>

int main() {
    std::ostringstream output;
    output << std::fixed << std::setprecision(2) << 3.5;
    assert(output.str() == "3.50");
    std::string name = "Ada \"Ace\"";
    std::ostringstream encoded;
    encoded << std::quoted(name);
    std::istringstream input(encoded.str());
    std::string restored;
    input >> std::quoted(restored);
    assert(restored == name);
    std::cout << "checks passed\n";
}
