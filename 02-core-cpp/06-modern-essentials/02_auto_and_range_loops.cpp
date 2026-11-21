#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 1. auto
    // The compiler deduces the type based on the initialization value.
    auto num = 42;                    // int
    auto pi = 3.14159;                // double
    auto name = std::string{"Alice"}; // std::string: explicit owning text, already taught.

    cout << num << " " << pi << " " << name << endl;

    // 2. Range-based for loop
    vector<int> scores = {90, 85, 95, 100};

    cout << "Scores: ";
    // Use 'auto' to let the compiler figure out the type in the vector.
    // Use '&' (reference) to avoid copying the elements, especially for large objects like strings.
    for (const auto& score : scores) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
