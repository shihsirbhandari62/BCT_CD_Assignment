//Design a class Employee with id, name, and salary as data members.
// Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.
#include <iostream>
#include <string>
using namespace std;
class Employee
{
    int ID;
    string name;
    float salary;
    public:
    Employee()
    {
        ID = 0;
        name = "";
        salary = 0;
    }
    Employee(int i, string n, float s)
    {
        ID = i;
        name = n;
        salary = s;
    }
    void get_input()
    {
        cout << "Enter the Employee ID: ";
        cin >> ID;
        cout << "Enter the Employee name: ";
        cin >> name;
        cout << "Enter the salary of the Employee: ";
        cin >> salary;
    }
    void Displaydata() const
    {
        cout << "ID number: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    void check_salary(float s) const
    {
        if(salary > s)
        {
            Displaydata();
        }
    }
};

int main(){
    int n,i;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *e = new Employee[n];

    for(i = 0; i < n; i++)
    {
        e[i].get_input();
    }
    float s;
    cout << "Enter the salary to be scanned";
    cin >> s;
    cout << "\nThe employees who has the salary greater than " << s << ":\n";
    for(int i = 0; i < n; i++)
    {
        e[i].check_salary(s);
    }
    delete[] e;
    return 0;
}