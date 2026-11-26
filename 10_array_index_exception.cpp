#include <iostream>
#include <string>
using namespace std;
int main() {
    int a[100];
    int n = 0;
    int index = -1;
    string word;
    while (cin >> word) {
        if (word == "Array:" || word == "Array") {
            continue;
        } else if (word == "Index:" || word == "Index") {
            cin >> index;
            break;
        } else if (isdigit(word[0])) {
            a[n++] = stoi(word);
        }
    }
    try {
        // Validate array boundaries
        if (index < 0 || index >= n) {
            throw "Array index out of bounds.";
        }
        cout << "Output:" << endl;
        cout << "Element at index " << index << " = " << a[index] << endl;
    } catch (const char* error) {
        cout << "Output:" << endl;
        cout << "Exception: " << error << endl;
    }
    return 0;
}
