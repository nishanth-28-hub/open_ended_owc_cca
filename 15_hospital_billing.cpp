#include <iostream>
#include <string>

using namespace std;

// Custom exceptions for hospital billing validation
class InvalidAgeException {
public:
    string getError() { return "Invalid Patient Age"; }
};

class NegativeBillingException {
public:
    string getError() { return "Negative billing amount not allowed."; }
};

int main() {
    string word;
    int age = -999;
    double consultationFee = 0, labCharges = 0, medicineCost = 0;

    // Read patient age
    while (cin >> word) {
        if (word == "=") {
            cin >> age;
            break;
        }
    }

    try {
        // Validate patient age
        if (age <= 0 || age > 130) {
            throw InvalidAgeException();
        }

        // If age is valid, read the bill items
        while (cin >> word) {
            if (word == "=") {
                if (consultationFee == 0) cin >> consultationFee;
                else if (labCharges == 0) cin >> labCharges;
                else {
                    cin >> medicineCost;
                    break;
                }
            }
        }

        if (consultationFee < 0 || labCharges < 0 || medicineCost < 0) {
            throw NegativeBillingException();
        }

        double totalBill = consultationFee + labCharges + medicineCost;

        cout << "Output:" << endl;
        cout << "Total Hospital Bill = " << totalBill << endl;
        cout << "Bill Generated Successfully" << endl;

    } catch (InvalidAgeException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    } catch (NegativeBillingException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    }

    return 0;
}
