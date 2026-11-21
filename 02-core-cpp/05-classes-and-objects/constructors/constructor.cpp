/*
A constructor establishes an object's initial state and has no return type.
Here parameter names shadow member names; this->roll selects the current object's
member. Every Student object gets its own values. An initializer list can initialize
members directly instead of assigning in the body. Exercise: rewrite using an
initializer list and make showdetails() const because it only observes state.
Construction/display cost O(name length), with O(name length) string storage.
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    int age;
    string name;

public:
    Student(int roll, string name, int age) {
        this->roll = roll;
        this->age = age;
        this->name = name;
    }

    void showdetails() {
        cout << "Roll no : " << roll << "\tName : " << name << "\tAge : " << age << endl;
    }
};

int main() {
    Student s1(10, "Tejas", 19);
    s1.showdetails();
    return 0;
}
