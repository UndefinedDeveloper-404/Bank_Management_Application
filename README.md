# Bank Management Application

## Project Description
A C++ console-based Bank Management Application that demonstrates object-oriented programming and file handling.

## Features
- Create a bank account
- Customer login using account number and password
- Deposit money
- Withdraw money
- Check balance
- View customer details
- Persistent storage using file handling
- Basic input validation
- Encapsulation using classes

## OOP Concepts Used
1. **Class and Object** – `Account` and `Bank`
2. **Encapsulation** – account data is private and accessed through member functions
3. **Abstraction** – banking operations are provided through simple methods
4. **Constructors** – used to initialize account objects
5. **Modularity** – account management and bank operations are separated

## File Handling
Customer records are stored in `accounts.dat`. The data remains available after the application is closed and restarted.

## Compile and Run

### Windows / MinGW
```bash
g++ main.cpp -o BankManagement.exe
BankManagement.exe
```

### Linux / macOS
```bash
g++ main.cpp -o BankManagement
./BankManagement
```

## Test Flow
1. Select `1. Create Account`
2. Enter account number, name, phone, password and initial deposit.
3. Select `2. Customer Login`.
4. Enter the same account number and password.
5. Test:
   - Deposit
   - Withdraw
   - Balance
   - Customer Details
6. Exit and reopen the program.
7. Login again to verify that the account data was saved.

## Sample Test Data
Account Number: 1001
Name: Arun Kumar
Phone: 9876543210
Password: 1234
Initial Deposit: 5000

Expected:
- Deposit 1000 -> balance 6000
- Withdraw 1500 -> balance 4500
- Balance inquiry -> Rs. 4500

## Important Note
This is an academic simulation, not production banking software. Passwords are stored in the local data file for demonstration of file handling. A real banking system must use secure password hashing, encryption, authorization, transaction logging, database storage, and stronger validation.
