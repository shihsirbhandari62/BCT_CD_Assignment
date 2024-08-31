/*Design a class Employee with id, name, and salary as data members.
Implement functions to input employee data and display employees who have a salary greater than a user-specified amount.*/

#include<iostream>
#include<string>
using namespace std;

class Employee
{
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getInput()
    {
        cout<<"Enter the ID:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the name:";
        getline(cin,name);
        cout<<"Enter the salary:";
        cin>>salary;
    }
    void show()
    {
        cout << "ID: " << id <<endl;
        cout<<"Name: " << name <<endl;
        cout<< "Salary: " << salary << endl;
    }
    float returnsalary()
    {
        return salary;
    }
};
int main()
{
    int num,i;
    int flag=0;
    cout<<"No of employee:"<<endl;
    cin>>num;
    Employee* E = new Employee[num];
    
    for(i=0;i<num;i++)
    {
    cout<<"Enter employee id,name and salary: "<<endl;
    E[i].getInput();
    cout<<endl;
    }

    float money;
    cout<<"Enter the amount to be compared:";
    cin>>money;
    cout<<"Employees having salary greater than the entered amount is"<<":"<<endl;
    
    for(i=0;i<num;i++)
    {
        if(E[i].returnsalary()>money)
        {
            flag=1;
            E[i].show();  
        }
    }
    if(flag==0)
        cout<<"Employee not Found"<<endl;
    delete[] E;
    return 0;
}