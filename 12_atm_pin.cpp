#include <iostream>
#include <string>
using namespace std;
class IncorrectPINException {
public:
    string getError() {
        return "Incorrect PIN.";
    }
};
class ATM {
    int correctPIN;
    int attemptsRemaining;
public:
    ATM(int pin) {
        correctPIN = pin;
        attemptsRemaining = 3;
    }
    void verifyPIN(int enteredPIN) {
        if (enteredPIN != correctPIN) {
            attemptsRemaining--;
            throw IncorrectPINException();
        }
        cout << "PIN Verified Successfully." << endl;
    }
    int getAttempts() {
        return attemptsRemaining;
    }
};
int main() {
    string word;
    int correctPIN = 0, enteredPIN = 0;
    while (cin >> word) {
        if (word == "=") {
            if (correctPIN == 0) cin >> correctPIN;
            else {
                cin >> enteredPIN;
                break;
            }
        }
    }
    ATM atm(correctPIN);
    try {
        atm.verifyPIN(enteredPIN);
    } catch (IncorrectPINException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
        cout << "Attempts Remaining: " << atm.getAttempts() << endl;
    }

    return 0;
}
