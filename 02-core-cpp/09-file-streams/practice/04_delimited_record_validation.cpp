/*
VALIDATE A COMPLETE RECORD BEFORE COMMITTING IT
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Parse id,mark in two stages and reject any extra character. Keep the old record unchanged on failure.
Trace: 2,90 accepted;2,90x rejected; previous result remains2,90.
Why it works: Only a fully valid local candidate is assigned to persistent state.
Cost: O(L) parsing time/storage for L characters.
Common mistake: Updating fields during parsing can leave a half-modified object after an error.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <sstream>
#include <string>

struct Record {
    int id;
    int mark;
};

bool parse(const std::string& line, Record& result) {
    std::istringstream input(line);
    Record candidate{};
    char comma = ' ';
    char extra = ' ';
    if (!(input >> candidate.id >> comma >> candidate.mark) || comma != ',' || candidate.id <= 0
        || candidate.mark < 0 || candidate.mark > 100 || (input >> extra)) {
        return false;
    }
    result = candidate;
    return true;
}

int main() {
    Record record{1, 50};
    assert(parse("2,90", record));
    assert(record.id == 2 && record.mark == 90);
    assert(!parse("2,90x", record));
    assert(record.id == 2 && record.mark == 90);
    assert(!parse("2,101", record));
    std::cout << "checks passed\n";
}
