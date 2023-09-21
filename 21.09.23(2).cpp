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
    double prevBalance;
    static int generateId() {
        static int nextId = 1;
        return nextId++;
    }

public:
    BankAccount(const string& name, double initialBalance) {
        Name = name;
        id = generateId();
        balance = initialBalance;
        prevBalance = initialBalance; 
    }

    void Deposit(double amount) {
        if (amount > 0) {
            prevBalance = balance; 
            balance += amount;
            cout << "Deposited into account #" << id << ": " << amount << endl;
        }
        else {
            cout << "Error: The deposit amount must be greater than 0." << endl;
        }
    }

    void Withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            prevBalance = balance; 
            balance -= amount;
            cout << "Withdrawn from account #" << id << ": " << amount << endl;
        }
        else {
            cout << "Error: The withdrawal amount is invalid." << endl;
        }
    }

    int GetBalance() {
        return balance;
    }

    void DisplayInfo() {
        if (prevBalance != balance) {
            cout << "Account Owner: " << Name << endl;
            cout << "Account Number: " << id << endl;
            cout << "Previous Balance: " << prevBalance << endl;
            cout << "Current Balance: " << balance << endl;
            cout << endl;
        }

        prevBalance = balance;
    }

    int GetId() {
        return id;
    }
};

class Banks {
private:
    string Name;
    BankAccount* users[10];

public:
    Banks(const string& name) {
        Name = name;

        string names[10] = { "Anna", "Bogdan", "Victor", "Hanna", "Dmitry", "Eugene", "Zoya", "Ivan", "Katerina", "Leo" };
        for (int i = 0; i < 10; i++) {
            int nameIndex = rand() % 10;
            double balance = rand() % 10000 + 100;
            users[i] = new BankAccount(names[nameIndex], balance);
        }
    }

    ~Banks() {
        for (int i = 0; i < 10; i++) {
            delete users[i];
        }
    }

    void Transfer(int fromId, int toId, double amount) {

        BankAccount* fromAccount = nullptr;
        BankAccount* toAccount = nullptr;
        for (int i = 0; i < 10; i++) {
            if (users[i]->GetId() == fromId) {
                fromAccount = users[i];
            }
            if (users[i]->GetId() == toId) {
                toAccount = users[i];
            }
        }

        if (fromAccount == nullptr || toAccount == nullptr) {
            cout << "Error: One or both of the accounts do not exist." << endl;
            return;
        }
        if (amount <= 0) {
            cout << "Error: The transfer amount must be positive." << endl;
            return;
        }

        fromAccount->Withdraw(amount);
        toAccount->Deposit(amount);

        fromAccount->DisplayInfo();
        toAccount->DisplayInfo();
    }

};

int main() {
    srand(time(0));

    Banks monobank("Monobank");

    cout << "Accounts Before Transfer:" << endl;
    for (int i = 0; i < 10; ++i) {
        monobank.Transfer(1, 2, rand() % 1000); 
    }

    return 0;
}

