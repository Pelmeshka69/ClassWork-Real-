#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class BankAccount {
private:
    string Name;
    int id;
    double balance;
    static int generateId() {
        static int nextId = 1;
        return nextId++;
    }


public:
    BankAccount(const string& name, double initialBalance) {
        Name = name;
        id = generateId();
        balance = initialBalance;
    }
    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Submitted to balance: " << amount << endl;
        }
        else {
            cout << "Error: The contribution amount must be greater than 0." << endl;
        }

    }
    void Withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn from the balance:" << amount << endl;
        }
        else {
            cout << "The withdrawal amount is too large." << endl;
        }
    }
    int GetBalance() {
        return balance;
    }
    void DisplayInfo() {
        cout << "Owner Name: " << Name << endl;
        cout << "Account number: " << id << endl;
        cout << "Current balance: " << balance << endl;
    }
};

int main() {
    srand(time(0));
    BankAccount account1("John", 1000.0);
    account1.DisplayInfo();
    account1.Deposit(500.0);
    account1.Withdraw(200.0);
    account1.DisplayInfo();
    BankAccount account2("Jack", 500.0);
    account2.DisplayInfo();
    account2.Deposit(100.0);
    account2.Withdraw(300.0);
    account2.DisplayInfo();

    return 0;
}
