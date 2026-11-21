#include <iostream>
#include <stdexcept>

using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        // Throw an exception when an error occurs
        throw runtime_error("Division by zero error!");
    }
    return a / b;
}

int main() {
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl; // This will throw
        cout << "This line will not execute." << endl;
    } catch (const exception& e) {
        // Catch the exception and handle it gracefully
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues execution normally..." << endl;

    return 0;
}
