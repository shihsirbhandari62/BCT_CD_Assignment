/*
design a class employee with id, name and salary as data members.
implement functions to input employee data and display employees 
who have a salary greater than a user specified amount.
*/
#include<iostream>
#include<string>
#define size 40
#define emp_size 3
using namespace std;

class employee
{
    int id;
    char name[size];
    float salary;
    public:
    void input()
    {
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter name: ";
        cin.ignore();
        cin.getline(name,size);
        cout<<"Enter salary: ";
        cin>>salary;

    }
    void display()
    {
        cout<<"\nId: "<<id;
        cout<<"\nName: "<<name;
        cout<<"\nSalary: "<<salary;
    }
    bool operator >(float threshold)
    {
        return (salary>threshold);
    }
};
int main()
{
    employee e[emp_size];
    float threshold=0.0;
    cout<<"Enter threshold salary: ";
    cin>>threshold;
    for(int i=0;i<emp_size;i++)
    {
        e[i].input();
    }
    cout<<"employees who have more than "<<threshold<<":";
    for(int i=0;i<emp_size;i++)
    {
        if(e[i]>threshold)
        {
        e[i].display();
        cout<<endl;
        }
    }
    return 0;
}
