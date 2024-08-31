// Create a class person with name and DOB as data members. Ask the user to enter a date of birth and print all person name with a matched date of birth
#include <iostream>
#include <string>
using namespace std;

class DOB
{
    int day, month, year;

public:
    DOB()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    DOB(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void getDOB()
    {
        cout << "Enter the date of birth in: day month year format ";
        cin >> day >> month >> year;
    }

    void DisplayDOB() const
    {
        cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;
    }
    bool checkDOB(const DOB &dob) const
    {
        return (day == dob.day && month == dob.month);
    }
};

class Person
{
private:
    string name;
    DOB dob;
public:
    Person()
    {
        name = "";
    }
    Person(string n, DOB d) : name(n), dob(d)
    {
    }
    void getPerson()
    {
        cout << "Enter the name: ";
        cin >> name;
        dob.getDOB();
    }
    void DisplayPerson() const
    {
        cout << "Name: " << name << endl;
        dob.DisplayDOB();
    }
    bool checkPerson(const DOB &d) const
    {
        return dob.checkDOB(d);
    }
};

int main()
{
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    Person *p = new Person[n]; 
    for (int i = 0; i < n; i++)
    {
        p[i].getPerson();
    }
    DOB dob;
    cout << "\nTo search for the required date, ";
    dob.getDOB();

    cout << "\nPersons with matching DOB:\n";
    for (int i = 0; i < n; i++)
    {
        if (p[i].checkPerson(dob))
        {
            p[i].DisplayPerson();
        }
    }
    delete[] p; 
    return 0;
}