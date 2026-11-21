
#include <cassert>
#include <fstream>
#include <string>

int main() {
    {
        std::ofstream output("build/notes.txt"); // Default mode replaces this teaching file.
        if (!output) {
            return 1;
        }
        output << "Learn, trace, implement, test.\n";
        if (!output) {
            return 1;
        }
    } // Close and release before opening for reading.
    std::ifstream input("build/notes.txt");
    if (!input) {
        return 1;
    }
    std::string line;
    std::getline(input, line);
    assert(line == "Learn, trace, implement, test.");
}
