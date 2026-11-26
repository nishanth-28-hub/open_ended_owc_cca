#include <iostream>
using namespace std;
template <typename T>
void sortArray(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    if (cin >> n) {
        int a[100];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sortArray(a, n);
        cout << "Output:" << endl;
        cout << "Sorted Array:" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
