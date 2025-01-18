#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
public:
    void takeOrder();         // Take a new order
    void displayOrders();     // Display all orders
    void reserveTable();      // Reserve a table
    void cancelOrder();       // Cancel an order or reservation
    void billingAndPayment(); // Handle billing and payment
};

#endif // EMPLOYEE_H
