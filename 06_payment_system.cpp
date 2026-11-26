#include <iostream>
#include <string>
using namespace std;
class Payment {
public:
    virtual void makePayment(double amount) = 0;
};
class CreditCard : public Payment {
public:
    void makePayment(double amount) {
        cout << "Output:" << endl;
        cout << "Payment Mode: Credit Card" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};
class UPI : public Payment {
public:
    void makePayment(double amount) {
        cout << "Output:" << endl;
        cout << "Payment Mode: UPI" << endl;
        cout << "Amount Paid = " << amount << endl;
        cout << "Payment Successful" << endl;
    }
};
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
