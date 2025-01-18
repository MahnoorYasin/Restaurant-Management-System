#include "login.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

// Function to clear the console screen based on the platform
void clearScreen()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls"); // Windows
#else
    system("clear"); // UNIX-like (Linux/Mac)
#endif
}

// Function to display the restaurant management system header
void displayHeading()
{
    cout << "\n\n";
    cout << "**************************\n";
    cout << "*  RESTAURANT MANAGEMENT *\n";
    cout << "*     SYSTEM             *\n";
    cout << "**************************\n";
    cout << "\n";
}

string login()
{
    clearScreen(); // Clear the screen when the program starts

    // Display the restaurant management system header
    displayHeading();

    int choice;
    while (true)
    {
        // Display login options
        cout << "--- Login ---\n";
        cout << "Select Role: \n";
        cout << "1. Admin\n";
        cout << "2. Employee\n";
        cout << "3. Customer\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        // Validate the input for 'choice'
        if (!(cin >> choice))
        {
            cin.clear();                                         // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number.\n";
            continue; // Re-prompt the user
        }

        switch (choice)
        {
        case 1:
        {
            int password;
            cout << "Enter Admin Password: ";
            if (!(cin >> password))
            { // Validate input for password
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Password must be a number.\n";
                continue; // Re-prompt the user for valid input
            }
            if (password == 1234)
            {
                return "admin"; // Return "admin" if password matches
            }
            else
            {
                cout << "Invalid Admin Password!\n";
            }
            break;
        }
        case 2:
            return "employee"; // Return "employee" for employee role
        case 3:
            return "customer"; // Return "customer" for customer role
        case 4:
            return "exit"; // Exit the program if the user chooses this option
        default:
            cout << "Invalid choice! Please select a valid role.\n";
        }
    }
}
