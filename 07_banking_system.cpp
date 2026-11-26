#include <iostream>
#include <string>

using namespace std;

// Base Account class
class Account {
protected:
    double balance;
    double rate;
public:
    Account(double b, double r) {
        balance = b;
        rate = r;
    }
    virtual void calculateInterest() = 0;
};

// Savings account
class SavingsAccount : public Account {
public:
    SavingsAccount(double b, double r) : Account(b, r) {}

    void calculateInterest() {
        double interest = (balance * rate) / 100.0;
        double finalBalance = balance + interest;
        cout << "Output:" << endl;
        cout << "Interest = " << interest << endl;
        cout << "Final Balance = " << finalBalance << endl;
    }
};

// Current account
class CurrentAccount : public Account {
public:
    CurrentAccount(double b, double r) : Account(b, r) {}

    void calculateInterest() {
        double interest = (balance * rate) / 100.0;
        double finalBalance = balance + interest;
        cout << "Output:" << endl;
        cout << "Interest = " << interest << endl;
        cout << "Final Balance = " << finalBalance << endl;
    }
};

// Fixed deposit account
class FixedDepositAccount : public Account {
public:
    FixedDepositAccount(double b, double r) : Account(b, r) {}

    void calculateInterest() {
        double interest = (balance * rate) / 100.0;
        double finalBalance = balance + interest;
        cout << "Output:" << endl;
        cout << "Interest = " << interest << endl;
        cout << "Final Balance = " << finalBalance << endl;
    }
};

int main() {
    string word, type = "Savings";
    double balance = 0, rate = 0;

    // Read: Account Type: Savings \n Balance = 50000 \n Interest Rate = 6
    while (cin >> word) {
        if (word == "Savings" || word == "Current" || word == "FixedDeposit") {
            type = word;
        } else if (word == "=") {
            if (balance == 0) cin >> balance;
            else {
                cin >> rate;
                break;
            }
        }
    }

    Account* acc = nullptr;
    if (type == "Savings") acc = new SavingsAccount(balance, rate);
    else if (type == "Current") acc = new CurrentAccount(balance, rate);
    else if (type == "FixedDeposit") acc = new FixedDepositAccount(balance, rate);

    if (acc != nullptr) {
        acc->calculateInterest();
        delete acc;
    }

    return 0;
}
