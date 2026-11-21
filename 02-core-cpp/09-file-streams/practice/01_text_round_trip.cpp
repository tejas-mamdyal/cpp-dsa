/*
WRITE CLOSE AND READ A TEXT FILE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Write a known record in a scratch build directory; close before opening an input stream.
Trace: Ada and42 survive the file round trip.
Why it works: Closing the output flushes buffered text before the input reads it.
Cost: O(L) text I/O for L characters, O(L) record storage.
Common mistake: The checker/compile instructions create build first. Always inspect stream state and define overwrite versus append behavior.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>

int main() {
    {
        std::ofstream output("build/text_round_trip.txt");
        assert(output);
        output << "Ada\n42\n";
        output.close();
        assert(output);
    }
    std::ifstream input("build/text_round_trip.txt");
    assert(input);
    std::string name;
    int score = 0;
    assert(std::getline(input, name));
    assert(input >> score);
    assert(name == "Ada" && score == 42);
    std::cout << "checks passed\n";
}
