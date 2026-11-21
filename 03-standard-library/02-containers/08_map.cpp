#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
* std::map (Ordered Associative Container)
 * 
 * Why use it?
 * Stores Key-Value pairs sorted by Key. Keys must be UNIQUE.
 * Internally implemented as a Red-Black Tree.
 * 
 * Complexity:
 * - Insert: O(log N)
 * - Erase: O(log N)
 * - Access [key]: O(log N)
 * 
 * MISTAKE WARNING:
 * map[key] will automatically CREATE the key with a default value (0) if it doesn't exist!
*/

int main() {
    map<string, int> ages;

    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages.insert({"Charlie", 22});

    cout << "Bob's age: " << ages["Bob"] << endl;

    // WARNING! "David" doesn't exist. This will insert "David" with age 0!
    cout << "David's age (accidentally inserted!): " << ages["David"] << endl;

    // Safe way to check if a key exists
    if (ages.find("Eve") == ages.end()) {
        cout << "Eve is not in the map." << endl;
    }

    // Iteration using Structured Bindings (C++17)
    cout << "\nAll entries (Sorted by Key!):" << endl;
    for (const auto& [name, age] : ages) {
        cout << name << " -> " << age << endl;
    }

    return 0;
}
