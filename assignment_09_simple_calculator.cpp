// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store student information
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void calculateAverage(const vector<Student>& students);
double getAverage(const vector<double>& scores);

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                calculateAverage(students);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student s;
    int numScores;

    cin.ignore();

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);

    cout << "Student \"" << s.name << "\" added successfully.\n";
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << "\n---------------------------------------------------------------\n";
    cout << left << setw(20) << "Name"
         << setw(12) << "ID"
         << setw(25) << "Scores"
         << "Average\n";
    cout << "---------------------------------------------------------------\n";

    for (const Student& s : students) {
        cout << left << setw(20) << s.name
             << setw(12) << s.id;

        for (double score : s.scores) {
            cout << score << " ";
        }

        cout << "\t" << fixed << setprecision(2)
             << getAverage(s.scores) << endl;
    }
}

// Function to calculate average score for a specific student
void calculateAverage(const vector<Student>& students) {
    int searchID;
    bool found = false;

    cout << "Enter student ID: ";
    cin >> searchID;

    for (const Student& s : students) {
        if (s.id == searchID) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: "
                 << getAverage(s.scores) << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student ID not found.\n";
    }
}

// Function to compute average score
double getAverage(const vector<double>& scores) {
    if (scores.empty())
        return 0.0;

    double sum = 0;

    for (double score : scores) {
        sum += score;
    }

    return sum / scores.size();
}
