#include <iostream>

using namespace std;

int main() {
    int score = 100;

    // '&' gets the memory address of the variable
    cout << "Value of score: " << score << endl;
    cout << "Address of score: " << &score << endl;

    // '*' creates a pointer variable to store an address
    int* ptr = &score;
    cout << "Value of ptr (an address): " << ptr << endl;

    // Dereferencing: Use '*' on a pointer to access the value at that address
    cout << "Value at the address ptr points to: " << *ptr << endl;

    // Modifying the value via the pointer
    *ptr = 200;
    cout << "New value of score: " << score << endl;

    // The nullptr (Always initialize pointers!)
    int* safe_ptr = nullptr;
    if (safe_ptr == nullptr) {
        cout << "safe_ptr is pointing to nothing (safe!)." << endl;
    }

    return 0;
}
