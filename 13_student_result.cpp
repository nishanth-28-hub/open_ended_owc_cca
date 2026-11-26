#include <iostream>
#include <string>

using namespace std;

// User-defined exception for marks validation
class InvalidMarksException {
public:
    string getError() {
        return "Marks out of range (0-100).";
    }
};

int main() {
    int numSubjects;
    string dummy;

    if (!(cin >> numSubjects)) return 0;
    cin >> dummy; // Reads "Subjects"

    int marks[50];
    int total = 0;

    try {
        for (int i = 0; i < numSubjects; i++) {
            cin >> marks[i];
            // Check if marks are valid
            if (marks[i] < 0 || marks[i] > 100) {
                throw InvalidMarksException();
            }
            total += marks[i];
        }

        double average = (double)total / numSubjects;
        char grade;

        if (average >= 80) grade = 'A';
        else if (average >= 70) grade = 'B';
        else if (average >= 60) grade = 'C';
        else if (average >= 50) grade = 'D';
        else grade = 'F';

        cout << "Output:" << endl;
        cout << "Total = " << total << endl;
        cout << "Average = " << average << endl;
        cout << "Grade = " << grade << endl;

    } catch (InvalidMarksException e) {
        cout << "Output:" << endl;
        cout << "Exception: " << e.getError() << endl;
    }

    return 0;
}
