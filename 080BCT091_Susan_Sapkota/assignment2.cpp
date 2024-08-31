/*Design a class Employee with id, name, and salary as data members. Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.*/

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
        cout << "Enter the ID: ";
        cin >> ID;
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the salary: ";
        cin >> salary;
    }
    void display() const
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    void check_salary(float s) const
    {
        if(salary > s)
        {
            display();
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *e = new Employee[n];

    for(int i = 0; i < n; i++)
    {
        e[i].get_input();
    }

    float s;
    cout << "Enter the salary to search: ";
    cin >> s;

    cout << "\nEmployees with salary greater than " << s << ":\n";
    for(int i = 0; i < n; i++)
    {
        e[i].check_salary(s);
    }

    delete[] e;

    return 0;
}