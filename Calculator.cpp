/*
 * Calculator.cpp
 *
 *  Date: 03/8/2023
 *  Author: Shekhar Chaudhary
 */

#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

int main() // Change void to int main as main should always return a value.
{
    double op1, op2; // hange the data type of op1 and op2 to double to handle non-integer arithmetic expressions.
    char operation;
    char answer = 'Y';                     // Initialize answer to Y, and use single quotes to assign a character value instead of double quotes which are used for string literals.
    while (answer == 'Y' || answer == 'y') // Use double equals to compare values in the while loop, and add || operator to check for lowercase y as well.
    {
        cout << "Enter expression" << endl;
        cin >> op2 >> operation >> op1;
        // Fix the order of operands to match the operator in each arithmetic operation.
        // Remove semicolons after if statements, which cause the following cout statement to always execute.
        // Add semicolons after each cout statement.
        if (operation == '+')
        {
            cout << op2 << " + " << op1 << " = " << op2 + op1 << endl;
        }
        if (operation == '-')
        {
            cout << op2 << " - " << op1 << " = " << op2 - op1 << endl;
        }
        if (operation == '*')
        {
            cout << op2 << " * " << op1 << " = " << op2 * op1 << endl;
        }
        if (operation == '/')
        {
            cout << op2 << " / " << op1 << " = " << op2 / op1 << endl;
        }
        cout << "Do you wish to evaluate another expression? " << endl;
        cin >> answer;
    }
    cout << "Program Finished." << endl; // Add program to terminate.
    return 0;
}
