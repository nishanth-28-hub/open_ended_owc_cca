#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Base class for shapes
class Shape {
public:
    // Pure virtual function for calculating area
    virtual void area() = 0;
};

// Circle class derived from Shape
class Circle : public Shape {
    double radius;
public:
    Circle(double r) {
        radius = r;
    }

    void area() {
        double result = 3.14 * radius * radius;
        cout << fixed << setprecision(2);
        cout << "Area of Circle = " << result << endl;
    }
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
    double length, breadth;
public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    void area() {
        double result = length * breadth;
        cout << fixed << setprecision(2);
        cout << "Area of Rectangle = " << result << endl;
    }
};

int main() {
    string choice;
    cin >> choice;

    Shape* s = nullptr;

    if (choice == "Circle") {
        double r;
        cin >> r;
        s = new Circle(r);
    } else if (choice == "Rectangle") {
        double l, b;
        cin >> l >> b;
        s = new Rectangle(l, b);
    }

    // Call overridden function using base pointer
    if (s != nullptr) {
        s->area();
        delete s;
    }

    return 0;
}
