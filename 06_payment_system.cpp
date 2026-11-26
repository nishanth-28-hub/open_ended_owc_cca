#include <iostream>
#include <string>

using namespace std;

// Base class for payment
class Payment {
public:
    virtual void makePayment(double amount) = 0;
};

// Credit Card mode
class CreditCard : public Payment {
public:
    void makePayment(double amount) {
        cout << "Output:" << endl;
        cout << "Payment Mode: Credit Card" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

// UPI mode
class UPI : public Payment {
public:
    void makePayment(double amount) {
        cout << "Output:" << endl;
        cout << "Payment Mode: UPI" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

// Cash mode
class Cash : public Payment {
public:
    void makePayment(double amount) {
        cout << "Output:" << endl;
        cout << "Payment Mode: Cash" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};

int main() {
    string mode, word;
    double amount = 0;

    cin >> mode;

    // Handles: Amount = 2500 OR 2500
    while (cin >> word) {
        if (word == "=") {
            cin >> amount;
            break;
        } else if (isdigit(word[0])) {
            amount = stod(word);
            break;
        }
    }

    Payment* p = nullptr;
    if (mode == "UPI") p = new UPI();
    else if (mode == "CreditCard") p = new CreditCard();
    else if (mode == "Cash") p = new Cash();

    if (p != nullptr) {
        p->makePayment(amount);
        delete p;
    }

    return 0;
}
