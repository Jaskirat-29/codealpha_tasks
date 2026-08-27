#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of courses: ";
    cin >> n;

    double totalCredits = 0;
    double totalGradePoints = 0;

    for (int i = 1; i <= n; i++) {
        double grade, credits;

        cout << "\nCourse " << i << endl;

        cout << "Enter grade point: ";
        cin >> grade;

        cout << "Enter credit hours: ";
        cin >> credits;

        double gradePoints = grade * credits;

        totalCredits += credits;
        totalGradePoints += gradePoints;

        cout << "Grade Point: " << grade << endl;
        cout << "Credit Hours: " << credits << endl;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\n-----------------------------" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Semester GPA: " << gpa << endl;
    cout << "Overall CGPA: " << gpa << endl;
    cout << "-----------------------------" << endl;

    return 0;
}