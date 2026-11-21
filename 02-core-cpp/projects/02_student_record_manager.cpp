/*
STUDENT RECORD MANAGER
Prerequisites: encapsulation, vectors/maps, lambdas, sort, accumulate, quoted input.
Commands: ADD id "name" count mark..., UPDATE id count mark..., REMOVE id,
REPORT, FILTER threshold, FIND id, QUIT. One complete command per line.
ID 1..1000000; name 1..80 characters; count 1..10; marks 0..100; at most1000
students; threshold0..100. ADD duplicates and absent UPDATE/REMOVE are errors.
FIND absence prints NOT FOUND. REPORT sorts descending average then ascending ID;
FILTER uses that order but prints only averages >=threshold. Fixed two decimals.
EOF ends normally. Invalid input prints stderr and returns1; earlier output remains.
The Student model owns its marks privately and computes derived averages instead
of caching a value that can become stale. Parsing validates a temporary before
updates. A map owns students by ID; sorted reports borrow via a copied vector.
Trace: ADD1 Ada marks80,100 ->ADDED; REPORT ->1 "Ada" 90.00.
CRUD O(log n + m), reporting O(n log n * m) for at most10 marks per comparison;
O(n*m) copied report storage. Format state is explicit, and stable IDs break ties.
Practice: add a validated CSV import/export using the contact manager's staged-load
pattern; add a median summary after learning selection algorithms.
*/
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Student {
    int identifier;
    std::string label;
    std::vector<int> marks;

public:
    Student(int id, const std::string& name, const std::vector<int>& values)
        : identifier(id),
          label(name),
          marks(values) {
    }

    int id() const {
        return identifier;
    }

    const std::string& name() const {
        return label;
    }

    void replaceMarks(const std::vector<int>& values) {
        marks = values;
    }

    double average() const {
        return std::accumulate(marks.begin(), marks.end(), 0.0) / static_cast<double>(marks.size());
    }
};

bool finished(std::istringstream& input) {
    char extra = ' ';
    return !(input >> extra);
}

bool readMarks(std::istringstream& input, std::vector<int>& marks) {
    int count = 0;
    if (!(input >> count) || count < 1 || count > 10) {
        return false;
    }
    std::vector<int> candidate;
    for (int i = 0; i < count; ++i) {
        int value = 0;
        if (!(input >> value) || value < 0 || value > 100) {
            return false;
        }
        candidate.push_back(value);
    }
    if (!finished(input)) {
        return false;
    }
    marks = std::move(candidate);
    return true;
}

void print(const Student& student) {
    std::cout << student.id() << ' ' << std::quoted(student.name()) << ' ' << std::fixed
              << std::setprecision(2) << student.average() << '\n';
}

void report(const std::map<int, Student>& students, double threshold) {
    std::vector<Student> ordered;
    for (const auto& entry : students) {
        ordered.push_back(entry.second);
    }
    std::sort(ordered.begin(), ordered.end(), [](const Student& a, const Student& b) {
        if (a.average() != b.average()) {
            return a.average() > b.average();
        }
        return a.id() < b.id();
    });
    for (const Student& student : ordered) {
        if (student.average() >= threshold) {
            print(student);
        }
    }
}

bool execute(const std::string& line, std::map<int, Student>& students, bool& quit) {
    std::istringstream input(line);
    std::string command;
    if (!(input >> command)) {
        return false;
    }
    if (command == "ADD" || command == "UPDATE") {
        int id = 0;
        if (!(input >> id) || id < 1 || id > 1000000) {
            return false;
        }
        std::string name;
        if (command == "ADD"
            && (!(input >> std::quoted(name)) || name.empty() || name.size() > 80)) {
            return false;
        }
        std::vector<int> marks;
        if (!readMarks(input, marks)) {
            return false;
        }
        auto found = students.find(id);
        if (command == "ADD") {
            if (found != students.end() || students.size() == 1000) {
                return false;
            }
            students.emplace(id, Student(id, name, marks));
            std::cout << "ADDED\n";
        } else {
            if (found == students.end()) {
                return false;
            }
            found->second.replaceMarks(marks);
            std::cout << "UPDATED\n";
        }
        return true;
    }
    if (command == "REMOVE" || command == "FIND") {
        int id = 0;
        if (!(input >> id) || id < 1 || id > 1000000 || !finished(input)) {
            return false;
        }
        auto found = students.find(id);
        if (command == "REMOVE") {
            if (found == students.end()) {
                return false;
            }
            students.erase(found);
            std::cout << "REMOVED\n";
        } else if (found == students.end()) {
            std::cout << "NOT FOUND\n";
        } else {
            print(found->second);
        }
        return true;
    }
    double threshold = 0;
    if (command == "FILTER" && (!(input >> threshold) || !(threshold >= 0 && threshold <= 100))) {
        return false;
    }
    if (!finished(input)) {
        return false;
    }
    if (command == "REPORT" || command == "FILTER") {
        report(students, threshold);
    } else if (command == "QUIT") {
        quit = true;
    } else {
        return false;
    }
    return true;
}

int main() {
    std::map<int, Student> students;
    std::string line;
    bool quit = false;
    while (!quit && std::getline(std::cin, line)) {
        if (!execute(line, students, quit)) {
            std::cerr << "Invalid command or student record.\n";
            return 1;
        }
    }
    if (std::cin.bad()) {
        std::cerr << "Input read failed.\n";
        return 1;
    }
    return 0;
}
