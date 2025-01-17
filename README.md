# Restaurant Management System

## Table of Contents

1. [Project Overview](#project-overview)
2. [Admin Functionality](#admin-functionality)
3. [Employee Functionality](#employee-functionality)
4. [Customer Functionality](#customer-functionality)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Contributing](#contributing)
8. [License](#license)

---

## Project Overview

The **Restaurant Management System** is built with C++ using **Object-Oriented Programming** concepts to create a robust and easy-to-manage software solution for restaurant operations. The system allows users to choose their role (Admin, Employee, or Customer) and interact with the restaurant in various ways depending on the role.

### Core Components:
- **Login System**: A prompt allows users to select their role (Admin, Employee, or Customer). The login process uses a simple authentication mechanism for Admin.
- **Admin Panel**: Admins have the ability to manage employees, menu items, and monitor restaurant operations.
- **Employee Panel**: Employees can take orders, manage reservations, and handle customer interactions.
- **Customer Panel**: Customers can place orders, pay bills, and leave feedback, interacting with the system in a simplified way.

---

## Admin Functionality

The **Admin** has full access to the system, and their functionality includes:

1. **Login**: Admin must enter the correct password to gain access to the system.
2. **Manage Employees**: Admin can add, view, and remove employees.
3. **Manage Menu**: Admin can add new items to the menu, modify existing items, or delete items.
---

## Employee Functionality

The **Employee** can perform the following tasks:

1. **Login**: Employees log in with their credentials.
2. **Take Orders**: Employees can take customer orders from the menu and track the status of orders.
3. **Table Reservations**: Employees can manage table reservations (reserve or cancel tables).
4. **Order Management**: Employees can view and update orders, including canceling them or modifying order status.
5. **Billing and Payments**: Employees manage billing, process payments, and generate receipts for customers.

---

## Customer Functionality

The **Customer** role allows customers to interact with the system in the following ways:

1. **Login**: Customers can log in to the system for a personalized experience.
2. **Place Order**: Customers can select items from the menu and place orders.
3. **Reserve Table**: Customers can reserve tables ahead of time for a given time slot.
4. **Pay Bill**: After dining, customers can view and pay their bills.
5. **Provide Feedback**: Customers can leave feedback about their experience at the restaurant.

---

## Installation

### Prerequisites:
- **C++ Compiler**: Any standard C++ compiler (e.g., **GCC** or **Visual Studio**).
- **IDE/Text Editor**: Any C++ IDE (e.g., **Code::Blocks**, **Visual Studio**, **CLion**) or text editor (e.g., **VSCode**).

### Steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Restaurant-Management-System.git
   ```

2. Navigate to the project directory:
   ```bash
   cd Restaurant_Management_System
   ```

3. Compile the project:
   ```bash
   g++ main.cpp admin.cpp employee.cpp customer.cpp login.cpp user_panels.cpp -o restaurant_management_system
   ```

4. Run the program:
   ```bash
   ./restaurant_management_system
   ```

---

## Usage

After running the program, the system will prompt users to log in by selecting one of the following roles:
- **Admin**: Will have access to the Admin Panel to manage employees, menus, orders, and view reports.
- **Employee**: Will be able to take orders, manage reservations, handle billing, and interact with customers.
- **Customer**: Can place orders, make reservations, pay bills, and provide feedback.

Each role has a set of options in their respective panels, and the system will continue to prompt for actions until the user logs out.

---

## Contributing

Contributions are welcome to improve the **Restaurant Management System**! To contribute:

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature-branch`).
3. Implement your changes.
4. Commit your changes (`git commit -m "Add new feature"`).
5. Push to your forked repository (`git push origin feature-branch`).
6. Open a pull request.

---
