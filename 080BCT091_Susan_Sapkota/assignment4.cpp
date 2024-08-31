/*
Create a base class Account with data members accountNumber and balance. Derive two classes SavingAccount and CheckingAccount
from Account. Implement polymorphic behavior where the base class pointer can point to objects of derived classes, and call 
their respective member functions to deposit and withdraw money,applying specific rules for each account type.
*/

#include <iostream>
#include <string>

using namespace std;

class Account
{
protected:
    int accountNumber;
    float balance;

public:
    Account(int a = 0, float b = 0.0) : accountNumber(a), balance(b) {}

    virtual void deposit() = 0;
    virtual void withdraw() = 0;

    void setdata()
    {
        cout << "Enter the account number: ";
        cin >> accountNumber;
        cout << "Enter the balance: ";
        cin >> balance;
    }

    void display(const string &type) 
    {
        cout << "Account Type: " << type << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int a = 0, float b = 0.0) : Account(a, b) {}

    void deposit() override
    {
        float amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully\n";
    }

    void withdraw() override
    {
        float amount;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (balance - amount >= 0)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int a = 0, float b = 0.0) : Account(a, b) {}

    void deposit() override
    {
        float amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully\n";
    }

    void withdraw() override
    {
        float amount;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (balance - amount >= 0)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
};

int main()
{
    Account *a = nullptr;
    int choice;

    cout << "1. Savings Account\n2. Checking Account\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        a = new SavingsAccount();
        a->setdata();
        a->deposit();
        a->withdraw();
        a->display("Savings Account");
        break;
    case 2:
        a = new CheckingAccount();
        a->setdata();
        a->deposit();
        a->withdraw();
        a->display("Checking Account");
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    delete a; // Free the allocated memory
    return 0;
}