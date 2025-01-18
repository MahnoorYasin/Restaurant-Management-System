#include "employee.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

struct Order
{
    int orderID;
    string tableNumber;
    vector<string> items;
    double totalPrice;
} newOrder;

vector<Order> orders; // Store all orders
int nextOrderID = 1;

void Employee::takeOrder()
{
    cout << "--- Take Order ---\n";
    newOrder.orderID = nextOrderID++;
    cout << "Enter Table Number(1-15): ";
    cin >> newOrder.tableNumber;
    cin.ignore(); // To clear the input buffer for the next input

    // Load menu from menu.txt file
    map<string, vector<pair<string, double>>> menu; // Category -> (Item, Price)

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

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

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

    // Loop through menu categories and display items
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
    string item;
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
                    newOrder.items.push_back(item);
                    newOrder.totalPrice += menuItem.second;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }

        if (!found)
        {
            cout << "Item not found! Please enter a valid item.\n";
        }
    }

    cout << "Order taken successfully! Order ID: " << newOrder.orderID << "\n";
    cout << "Total Price: $" << fixed << setprecision(2) << newOrder.totalPrice << endl;

    // Add the order to the orders list
    orders.push_back(newOrder);
}

void Employee::displayOrders()
{
    cout << "--- Display Orders ---\n";
    if (orders.empty())
    {
        cout << "No orders to display.\n";
        return;
    }

    for (const auto &order : orders)
    {
        cout << "Order ID: " << order.orderID << endl;
        cout << "Table Number: " << order.tableNumber << endl;
        cout<< "Total Price: " << order.totalPrice <<endl;
        cout << "Items: ";
        for (const auto &item : order.items)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
}

void Employee::reserveTable()
{
    cout << "--- Reserve Table ---\n";
    string tableNumber;
    cout << "Enter Table Number to Reserve: ";
    cin >> tableNumber;
    if(tableNumber==newOrder.tableNumber)
    {
        cout << "The table " << tableNumber << " is already reserved. Try again" << endl;
    }
    else
    {
        cout << "Table " << tableNumber << " reserved successfully!\n";
    }

    // You could add logic to save reservations to a file if needed
}

void Employee::cancelOrder()
{
    cout << "--- Cancel Order ---\n";
    int orderID;
    cout << "Enter Order ID to Cancel: ";
    cin >> orderID;

    bool found = false;
    for (auto it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->orderID == orderID)
        {
            orders.erase(it);
            found = true;
            cout << "Order " << orderID << " canceled successfully.\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Order not found.\n";
    }
}

void Employee::billingAndPayment()
{
    cout << "--- Billing and Payment ---\n";
    int orderID;
    cout << "Enter Order ID for Billing: ";
    cin >> orderID;

    bool found = false;
    for (const auto &order : orders)
    {
        if (order.orderID == orderID)
        {
            cout << "Order ID: " << order.orderID
                 << ", Table Number: " << order.tableNumber
                 << ", Total Price: " << order.totalPrice << "\n";
            cout << "Payment Successful. Thank you!\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Order not found.\n";
    }
}
