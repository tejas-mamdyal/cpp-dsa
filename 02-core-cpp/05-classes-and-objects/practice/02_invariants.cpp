/*
CLASS INVARIANT REJECTS AN INVALID UPDATE
Prerequisites: read this unit's README and the earlier units in LEARNING_ORDER.md.
Problem and contract: Keep an integer account balance nonnegative; deposits and withdrawals return success. Amounts are bounded to 1000 for this exercise.
Trace: deposit50 then withdraw20 leaves30; overdraft fails without mutation.
Why it works: Every successful update preserves 0<=balance<=1000000; rejected operations leave state unchanged.
Cost: O(1) time and space.
Common mistake: Checking after mutation can break the invariant; validate before updating.
Practice: change the traced values, predict the result, and add one boundary case.
*/
#include <iostream>
#include <cassert>

class Account {
    int cents = 0;

public:
    bool deposit(int amount) {
        if (amount <= 0 || amount > 1000 || cents > 1000000 - amount) {
            return false;
        }
        cents += amount;
        return true;
    }

    bool withdraw(int amount) {
        if (amount <= 0 || amount > cents) {
            return false;
        }
        cents -= amount;
        return true;
    }

    int balance() const {
        return cents;
    }
};

int main() {
    Account account;
    assert(account.deposit(50));
    assert(account.withdraw(20));
    assert(!account.withdraw(31));
    assert(!account.deposit(-1));
    assert(account.balance() == 30);
    std::cout << "checks passed\n";
}
