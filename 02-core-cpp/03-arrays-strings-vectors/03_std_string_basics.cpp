/*
size_t is an unsigned integer type used for sizes and indices; std::size_t is declared in cstddef. Zero minus one wraps, so test emptiness before subtracting. It is not necessarily the same width as int.

string::npos is the unsigned not-found sentinel returned by find. Compare against npos before using the position as an index; a failed find is not position zero.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declaration
    string greeting = "Hello";
    string name = "Alice";

    // Concatenation
    string message = greeting + ", " + name + "!";
    cout << message << endl;

    // Length
    cout << "Length of message: " << message.length() << endl;

    // Accessing characters
    cout << "First character: " << message[0] << endl;

    // Substring (starting index, length)
    string sub = message.substr(0, 5);
    cout << "Substring: " << sub << endl;

    // Finding characters or substrings
    size_t pos = message.find("Alice");
    if (pos != string::npos) {
        cout << "'Alice' found at index: " << pos << endl;
    }

    // String Traversal
    cout << "Characters: ";
    for (char c : greeting) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
