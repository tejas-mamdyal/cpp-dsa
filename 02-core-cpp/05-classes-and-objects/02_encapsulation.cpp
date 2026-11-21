#include <iostream>
#include <string>

using namespace std;

// By default, everything in a class is PRIVATE.
class BankAccount {
private:
    string owner;
    double balance;

public:
    // Constructor
    BankAccount(string name, double initial_balance) {
        owner = name;
        balance = initial_balance;
    }

    // Getter
    double getBalance() const {
        return balance;
    }

    // Setter (with validation)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
};

int main() {
    BankAccount account("Alice", 1000.0);

    // ERROR: Cannot access private members directly
    // account.balance = 5000.0;

    cout << "Balance: $" << account.getBalance() << endl;
    account.deposit(500.0);
    cout << "New Balance: $" << account.getBalance() << endl;

    return 0;
}
