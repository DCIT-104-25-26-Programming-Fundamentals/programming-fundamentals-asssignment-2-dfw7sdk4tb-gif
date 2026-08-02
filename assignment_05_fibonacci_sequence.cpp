// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Function prototypes
void printFibonacci(int n);
void checkFibonacci(int num);

int main()
{
    int n, number;

    // Part A
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number of terms must be a positive integer." << endl;
    }
    else
    {
        cout << "Fibonacci sequence: ";
        printFibonacci(n);
    }

    cout << endl;

    // Part B
    cout << "Enter a number to check: ";
    cin >> number;

    checkFibonacci(number);

    return 0;
}

// Function to print the first N Fibonacci numbers
void printFibonacci(int n)
{
    int first = 0, second = 1, next;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << first << " ";
        }
        else if (i == 2)
        {
            cout << second << " ";
        }
        else
        {
            next = first + second;
            cout << next << " ";
            first = second;
            second = next;
        }
    }

    cout << endl;
}

// Function to check if a number is a Fibonacci number
void checkFibonacci(int num)
{
    if (num < 0)
    {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    int first = 0, second = 1, next = 0;

    if (num == 0 || num == 1)
    {
        cout << num << " is a Fibonacci number." << endl;
        return;
    }

    while (next < num)
    {
        next = first + second;
        first = second;
        second = next;
    }

    if (next == num)
    {
        cout << num << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}
