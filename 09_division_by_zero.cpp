#include <iostream>
using nameppace std;
int main() {
    int num, den;
    if (cin >> num >> den) {
        try {
            // Check if denominator is 0
            if (den == 0) {
                throw "Division by zero is not allowed.";
            }
            int ans = num / den;
            cout << "Output:" << endl;
            cout << "Result = " << ans << endl;

        } catch (const char* msg) {
            cout << "Output:" << endl;
            cout << "Exception: " << msg << endl;
        }
    }
    return 0;
}
