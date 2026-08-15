# 🏦 Bank Management Application

A simple **C++ based Bank Management Application** that simulates core banking operations using **Object-Oriented Programming (OOP)** and **File Handling**.

## 📌 Project Overview

The Bank Management Application is a console-based banking system developed in C++. It allows customers to create accounts, securely log in, deposit money, withdraw money, check their balance, and view account details.

Customer records are stored in a local file so that the data remains available even after the application is closed.

## ✨ Features

* 🏦 Create a new bank account
* 🔐 Customer login authentication
* 💰 Deposit money
* 💸 Withdraw money
* 💳 Check account balance
* 👤 View customer details
* 💾 Persistent customer data using file handling
* 🛡️ Input validation
* 📦 Object-Oriented Programming implementation
* 🖥️ Simple console-based interface

## 🧠 OOP Concepts Used

The project demonstrates several important C++ concepts:

### 1. Classes and Objects

The application uses classes such as:

* `Account`
* `Bank`

### 2. Encapsulation

Customer information such as:

* Account number
* Name
* Phone number
* Password
* Balance

is kept private inside the `Account` class.

### 3. Abstraction

Banking operations are implemented through simple functions such as:

```cpp
deposit()
withdraw()
authenticate()
showBalance()
```

### 4. Constructors

Constructors are used to initialize customer account information.

## 💾 File Handling

The application uses C++ file handling to maintain persistent customer records.

The following file operations are used:

* `ifstream` – Reading customer records
* `ofstream` – Writing customer records
* Temporary file – Updating existing account records

Customer information is stored in:

```text
accounts.dat
```

This allows account information to remain available when the program is restarted.

## 🔄 Application Flow

```text
                ┌─────────────────────┐
                │       Start         │
                └──────────┬──────────┘
                           ↓
                ┌─────────────────────┐
                │     Main Menu       │
                └──────────┬──────────┘
                           ↓
              ┌────────────┴────────────┐
              ↓                         ↓
       Create Account              Customer Login
              ↓                         ↓
       Save Account                 Authenticate
              │                         ↓
              │                  Customer Menu
              │                         ↓
              │       ┌─────────────────┼─────────────────┐
              │       ↓                 ↓                 ↓
              │    Deposit           Withdraw          Balance
              │       ↓                 ↓                 ↓
              │       └─────────────────┼─────────────────┘
              │                         ↓
              │                    Update File
              │                         ↓
              └────────────────────── Logout
                                        ↓
                                       Exit
```

## 🛠️ Technologies Used

| Technology        | Purpose                     |
| ----------------- | --------------------------- |
| **C++**           | Main programming language   |
| **OOP**           | Application structure       |
| **File Handling** | Persistent customer records |
| **MSVC / MinGW**  | C++ compiler                |
| **Visual Studio** | Development environment     |

## 📂 Project Structure

```text
Bank-Management-Application/
│
├── main.cpp
├── README.md
├── Project_Report.md
└── accounts.dat
```

> `accounts.dat` is generated automatically when the application creates its first account.

## ▶️ How to Run

### Using Visual Studio

1. Open **Visual Studio**.
2. Create a **C++ Console Application**.
3. Add `main.cpp` to the project.
4. Build the project.
5. Run the application.

### Using Command Prompt / Terminal

If using MinGW:

```bash
g++ main.cpp -o BankManagement.exe
BankManagement.exe
```

If using MSVC Developer Command Prompt:

```bash
cl main.cpp
main.exe
```

## 🧪 Test Example

### Create Account

```text
Account Number: 1001
Name: Arun Kumar
Phone: 9876543210
Password: 1234
Initial Deposit: 5000
```

### Deposit

```text
Deposit Amount: 1000
New Balance: Rs. 6000.00
```

### Withdrawal

```text
Withdrawal Amount: 1500
New Balance: Rs. 4500.00
```

### Balance Check

```text
Account Number: 1001
Customer Name: Arun Kumar
Balance: Rs. 4500.00
```

## 📋 Input Validation

The application validates:

* Duplicate account numbers
* Negative initial deposits
* Invalid deposit amounts
* Invalid withdrawal amounts
* Withdrawal greater than available balance
* Incorrect login credentials

## 🎯 Expected Outcome

The completed system provides a functional banking simulation capable of:

* Creating customer accounts
* Authenticating customers
* Performing deposits
* Performing withdrawals
* Checking balances
* Maintaining persistent customer records

## 🔮 Future Enhancements

Possible improvements include:

* 🧑‍💼 Admin login
* 📜 Transaction history
* 💳 Fund transfer between accounts
* 🏧 ATM-style interface
* 🗄️ MySQL / SQLite database
* 🔐 Secure password hashing
* 📄 Account statement generation
* 🖥️ Graphical User Interface
* 📊 Transaction reports

## ⚠️ Security Note

This project is intended for **academic and educational purposes**.

The current implementation stores passwords locally for demonstrating C++ file handling. A real banking application should use:

* Password hashing
* Encryption
* Secure authentication
* Database transactions
* Access control
* Audit logging
* Secure communication

## 📸 Screenshots

### Main Menu
![Main Menu](screenshots/main-menu.png)

### Create Account
![Create Account](screenshots/create-account.png)

### Customer Login
![Customer Login](screenshots/login.png)

### Deposit
![Deposit](screenshots/deposit.png)

### Withdrawal
![Withdrawal](screenshots/withdrawal.png)

### Balance Check
![Balance Check](screenshots/balance.png)

### Logout
![Logout](screenshots/logout.png).

## 👨‍💻 Project Type

**Academic C++ Mini Project**

**Domain:** Banking / Financial Management

**Language:** C++

**Concepts:** OOP + File Handling

## 📜 License

This project is created for educational purposes. You are free to use and modify it for learning and academic submissions.
