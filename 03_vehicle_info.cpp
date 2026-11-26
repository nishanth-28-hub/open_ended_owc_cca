#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
    string brand;
    string model;
public:
    Vehicle(string b, string m) {
        brand = b;
        model = m;
    }
    virtual void displayDetails() = 0; 
};
class Car : public Vehicle {
public:
    Car(string b, string m) : Vehicle(b, m) {}

    void displayDetails() {
        cout << "Output:" << endl;
        cout << "Vehicle: Car" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};
class Bike : public Vehicle {
public:
    Bike(string b, string m) : Vehicle(b, m) {}

    void displayDetails() {
        cout << "Output:" << endl;
        cout << "Vehicle: Bike" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};
class Bus : public Vehicle {
public:
    Bus(string b, string m) : Vehicle(b, m) {}
    void displayDetails() {
        cout << "Output:" << endl;
        cout << "Vehicle: Bus" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }
};
int main() {
    string type, word;
    string brandName = "", modelName = "";
    cin >> type;
    while (cin >> word) {
        if (word == "=") {
            if (brandName == "") cin >> brandName;
            else {
                cin >> modelName;
                break;
            }
        } else if (word != "Brand" && word != "Model") {
            if (brandName == "") brandName = word;
            else {
                modelName = word;
                break;
            }
        }
    }
    Vehicle* v = nullptr;
    if (type == "Bike") v = new Bike(brandName, modelName);
    else if (type == "Car") v = new Car(brandName, modelName);
    else if (type == "Bus") v = new Bus(brandName, modelName);

    if (v != nullptr) {
        v->displayDetails();
        delete v;
    }

    return 0;
}
