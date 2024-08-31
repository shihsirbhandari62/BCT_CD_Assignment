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
    void getInput()
    {
        if(count!=1)
        {
        cout<<"Enter name: ";
        cin>>name;
        }
        cout<<"enter dob(dd/mm/yr)BS:";
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"Name of the person with the given date of birth: "<<name<<endl;
    }
    bool operator==(person &P)
    {
        if((year==P.year)&&(month==P.month)&&(day==P.day))
        {
            cout<<"The match is found"<<endl;
            P.display();
        }
        else
            cout<<"No match found"<<endl;
    }
};
int main()
{
    int num;
    cout<<"Enter number of persons: ";
    cin>>num;
    person P1[num],P2;
    for(int i=0;i<num;i++)
    {
        P1[i].getInput();
    }
    count=1;
    cout<<"enter the date of birth to search:"<<endl;
    P2.getInput();

    for(int i=0;i<num;i++)
    {
        P2==P1[i];
    }
    return 0;
}
