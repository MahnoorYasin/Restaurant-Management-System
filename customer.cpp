#include "customer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> feedbacks; // Store customer feedback

void Customer::placeOrder()
{
    cout << "--- Place Order ---\n";
    map<string, vector<pair<string, double>>> menu; // Category -> (Item, Price)

    // Load menu from file
    ifstream file("menu.txt");
    if (!file.is_open())
    {
        cout << "Error: Could not open menu.txt\n";
        return;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> tokens;
        stringstream ss(line);
        string token;

        // Tokenize by comma and handle spaces
        while (getline(ss, token, ','))
        {
            // Trim leading/trailing whitespaces from token
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            tokens.push_back(token);
        }

        // Ensure there are exactly 3 tokens (Category, Item, Price)
        if (tokens.size() == 3)
        {
            string category = tokens[0];
            string item = tokens[1];
            double price = stod(tokens[2]);

            menu[category].push_back({item, price});
        }
        else
        {
            cout << "[ERROR] Invalid menu entry: " << line << endl;
        }
    }
    file.close();

    // **Display menu in a table format**
    cout << setw(15) << left << "Category" << setw(20) << "Item" << setw(10) << "Price" << endl;
    cout << "-----------------------------------------------------\n";

    for (const auto &category : menu)
    {
        bool firstItem = true;
        for (const auto &item : category.second)
        {
            if (firstItem)
            {
                cout << setw(15) << left << category.first;
                firstItem = false;
            }
            else
            {
                cout << setw(15) << " "; // Align subsequent items under the category
            }
            cout << setw(20) << left << item.first << "$" << setw(9) << fixed << setprecision(2) << item.second << endl;
        }
    }

    // **Take customer order**
    vector<string> orderedItems;
    string item;
    double totalPrice = 0;

    cout << "Enter items (type 'done' to finish): \n";
    while (true)
    {
        cout << "Item: ";
        getline(cin, item);
        if (item == "done")
            break;

        bool found = false;
        for (const auto &category : menu)
        {
            for (const auto &menuItem : category.second)
            {
                if (menuItem.first == item)
                {
                    orderedItems.push_back(item);
                    totalPrice += menuItem.second;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

    }

    cout << "Order placed successfully! Your Total Bill: $" << fixed << setprecision(2) << totalPrice << "\n";
}

void Customer::reserveTable()
{
    cout << "--- Reserve Table ---\n";
    string tableNumber;
    cout << "Enter Table Number to Reserve: ";
    cin >> tableNumber;
    cin.ignore(); // Clear the input buffer
    cout << "Table " << tableNumber << " reserved successfully!\n";
}

void Customer::payBill()
{
    cout << "--- Pay Bill ---\n";
    double amount;
    cout << "Enter the bill amount to pay: $";
    cin >> amount;
    cin.ignore(); // Clear the input buffer

    cout << "Payment of $" << amount << " completed successfully. Thank you!\n";
}

void Customer::giveFeedback()
{
    cout << "--- Give Feedback ---\n";
    string feedback;

    // Clear the input buffer to avoid issues when using getline
    cin.ignore(); // Ignore any leftover characters in the buffer

    cout << "Enter your feedback: ";
    getline(cin, feedback); // Wait for the user to input feedback

    feedbacks.push_back(feedback); // Store feedback in memory

    // Append the feedback to the file
    ofstream feedbackFile("feedback.txt", ios::app);
    if (feedbackFile.is_open())
    {
        feedbackFile << feedback << "\n"; // Append feedback to the file
        feedbackFile.close();
        cout << "Thank you for your feedback!\n";
    }
    else
    {
        cout << "Unable to save feedback. Please try again.\n";
    }
}
