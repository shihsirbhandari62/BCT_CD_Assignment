/*Create a class person with name and date of birth as data members. Ask the user to
enter a date of birth and print all persons name with a matched date of birth.*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
    string name;
    int year, month, day;

public:
    void getData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter date of birth (yyyy mm dd): ";
        cin >> year >> month >> day;
    }

    void showData()
    {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << year << "/" << month << "/" << day << endl;
    }

    bool hasBirthday(int y, int m, int d)
    {
        return (year == y && month == m && day == d);
    }
};

int main()
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    Person *persons = new Person[n];

    cout << "Enter the data of " << n << " persons:" << endl;
    for (int i = 0; i < n; ++i)
    {
        persons[i].getData();
    }

    int sYear, sMonth, sDay;
    cout << "Enter a date of birth to search (yyyy mm dd): ";
    cin >> sYear >> sMonth >> sDay;

    bool found = false;
    cout << "Matching dates:" << endl;
    for (int i = 0; i < n; ++i)
    {
        if (persons[i].hasBirthday(sYear, sMonth, sDay))
        {
            persons[i].showData();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No match found." << endl;
    }

    delete[] persons;
    return 0;
}
