#include "admin.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

struct EmployeeData
{
    int id;
    string name;
    string post;
    double salary;
};

struct MenuItem
{
    string category;
    string name;
    double price;
};

vector<EmployeeData> employees;
vector<MenuItem> menu;

// Helper function to split a string by a delimiter
vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void Admin::loadEmployees()
{
    employees.clear();
    ifstream file("employees.txt");
    if (!file.is_open())
    {
        cout << "Error: Could not open employees.txt\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        vector<string> tokens = split(line, ',');

        if (tokens.size() != 4)
        {
            cout << "[ERROR] Invalid line format: " << line << endl;
            continue;
        }

        try
        {
            EmployeeData emp;
            emp.id = stoi(tokens[0]);
            emp.name = tokens[1];
            emp.post = tokens[2];
            emp.salary = stod(tokens[3]);
            employees.push_back(emp);
        }
        catch (const exception &e)
        {
            cout << "[ERROR] Failed to parse line: " << line << " (" << e.what() << ")\n";
        }
    }
    file.close();
}

bool Admin::isEmployeeIDUnique(int id)
{
    for (const auto &emp : employees)
    {
        if (emp.id == id)
        {
            return false; // ID already exists
        }
    }
    return true; // ID is unique
}

void Admin::manageEmployees()
{
    while (true)
    {
        cout << "\n--- Manage Employees ---\n";
        cout << "1. Add Employee\n2. Remove Employee\n3. Update Employee\n4. View Employees\n5. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            EmployeeData emp;
            cout << "Enter Employee ID: ";
            cin >> emp.id;
            if (!isEmployeeIDUnique(emp.id))
            {
                cout << "Error: Employee ID already exists!\n";
                continue;
            }
            cin.ignore();
            cout << "Enter Employee Name: ";
            getline(cin, emp.name);
            cout << "Enter Employee Post: ";
            getline(cin, emp.post);
            cout << "Enter Employee Salary: ";
            cin >> emp.salary;
            employees.push_back(emp);

            // Save to file
            ofstream file("employees.txt", ios::app);
            if (file.is_open())
            {
                file << emp.id << "," << emp.name << "," << emp.post << "," << emp.salary << "\n";
                file.close();
            }
            else
            {
                cout << "Error: Could not update employees.txt\n";
            }
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Employee ID to Remove: ";
            cin >> id;
            bool found = false;
            for (auto it = employees.begin(); it != employees.end(); ++it)
            {
                if (it->id == id)
                {
                    employees.erase(it);
                    found = true;
                    break;
                }
            }
            if (found)
            {
                // Update file
                ofstream file("employees.txt");
                if (file.is_open())
                {
                    for (const auto &emp : employees)
                    {
                        file << emp.id << "," << emp.name << "," << emp.post << "," << emp.salary << "\n";
                    }
                    file.close();
                }
                cout << "Employee removed successfully.\n";
            }
            else
            {
                cout << "Employee not found.\n";
            }
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Employee ID to Update: ";
            cin >> id;
            bool found = false;
            for (auto &emp : employees)
            {
                if (emp.id == id)
                {
                    cout << "Enter New Post: ";
                    cin.ignore();
                    getline(cin, emp.post);
                    cout << "Enter New Salary: ";
                    cin >> emp.salary;
                    found = true;
                    break;
                }
            }
            if (found)
            {
                // Update file
                ofstream file("employees.txt");
                if (file.is_open())
                {
                    for (const auto &emp : employees)
                    {
                        file << emp.id << "," << emp.name << "," << emp.post << "," << emp.salary << "\n";
                    }
                    file.close();
                }
                cout << "Employee updated successfully.\n";
            }
            else
            {
                cout << "Employee not found.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "\n--- Employee List ---\n";
            cout << setw(10) << left << "ID" << setw(20) << "Name" << setw(15) << "Post" << setw(10) << "Salary" << endl;
            cout << "------------------------------------------------------------\n";
            for (const auto &emp : employees)
            {
                cout << setw(10) << left << emp.id << setw(20) << emp.name << setw(15) << emp.post << "$" << setw(10) << fixed << setprecision(2) << emp.salary << endl;
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
}

void Admin::loadMenu()
{
    menu.clear();
    ifstream file("menu.txt");
    if (!file.is_open())
    {
        cout << "Error: Could not open menu.txt\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        vector<string> tokens = split(line, ',');

        if (tokens.size() != 3)
        {
            cout << "[ERROR] Invalid line format: " << line << endl;
            continue;
        }

        try
        {
            MenuItem item;
            item.category = tokens[0];
            item.name = tokens[1];
            item.price = stod(tokens[2]); // Ensure price is valid
            menu.push_back(item);
        }
        catch (const exception &e)
        {
            cout << "[ERROR] Failed to parse line: " << line << " (" << e.what() << ")\n";
        }
    }
    file.close();
}

void Admin::manageMenu()
{
    while (true)
    {
        cout << "\n--- Manage Menu ---\n";
        cout << "1. Add Item\n2. Remove Item\n3. Update Item\n4. View Menu\n5. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            MenuItem item;
            cout << "Enter Category: ";
            cin.ignore();
            getline(cin, item.category);
            cout << "Enter Item Name: ";
            getline(cin, item.name);
            cout << "Enter Item Price: ";
            cin >> item.price;
            menu.push_back(item);

            // Save to file
            ofstream file("menu.txt", ios::app);
            if (file.is_open())
            {
                file << item.category << "," << item.name << "," << item.price << "\n";
                file.close();
            }
            else
            {
                cout << "Error: Could not update menu.txt\n";
            }
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter Item Name to Remove: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (auto it = menu.begin(); it != menu.end(); ++it)
            {
                if (it->name == name)
                {
                    menu.erase(it);
                    found = true;
                    break;
                }
            }
            if (found)
            {
                // Update file
                ofstream file("menu.txt");
                if (file.is_open())
                {
                    for (const auto &item : menu)
                    {
                        file << item.category << "," << item.name << "," << item.price << "\n";
                    }
                    file.close();
                }
                cout << "Item removed successfully.\n";
            }
            else
            {
                cout << "Item not found.\n";
            }
        }
        else if (choice == 3)
        {
            string name;
            cout << "Enter Item Name to Update: ";
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (auto &item : menu)
            {
                if (item.name == name)
                {
                    cout << "Enter New Price: ";
                    cin >> item.price;
                    found = true;
                    break;
                }
            }
            if (found)
            {
                // Update file
                ofstream file("menu.txt");
                if (file.is_open())
                {
                    for (const auto &item : menu)
                    {
                        file << item.category << "," << item.name << "," << item.price << "\n";
                    }
                    file.close();
                }
                cout << "Item updated successfully.\n";
            }
            else
            {
                cout << "Item not found.\n";
            }
        }
        else if (choice == 4)
        {
            cout << "\n--- Menu ---\n";
            cout << setw(15) << left << "Category" << setw(20) << "Item" << setw(10) << "Price" << endl;
            cout << "------------------------------------------------------\n";
            for (const auto &item : menu)
            {
                cout << setw(15) << left << item.category << setw(20) << item.name << "$" << setw(10) << fixed << setprecision(2) << item.price << endl;
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }
}
