#include <iostream>
#include <string>
#include "login.cpp"
#include "user_panels.cpp"
using namespace std;

int main()
{
    while (true)
    {
        string role = login();
        if (role == "admin")
        {
            adminPanel();
        }
        else if (role == "employee")
        {
            employeePanel();
        }
        else if (role == "customer")
        {
            customerPanel();
        }
        else
        {
            cout << "Exiting...\n";
            break;
        }
    }
    return 0;
}
