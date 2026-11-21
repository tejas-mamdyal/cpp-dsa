/*
SEARCH AND UPDATE A VECTOR OF RECORDS
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Find a record by stable ID using a linear scan; update only the matching record.
Trace: ID2 has90 marks, becomes95; ID9 is absent.
Why it works: A unique ID selects exactly one record; other records remain unchanged.
Cost: O(n) search time and O(1) extra storage.
Common mistake: Do not retain references into a vector across reallocation; use IDs and reacquire the record.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>
#include <vector>

struct Student {
    int id;
    int mark;
};

int main() {
    std::vector<Student> students = {{1, 80}, {2, 90}};
    bool found = false;
    for (Student& student : students) {
        if (student.id == 2) {
            student.mark = 95;
            found = true;
            break;
        }
    }
    assert(found);
    assert(students[0].mark == 80);
    assert(students[1].mark == 95);
    std::cout << "checks passed\n";
}
