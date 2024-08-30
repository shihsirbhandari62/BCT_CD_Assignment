//Question number 2
#include<iostream>
#include<string>
using namespace std;
class Employee
{
    private:
    int id;
    string name;
    float salary;
public:
   Employee()
    {}
    void getinfo()
    {
        cout<<"Enter the ID:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the name:";
        getline(cin,name);
        cout<<"Enter the salary:";
        cin>>salary;
    }
    void showinfo()
    {
        cout << "ID: " << id <<endl<< ", Name: " << name <<endl<< ", Salary: " << salary << endl;
    }
    float getsalary()
    {
        return salary;
    }
};
int main()
{
    int n,i;
    cout<<"how many employees?"<<endl;
    cin>>n;
    Employee* e = new Employee[n];
    for(i=0;i<n;i++)
    {
    cout<<"Please enter the data for Employee "<<(i+1)<<endl;
    e[i].getinfo();
    cout<<endl;
    }
    float amount;
    cout<<"Enter the required amount to be compared";
    cin>>amount;
    cout<<"Employees having salary greater than "<<amount<<":"<<endl;
    bool found=false;
    for(i=0;i<n;i++)
    {
        if(e[i].getsalary()>amount)
        {
            e[i].showinfo();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"The Employee having salary greater than"<<amount<<" not found.";
    }
    delete[] e;
    return 0;
}
