/*
define a class library with booktitle,  author, and numberofcopies as data members.
implement methods to add new books,issue books and return books.ensure that the number of copies is
appropriately updated for each operation.
*/
#include <iostream>
#include<cstring>
using namespace std;
#define size 30
int book_varient = 0;
int mirror=0;
class library
{
    char booktitle[size], author[size];
    int numcp;

public:
    library() 
    {
        strcpy(this->booktitle, "");
        strcpy(this->author, "");
        this->numcp = 0;
    }
    void add_new_books(bool askauthor=true)
    {
        if(askauthor)
        {
        cout << "enter the name of author:";
        cin >> author; 
        }
        cout << "enter the number of copies:";
        int n;
        cin >> n;
        numcp+=n;
    }
    string gettitle()
    {
        return booktitle;
    }
    void inputtitle(const char* intitle)
    {
        strcpy(booktitle,intitle);
    }
    void issuebook()
    {
        if (numcp == 0)
        {
            cout << "book not available"<<endl;
        }
        else
        {
            int n;
            cout << "enter the no of books to be issued:";
            cin >> n;
            if (n > numcp)
            {
                cout << "limited books available"<<endl;
            }
            else
            {
                numcp -= n;
                cout << "book issued"<<endl;
            }
        }
    }
    void return_book() 
    {
        int n;
        cout <<endl<< "enter the no of books to be returned:";
        cin >> n;
        numcp += n;
        cout << "book returned";
    }
    bool new_booktitle_check(library lib[100])
    {
        char booktitle[size];
        cout << "enter the book title:";
        cin >> booktitle;
        for (int i = 0; i <= book_varient; i++)
        {
            if (strcmp(booktitle, lib[i].gettitle().c_str()) == 0)
            {
                mirror=i;
                return true;
            }
        }
         lib[book_varient].inputtitle(booktitle); 
        return false; 
    }
};
int main()
{
    library lib[100];
    while (true)
    {
        int choice;
        cout << "library management system"<<endl
             << "1. add new books" <<endl
             << "2. issue books " << endl
             << "3. return book" << endl
             << "4. exit"<<endl
             << "enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if(lib[book_varient].new_booktitle_check(lib)) 
            {
                cout << "book already exists" << endl;
               lib[mirror].add_new_books(false);
            }
            else
            {
                lib[book_varient].add_new_books(true);
                book_varient++;
            }
            break;
        case 2:
            if(lib[book_varient].new_booktitle_check(lib)) 
            {
                lib[mirror].issuebook();
            }
            else
            {
                cout << "book not found" << endl;
            }
            break;
        case 3:
            if(lib[book_varient].new_booktitle_check(lib)) 
            {
                lib[mirror].return_book();
            }
            else
            {
                cout << "book not found" << endl;
            }
            break;
            case 4:
            exit(0);
        default:
            cout << "invalid choice" << endl;
            cout << "confirm" << endl
                 << "yes\t\t no"<<endl;
            break;
        }
    }
    return 0;
}
