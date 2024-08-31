/*create a base class account with data members accountNumber and balance.Derive two classese savingsaccount and checkingaccount from account.
implement polymorphic behaviour where the base class pointer can point to a objects of derived classes ,and call their respective member functions to deposit and withdraw money,
applying specific rules for each account type.*/

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

    void get_input()
    {
        cout << "Enter the account number: ";
        cin >> accountNumber;
    }

    void display(const string &type) const
    {
        cout << "Account Type: " << type << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Available Balance: " << balance << endl;
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
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        balance += amount;
        cout << "Amount was deposited successfully"<<endl;
    }

    void withdraw() override
    {
        float amount;
        cout << "Enter the amount to be withdrawn: ";
        cin >> amount;
        if (balance - amount >= 0)
        {
            balance -= amount;
            cout << "Amount was withdrawn successfully"<<endl;
        }
        else
        {
            cout << "Insufficient balance in your account"<<endl;
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
            cout << "Your account does not have enough balance\n";
        }
    }
};

int main()
{
    Account *Acc = nullptr;
    int choice;

    cout << "1. Savings Account"<<endl<<"2. Checking Account"<<endl<<"Enter your choice: "<<endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        Acc = new SavingsAccount();
        Acc->get_input();
        Acc->deposit();
        Acc->withdraw();
        Acc->display("Savings Account");
        break;
    case 2:
        Acc = new CheckingAccount();
        Acc->get_input();
        Acc->deposit();
        Acc->withdraw();
        Acc->display("Checking Account");
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    delete Acc;
    return 0;
}