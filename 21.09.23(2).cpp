#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string Name;
    int Number;
    double balance;

public:
    BankAccount(const string& name, int number, double initialBalance) {
        Name = name;
        Number = number;
        balance = initialBalance;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено на рахунок: " << amount << endl;
        }

    }
    void Withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Знято з рахунку:" << amount << endl;
        }
    }

    int GetBalance() {
        return balance;
    }

    void DisplayInfo() {
        cout << "Ім'я власника: " << Name << endl;
        cout << "Номер рахунку: " << Number << endl;
        cout << "Поточний баланс: " << balance << " грн" << endl;
    }
};

int main() {

    BankAccount account1("John", 12345, 1000.0);
    BankAccount account2("Jack", 54321, 500.0);
    account1.DisplayInfo();
    account2.DisplayInfo();
    account1.Deposit(500.0);
    account1.Withdraw(200.0);
    account2.Deposit(100.0);
    account2.Withdraw(800.0);
    account1.DisplayInfo();
    account2.DisplayInfo();
    return 0;
}
