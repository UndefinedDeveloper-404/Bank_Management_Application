#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>


using namespace std;

class Account {
private:
    long long accountNumber;
    string name;
    string phone;
    string password;
    double balance;

public:
    Account() : accountNumber(0), balance(0.0) {}

    Account(long long accNo, const string& n, const string& p,
            const string& pass, double bal = 0.0)
        : accountNumber(accNo), name(n), phone(p), password(pass), balance(bal) {}

    long long getAccountNumber() const { return accountNumber; }
    string getName() const { return name; }
    double getBalance() const { return balance; }

    bool authenticate(const string& pass) const {
        return password == pass;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance)
            return false;
        balance -= amount;
        return true;
    }

    void save(ofstream& file) const {
        file << accountNumber << '|'
             << name << '|'
             << phone << '|'
             << password << '|'
             << fixed << setprecision(2) << balance << '\n';
    }

    static bool load(ifstream& file, Account& acc) {
        string line;
        if (!getline(file, line))
            return false;

        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        size_t p3 = line.find('|', p2 + 1);
        size_t p4 = line.find('|', p3 + 1);

        if (p1 == string::npos || p2 == string::npos ||
            p3 == string::npos || p4 == string::npos)
            return false;

        try {
            acc.accountNumber = stoll(line.substr(0, p1));
            acc.name = line.substr(p1 + 1, p2 - p1 - 1);
            acc.phone = line.substr(p2 + 1, p3 - p2 - 1);
            acc.password = line.substr(p3 + 1, p4 - p3 - 1);
            acc.balance = stod(line.substr(p4 + 1));
        } catch (...) {
            return false;
        }

        return true;
    }
};

class Bank {
private:
    const string filename = "accounts.dat";

    bool findAccount(long long accountNo, Account& result) const {
        ifstream file(filename);
        Account acc;

        while (Account::load(file, acc)) {
            if (acc.getAccountNumber() == accountNo) {
                result = acc;
                return true;
            }
        }
        return false;
    }

    bool accountExists(long long accountNo) const {
        Account temp;
        return findAccount(accountNo, temp);
    }

    void saveAllAccounts(const Account* updatedAccount = nullptr) {
        ifstream input(filename);
        ofstream temp("accounts.tmp");

        Account acc;
        while (Account::load(input, acc)) {
            if (updatedAccount &&
                acc.getAccountNumber() == updatedAccount->getAccountNumber()) {
                acc = *updatedAccount;
            }
            acc.save(temp);
        }

        input.close();
        temp.close();

        remove(filename.c_str());
        rename("accounts.tmp", filename.c_str());
    }

public:
    void createAccount() {
        long long accNo;
        string name, phone, password;
        double initialDeposit;

        cout << "\n--- Create Account ---\n";

        cout << "Enter account number: ";
        cin >> accNo;

        if (accountExists(accNo)) {
            cout << "Account already exists.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter customer name: ";
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        cout << "Create password: ";
        getline(cin, password);

        cout << "Enter initial deposit: ";
        cin >> initialDeposit;

        if (initialDeposit < 0) {
            cout << "Initial deposit cannot be negative.\n";
            return;
        }

        Account acc(accNo, name, phone, password, initialDeposit);

        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error opening database file.\n";
            return;
        }

        acc.save(file);
        file.close();

        cout << "Account created successfully.\n";
    }

    bool login(long long& loggedInAccountNo) {
        long long accNo;
        string password;

        cout << "\n--- Customer Login ---\n";
        cout << "Account number: ";
        cin >> accNo;

        cout << "Password: ";
        cin >> password;

        Account acc;
        if (findAccount(accNo, acc) && acc.authenticate(password)) {
            loggedInAccountNo = accNo;
            cout << "Login successful. Welcome, " << acc.getName() << "!\n";
            return true;
        }

        cout << "Invalid account number or password.\n";
        return false;
    }

    void depositMoney(long long accNo) {
        Account acc;
        if (!findAccount(accNo, acc)) {
            cout << "Account not found.\n";
            return;
        }

        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;

        if (amount <= 0) {
            cout << "Amount must be greater than zero.\n";
            return;
        }

        acc.deposit(amount);
        saveAllAccounts(&acc);

        cout << fixed << setprecision(2);
        cout << "Deposit successful. New balance: Rs. " << acc.getBalance() << '\n';
    }

    void withdrawMoney(long long accNo) {
        Account acc;
        if (!findAccount(accNo, acc)) {
            cout << "Account not found.\n";
            return;
        }

        double amount;
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if (!acc.withdraw(amount)) {
            cout << "Withdrawal failed. Check amount or available balance.\n";
            return;
        }

        saveAllAccounts(&acc);

        cout << fixed << setprecision(2);
        cout << "Withdrawal successful. New balance: Rs. "
             << acc.getBalance() << '\n';
    }

    void showBalance(long long accNo) {
        Account acc;
        if (!findAccount(accNo, acc)) {
            cout << "Account not found.\n";
            return;
        }

        cout << fixed << setprecision(2);
        cout << "\nAccount Number: " << acc.getAccountNumber() << '\n';
        cout << "Customer Name : " << acc.getName() << '\n';
        cout << "Balance       : Rs. " << acc.getBalance() << '\n';
    }

    void showCustomerDetails(long long accNo) {
        Account acc;
        if (!findAccount(accNo, acc)) {
            cout << "Account not found.\n";
            return;
        }

        cout << "\n--- Customer Details ---\n";
        cout << "Account Number: " << acc.getAccountNumber() << '\n';
        cout << "Name          : " << acc.getName() << '\n';
        cout << "Balance       : Rs. "
             << fixed << setprecision(2) << acc.getBalance() << '\n';
    }

    void customerMenu(long long accNo) {
        int choice;

        do {
            cout << "\n==============================\n";
            cout << "       CUSTOMER MENU\n";
            cout << "==============================\n";
            cout << "1. Deposit Money\n";
            cout << "2. Withdraw Money\n";
            cout << "3. Check Balance\n";
            cout << "4. Customer Details\n";
            cout << "5. Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    depositMoney(accNo);
                    break;
                case 2:
                    withdrawMoney(accNo);
                    break;
                case 3:
                    showBalance(accNo);
                    break;
                case 4:
                    showCustomerDetails(accNo);
                    break;
                case 5:
                    cout << "Logged out successfully.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 5);
    }

    void run() {
        int choice;

        do {
            cout << "\n====================================\n";
            cout << "       BANK MANAGEMENT SYSTEM\n";
            cout << "====================================\n";
            cout << "1. Create Account\n";
            cout << "2. Customer Login\n";
            cout << "3. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;

                case 2: {
                    long long accNo;
                    if (login(accNo))
                        customerMenu(accNo);
                    break;
                }

                case 3:
                    cout << "Thank you for using the Bank Management System.\n";
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main() {
    Bank bank;
    bank.run();
    return 0;
}
