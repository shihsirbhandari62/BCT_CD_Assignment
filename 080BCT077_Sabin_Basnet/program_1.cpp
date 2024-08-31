/*Create a class person with name and date of birth as data members.
Ask the user to enter a date of birth and print all persons name with a matched date of birth.*/


#include<iostream>
using namespace std;
int count=0;

class person
{
    char name[30];
    int year;
    int month;
    int day;
    public:
    person(){}
    person(int d,int m,int y){
        day=d;
        month=m;
        year=y;
    }
    void input()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"enter DOB (dd/mm/yr):";
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"Name of the person with the given date of birth: \n"<<name<<endl;
    }
    bool operator==(person &p)
    {
        if((year==p.year)&&(month==p.month)&&(day==p.day))
        {
            ::count=1;
            return true;
        }
        else
            return false;
    }
};
int main()
{
    int n,d,m,y;
    cout<<"Enter number of persons: ";
    cin>>n;
    person p[100];
    for(int i=0;i<n;i++)
    {
        p[i].input();
    }
    cout<<"enter the date of birth to search:"<<endl;
    cin>>d>>m>>y;
    person a(d,m,y);
    for(int i=0;i<n;i++)
    {
        if(a==p[i]){
            cout<<"Match is found\n";
            p[i].display();
        }
    }
    if(::count!=1){
        cout<<"No match found\n";
    }
    return 0;
}
