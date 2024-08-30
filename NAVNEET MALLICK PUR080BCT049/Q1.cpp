//Question Number 1
#include<iostream>
#include<string>
using namespace std;
class person
{
    private:
    string name;
    string dateofBirth;
public:
    person ()
    {}
    person (string Name,string DOB)
    {
       name=Name;
       dateofBirth=DOB;
    }

     void display()
     {

         cout<<"Name="<<name <<" "<<endl<< "Date of Birth="<<dateofBirth<<endl;
     }
     string getDOB()
     {
         return dateofBirth;
     }

};
int main()
{
    int i,n=4;
     person p[n] = {
        person("Mahesh Bhattarai", "2004-04-21"),
        person("Aakash Guragain", "2005-04-21"),
        person("Ramesh Khanal", "2005-04-28"),
        person("Saroj Pokharel", "2004-04-21")
    };

    string DOB;
    cout<<"Enter date of birth (YY-MM-DD)";
    cin>>DOB;
    bool found=false;
    cout<<"The information matched using DOB is "<<endl;
    for(i=0;i<n;i++)
    {
        if(p[i].getDOB()==DOB)
        {
            p[i].display();
            found=true;
        }
    }
    if(!found)
    {
        cout<<"Sorry! The Date of Birth doesn't match";
    }
    return 0;
}
