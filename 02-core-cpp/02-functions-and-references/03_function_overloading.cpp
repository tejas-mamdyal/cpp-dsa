#include <iostream>
#include <string>

using namespace std;

/*
* Function Overloading:
 * You can have multiple functions with the SAME NAME, as long as 
 * their parameter types or counts are different.
*/

void print(int x) {
    cout << "Printing an integer: " << x << endl;
}

void print(double x) {
    cout << "Printing a double: " << x << endl;
}

void print(string x) {
    cout << "Printing a string: " << x << endl;
}

int main() {
    print(5);
    print(3.14);
    print("Hello Overloading");

    return 0;
}
