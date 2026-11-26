#include <iostream>
using namespace std;
template <typename T>
class Calculator {
    T a, b;
public:
    Calculator(T val1, T val2) {
        a = val1;
        b = val2;
    }
    void calculateAndShow() {
        cout << "Output:" << endl;
        cout << "Addition = " << (a + b)
             << " , Subtraction = " << (a - b)
             << " , Multiplication = " << (a * b)
             << " , Division = " << (a / b) << endl;
    }
};
int main() {
    int num1, num2;
    if (cin >> num1 >> num2) {
        Calculator<int> calc(num1, num2);
        calc.calculateAndShow();
    }
    return 0;
}
