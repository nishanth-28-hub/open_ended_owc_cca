#include <iostream>
#include <string>

using namespace std;

// Base class representing general employee
class Employee {
public:
    virtual void calculateSalary() = 0; // Pure virtual function
};

// Developer class with basic salary + bonus
class Developer : public Employee {
    double basic;
    double bonus;
public:
    Developer(double b, double bon) {
        basic = b;
        bonus = bon;
    }

    void calculateSalary() {
        double total = basic + bonus;
        cout << "Output: Total Salary = " << total << endl;
    }
};

// Manager class with basic salary + bonus/allowance
class Manager : public Employee {
    double basic;
    double bonus;
public:
    Manager(double b, double bon) {
        basic = b;
        bonus = bon;
    }

    void calculateSalary() {
        double total = basic + bonus;
        cout << "Output: Total Salary = " << total << endl;
    }
};

int main() {
    string role, token;
    double basicSalary = 0, bonusAmount = 0;

    cin >> role;

    // Read inputs like: Basic Salary = 30000 \n Bonus = 5000 OR 30000 5000
    while (cin >> token) {
        if (token == "=") {
            if (basicSalary == 0) cin >> basicSalary;
            else {
                cin >> bonusAmount;
                break;
            }
        } else if (isdigit(token[0])) {
            if (basicSalary == 0) basicSalary = stod(token);
            else {
                bonusAmount = stod(token);
                break;
            }
        }
    }

    Employee* emp = nullptr;

    if (role == "Developer") {
        emp = new Developer(basicSalary, bonusAmount);
    } else if (role == "Manager") {
        emp = new Manager(basicSalary, bonusAmount);
    }

    if (emp != nullptr) {
        emp->calculateSalary();
        delete emp;
    }

    return 0;
}
