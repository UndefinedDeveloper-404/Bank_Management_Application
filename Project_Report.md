# Bank Management Application – Project Report

## 1. Title
**Bank Management Application using C++**

## 2. Objective
The objective of this project is to design and implement a simple Bank Management Application using C++. The application demonstrates object-oriented programming and file handling by allowing customers to create accounts, log in, deposit money, withdraw money and check their balance.

## 3. Problem Statement
Manual management of customer banking records can be time-consuming and error-prone. This project provides a simple computerized system for maintaining customer account information and performing basic banking operations.

## 4. Technologies Used
- Programming Language: C++
- Concepts: OOP, Classes, Objects, Encapsulation, Constructors
- Storage: File handling using `ifstream` and `ofstream`
- Interface: Console-based menu

## 5. Main Features
### Account Creation
A customer can create an account by entering an account number, name, phone number, password and initial deposit.

### Customer Login
Customers authenticate using their account number and password.

### Deposit
The customer can add money to the existing account balance.

### Withdrawal
The customer can withdraw money only when the requested amount is valid and does not exceed the available balance.

### Balance Inquiry
The current account balance and basic customer information can be displayed.

### Persistent Storage
Account information is stored in `accounts.dat`, allowing records to remain available after the application is closed.

## 6. OOP Concepts
### Class
The project uses `Account` and `Bank` classes.

### Encapsulation
Account information such as account number, name, password and balance is private.

### Abstraction
Methods such as `deposit()`, `withdraw()`, `authenticate()` and `showBalance()` hide the internal implementation from the user.

### Constructor
The `Account` constructor initializes account details.

## 7. System Flow
Start
↓
Main Menu
↓
Create Account / Customer Login
↓
Authentication
↓
Customer Menu
↓
Deposit / Withdraw / Balance / Details
↓
Update File
↓
Logout
↓
Exit

## 8. File Handling
The application uses a text-based data file named `accounts.dat`. Each account is stored as a record containing account number, name, phone number, password and balance.

File operations used:
- `ofstream` – write account records
- `ifstream` – read account records
- Temporary file – update an existing record safely

## 9. Validation
The application checks:
- Duplicate account numbers
- Negative initial deposits
- Non-positive deposit amounts
- Invalid withdrawal amounts
- Withdrawal amounts greater than the balance
- Invalid login credentials

## 10. Expected Output
The system should successfully:
- Create and store customer accounts
- Authenticate customers
- Perform deposits
- Perform withdrawals
- Display balances
- Preserve records between program executions

## 11. Advantages
- Simple and easy to use
- Demonstrates core C++ OOP concepts
- Demonstrates file handling
- Maintains persistent customer records
- Reduces manual calculation errors

## 12. Limitations
- Console-based interface
- Single local data file
- No database server
- Password is stored as plain text for academic demonstration
- No advanced transaction history

## 13. Future Enhancements
- Add an admin module
- Add transaction history
- Use SQLite/MySQL database
- Hash passwords securely
- Add account transfer functionality
- Add interest calculation
- Add GUI
- Generate account statements
- Add stronger authentication

## 14. Conclusion
The Bank Management Application successfully demonstrates how C++ object-oriented programming and file handling can be combined to build a functional banking simulation. The system supports account creation, authentication, deposit, withdrawal and balance inquiry while maintaining persistent customer records.
