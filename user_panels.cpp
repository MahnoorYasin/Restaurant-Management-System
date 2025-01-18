#include "user_panels.h"
#include "login.h"
#include "admin.cpp"
#include "employee.cpp"
#include "customer.cpp"
#include <iostream>
#include <limits>
using namespace std;



void adminPanel()
{
    Admin admin;
    admin.loadEmployees();
    admin.loadMenu();

    while (true)
    {
        cout << "\n--- Admin Panel ---\n";
        cout << "1. Manage Employees\n2. Manage Menu\n3. Logout\nEnter choice: ";
        int choice;

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            admin.manageEmployees();
            break;
        case 2:
            admin.manageMenu();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void employeePanel()
{
    Employee employee;
    while (true)
    {
        cout << "\n--- Employee Panel ---\n";
        cout << "1. Take Order\n2. Display Orders\n3. Reserve Table\n4. Cancel Order/Table\n5. Billing and Payment\n6. Logout\nEnter choice: ";
        int choice;

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            employee.takeOrder();
            break;
        case 2:
            employee.displayOrders();
            break;
        case 3:
            employee.reserveTable();
            break;
        case 4:
            employee.cancelOrder();
            break;
        case 5:
            employee.billingAndPayment();
            break;
        case 6:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void customerPanel()
{
    Customer customer;
    while (true)
    {
        cout << "\n--- Customer Panel ---\n";
        cout << "1. Place Order\n2. Reserve Table\n3. Pay Bill\n4. Give Feedback\n5. Logout\nEnter choice: ";
        int choice;

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            customer.placeOrder();
            break;
        case 2:
            customer.reserveTable();
            break;
        case 3:
            customer.payBill();
            break;
        case 4:
            customer.giveFeedback();
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
