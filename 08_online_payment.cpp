#include <iostream>
#include <string>

using namespace std;

// Base class
class Payment {
public:
    virtual void processPayment(double amount, double feePercent) = 0;
};

// Card payment with surcharge
class CardPayment : public Payment {
public:
    void processPayment(double amount, double feePercent) {
        double fee = (amount * feePercent) / 100.0;
        cout << "Output:" << endl;
        cout << "Transaction Charge = " << fee << endl;
        cout << "Total Amount = " << (amount + fee) << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

// UPI payment with surcharge
class UPIPayment : public Payment {
public:
    void processPayment(double amount, double feePercent) {
        double fee = (amount * feePercent) / 100.0;
        cout << "Output:" << endl;
        cout << "Transaction Charge = " << fee << endl;
        cout << "Total Amount = " << (amount + fee) << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

// Net banking payment with surcharge
class NetBankingPayment : public Payment {
public:
    void processPayment(double amount, double feePercent) {
        double fee = (amount * feePercent) / 100.0;
        cout << "Output:" << endl;
        cout << "Transaction Charge = " << fee << endl;
        cout << "Total Amount = " << (amount + fee) << endl;
        cout << "Payment Status = Successful" << endl;
    }
};

int main() {
    string word, mode = "Card";
    double amount = 0, chargeRate = 0;

    // Read: Payment Mode: Card \n Amount = 10000 \n Transaction Charge = 2%
    while (cin >> word) {
        if (word == "Card" || word == "UPI" || word == "NetBanking") {
            mode = word;
        } else if (word == "=") {
            if (amount == 0) {
                cin >> amount;
            } else {
                string pct;
                cin >> pct;
                if (pct.back() == '%') pct.pop_back();
                chargeRate = stod(pct);
                break;
            }
        }
    }

    Payment* p = nullptr;
    if (mode == "Card") p = new CardPayment();
    else if (mode == "UPI") p = new UPIPayment();
    else if (mode == "NetBanking") p = new NetBankingPayment();

    if (p != nullptr) {
        p->processPayment(amount, chargeRate);
        delete p;
    }

    return 0;
}
