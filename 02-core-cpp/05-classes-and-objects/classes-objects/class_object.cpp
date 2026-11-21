/*
FIVE STUDENT RECORDS WITH VALIDATED INPUT
Prerequisites: classes, fixed arrays and full-line strings. Read exactly five
records: full name on one line, then roll and age on the next. Roll1..1000000,
age0..120, name1..80 characters. Blank leading lines are skipped by ws. Invalid
input prints a diagnostic and exits1 before any records are displayed.
Trace: Ada Lovelace / 1 18 produces Ada Lovelace,1,18 in the table.
The class owns its record fields. read validates a temporary before assigning;
print is const because displaying must not mutate the record. main coordinates.
O(total name text) input/output and stored text; five records give bounded numeric
storage. Exercise: use a vector for runtime record count and reject duplicate rolls.
*/
#include <iostream>
#include <string>

class Student {
    std::string name;
    int roll = 0;
    int age = 0;

public:
    bool read() {
        std::string candidate;
        int newRoll = 0;
        int newAge = 0;
        if (!std::getline(std::cin >> std::ws, candidate) || candidate.empty()
            || candidate.size() > 80 || !(std::cin >> newRoll >> newAge) || newRoll < 1
            || newRoll > 1000000 || newAge < 0 || newAge > 120) {
            return false;
        }
        name = candidate;
        roll = newRoll;
        age = newAge;
        return true;
    }

    void print() const {
        std::cout << name << '\t' << roll << '\t' << age << '\n';
    }
};

int main() {
    Student students[5];
    for (Student& student : students) {
        if (!student.read()) {
            std::cerr << "Invalid student record.\n";
            return 1;
        }
    }
    std::cout << "Name\tRoll No\tAge\n";
    for (const Student& student : students) {
        student.print();
    }
}
