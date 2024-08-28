/*
create a base class account with data members accountnumber and balance.
derive two classese savingsaccount and checkingaccount from account.
implement polymorphic behaviour where the base class pointer can point to a objects of derived classes ,
and call their respective member functions to deposit and withdraw money, applying specific rules for each account type.
*/
#include <iostream>
using namespace std;
class Account
{

    int accno;

protected:
    float balance;

public:
    void input()
    {
        cout << "Enter Account Number: ";
        cin >> accno;
        cout << "Enter Balance: ";
        cin >> balance;
    }
    void display()
    {
        cout << "Account Number: " << accno << endl;
        cout<<"Balance:"<<balance<<endl;
    }
    virtual void deposit(float amount) = 0;
    virtual void withdraw(float amount) = 0;
};
class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(const string& msg) : runtime_error(msg) {}
};
class InvalidAmountException : public runtime_error {
public:
    InvalidAmountException(const string& msg) : runtime_error(msg) {}
};

class SavingsAccount : public Account
{
    void deposit(float amount)
    {
        if (amount <= 10)
        {
           throw  InvalidAmountException("amount should be more than 10.");

        }
        else
        {
            Account::balance += amount;
            cout << "deposit successfully done." << endl;
        }
    }
    void withdraw(float amount)
    {
        if(amount>balance)
        throw InsufficientFundsException("Insufficient funds for withdrawal.");
        else if (amount <= 100)
        {
            throw InvalidAmountException("amount should be more than 100");
        }
        else if (amount >= 100000)
        throw InvalidAmountException("limit reached of 100k");
        else
        {
            Account::balance -= amount;
            cout << "withdraw successfully done." << endl;
        }
    }
};
class checkingAccount : public Account
{
public:
    void deposit(float amount)
    {
        if (amount <= 10)
        {
            throw  InvalidAmountException("amount should be more than 10.");

        }
        else
        {
            Account::balance += amount;
            cout << "deposit successfully done." << endl;
        }
    }
    void withdraw(float amount)
    {
        if(amount>balance)
        throw InsufficientFundsException("Insufficient funds for withdrawal.");
        else if (amount <= 10)
        {
            throw InvalidAmountException("amount should be more 10");
        }
        else if (amount >= 50000)
            throw InvalidAmountException("amount should be more than 50k");
        else
        {
            Account::balance -= amount;
            cout << "withdraw successfully done." << endl;
        }
    }
};
int main()
{
    int size = 2;
    int choice;
    float amount;
    Account *ptr[size];
    ptr[0] = new SavingsAccount;
    ptr[1] = new checkingAccount;
    cout<<"enter the details for saving account:"<<endl;
    ptr[0]->input();
    cout<<"enter the details for checking account:"<<endl;
    ptr[1]->input();
    while (true)
    {
        cout << "1.Deposit\n2.Withdraw\n3.Display\n4.Exit\n";
        cin >> choice;
        try{
        switch (choice)
        {
        case 1:
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            cout << "select account type:\n1.savings account\n2.checking account" << endl;
            cin >> choice;
            if(choice==1 || choice==2)
            ptr[choice-1]->deposit(amount);
            else
            cout << "Invalid choice" << endl;
            break;
        case 2:
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            cout << "select account type:\n1.savings account\n2.checking account" << endl;
            cin >> choice;
            if(choice==1 || choice==2)
            ptr[choice-1]->withdraw(amount);
            else
            cout << "Invalid choice" << endl;
            break;
        case 3:
            cout << "select account type:\n1.savings account\n2.checking account" << endl;
            cin >> choice;
            if(choice==1 || choice==2)
            ptr[choice-1]->display();
            else
            cout << "Invalid choice" << endl;
            break;
        
        case 4:
            delete ptr[0];
            delete ptr[1];
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }}catch(InvalidAmountException& e)
        {
            cout<<"error:"<<e.what()<<endl;
        }
        catch(InsufficientFundsException& e)
        {
            cout<<"error:"<<e.what()<<endl;
        }
    }
}
