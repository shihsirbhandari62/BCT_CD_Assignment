/*
create a base class account with data members accountnumber and balance.
derive two classese savingsaccount and checkingaccount from account.
implement polymorphic behaviour where the base class pointer can point to a objects of derived classes ,
and call their respective member functions to deposit and withdraw money, applying specific rules for each account type.
*/

#include <iostream>
using namespace std;


class Account {
protected:
    int accountNumber;
    float balance;

public:

    Account(int acc, float bal) : accountNumber(acc), balance(bal) {}

    virtual void deposit(float amount) 
    {
        balance += amount;;
        cout<<"Deposited successfully!"<<endl;
    }

    virtual void withdraw(float amount) 
    {
        if (amount <= balance) 
        {
            balance -= amount;
            cout << "Withdrew successfully! "<< endl;
        } 
        else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayBalance() const 
    {
        cout << "Account Number: " << accountNumber<<endl;
        cout<< "Balance: Rs" << balance << endl;
    }

    virtual ~Account() {}
};


class SavingsAccount : public Account {
private:
    float Interest_rate;

public:

    SavingsAccount(int acc, double B, double rate) : Account(acc, B), Interest_rate(rate) {}


    void deposit(float amount) override 
    {
        float I = amount * Interest_rate / 100;
        balance += amount + I;
        cout << "Deposited Rs" << amount << " with Rs" <<I << " interest in saving account successfully! "<< endl;
    }


    void withdraw(float amount) override 
    {
        if (amount > balance) 
        {
            cout << "Insufficient balance!" << endl;
        } else 
        {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from  saving account successfully!"  << endl;
        }
    }


    void displayBalance() const override 
    {
        cout << "Savings ";
        Account::displayBalance();
    }
};


class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:

    CheckingAccount(int account, double B, double overdraft) : Account(account,B), overdraftLimit(overdraft) {}


    void withdraw(float amount) override 
    {
        if (amount > balance + overdraftLimit) 
        {
            cout << "Overdraft limit exceeded!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs" << amount << " from checking account successfully! "<< endl;
        }
    }


    void displayBalance() const override 
    {
        cout << "Checking ";
        Account::displayBalance();
    }
};

int main() {
    int Type;
    int account;
    double iBalance;
    double Irate;
    double overdraftLimit;
    double amount;

    Account* accountPtr = nullptr;

    cout << "\nWelcome to the Bank  Management System" << endl;
    cout << "Please choose account type:"<<endl;
    cout<<" 1. Savings Account"<<endl;
    cout<<" 2. Checking Account"<<endl;
    cout<<"Choose your account type:"<<endl;
    cin >> Type;

    cout << "Enter account number: ";
    cin >> account;

    cout << "Enter initial balance: ";
    cin >> iBalance;

    if (Type == 1) 
    {
        cout << "Enter interest rate (%): ";
        cin >> Irate;
        accountPtr = new SavingsAccount(account, iBalance, Irate);
    } else if (Type == 2) {
        cout << "Enter overdraft limit: ";
        cin >> overdraftLimit;
        accountPtr = new CheckingAccount(account, iBalance, overdraftLimit);
    } else {
        cout << "Invalid account type selected!" << endl;
        return 1;
    }

    char choice;
    while(1)
    {
    cout << "\nChoose an operation: " << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Display Balance" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case '1':
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accountPtr->deposit(amount);
            break;

        case '2':
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            accountPtr->withdraw(amount);
            break;

        case '3':
            accountPtr->displayBalance();
            break;

        case '4':
            cout << "Thank you!" << endl;
            exit(0);
            break;

            default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
    }
    delete accountPtr;
    return 0;
}
