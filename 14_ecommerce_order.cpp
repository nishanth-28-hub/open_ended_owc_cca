#include <iostream>
#include <string>
using namespace std;
class InvalidPriceException {
public:
    string getError() { return "Invalid Price"; }
};
class InvalidQuantityException {
public:
    string getError() { return "Invalid Quantity"; }
};
class InsufficientStockException {
public:
    string getError() { return "Insufficient Stock"; }
};
int main() {
    string word;
    double price = 0;
    int qty = 0, stock = 0;
    while (cin >> word) {
        if (word == "=") {
            if (price == 0) cin >> price;
            else if (qty == 0) cin >> qty;
            else {
                cin >> stock;
                break;
            }
        }
    }
    try {
        if (price <= 0) throw InvalidPriceException();
        if (qty <= 0) throw InvalidQuantityException();
        if (qty > stock) throw InsufficientStockException();
        double totalAmount = price * qty;
        int remainingStock = stock - qty;
        cout << "Output:" << endl;
        cout << "Order Confirmed" << endl;
        cout << "Total Amount = " << totalAmount << endl;
        cout << "Remaining Stock = " << remainingStock << endl;
    } catch (InsufficientStockException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    } catch (InvalidQuantityException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    } catch (InvalidPriceException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    }
    return 0;
}
