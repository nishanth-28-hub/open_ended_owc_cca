#include <iostream>
#include <string>

using namespace std;

// User-defined exception class for balance errors
class InsufficientBalanceException {
public:
    string getError() {
        return "Insufficient balance.";
    }
};

// Bank account class
class BankAccount {
    double balance;
public:
    BankAccount(double b) {
        balance = b;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientBalanceException();
        }
        balance -= amount;
        cout << "Withdrawal successful. Remaining Balance = " << balance << endl;
    }
};

int main() {
    string word;
    double balance = 0, withdrawal = 0;

    // Handles: Balance = 10000 \n Withdrawal = 12000
    while (cin >> word) {
        if (word == "=") {
            if (balance == 0) cin >> balance;
            else {
                cin >> withdrawal;
                break;
            }
        }
    }

    BankAccount acc(balance);

    try {
        acc.withdraw(withdrawal);
    } catch (InsufficientBalanceException e) {
        cout << "Output: Exception: " << e.getError() << endl;
    }

    return 0;
}
