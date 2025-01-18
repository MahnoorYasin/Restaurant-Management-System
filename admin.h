#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin
{
public:
    void loadEmployees();
    void manageEmployees();
    void loadMenu();
    void manageMenu();
    bool isEmployeeIDUnique(int);
};

#endif
