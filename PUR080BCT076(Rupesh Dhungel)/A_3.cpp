/*
define a class library with booktitle,  author, and numberofcopies as data members.
implement methods to add new books,issue books and return books.ensure that the number of copies is
appropriately updated for each operation.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library
{
    string title;
    string author;
    int no_of_copies;

public:
    Library() : title(""), author(""), no_of_copies(0) {}
    
    Library(string t, string a, int c) : title(t), author(a), no_of_copies(c) {}
   

    void addNewBook()
    {
        cout << "Enter the book title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Enter the author: ";
        getline(cin, author);
        cout << "Enter the number of copies: ";
        cin >> no_of_copies;
    }

    void issueBook()
    {
        if (no_of_copies > 0)
        {
            no_of_copies--;
            cout << "Book issued successfully"<<endl;
        }
        else
        {
            cout << "Book not available"<<endl;
        }
    }

    void returnBook()
    {
        no_of_copies++;
        cout << "Book returned successfully"<<endl;
    }

    void display() const
    {
        cout << "Title: " << title <<endl;
        cout<< "Author: " << author <<endl;
        cout<<  "No. of Copies: " << no_of_copies << endl;
    }

    string returnTitle() const
    {
        return title;
    }
};

int main()
{
    vector<Library> library;
    int choice;
    int flag;
    while(1)
    {cout << "\nEnter your choice: "<<endl;
    cout << "1. Add Book"<<endl;
    cout<<"2. Issue Book"<<endl;
    cout<<"3. Return Book"<<endl;
    cout<<"4. Display All Books "<<endl;
    cout<<"5. Exit"<<endl;
      
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            Library L1;
            L1.addNewBook();
            library.push_back(L1);
            cout << "Book added successfully!"<<endl;
            break;
        }
        case 2:
        {
            string title;
            flag=0;
            cout << "Enter the book title to issue: ";
            cin.ignore();
            getline(cin, title);

            for (auto &L2 : library)
            {
                if (L2.returnTitle() == title)
                {
                    flag=1;
                    L2.issueBook();
                    break;
                }
            }
            if(flag==0)
            {
                cout << "Book not found!"<<endl;
            }

        }
        case 3:
        {
            string title;
            flag=0;
            cout << "Enter the book title to return: ";
            cin.ignore(); 
            getline(cin, title);

           
            for (auto &L2 : library)
            {
                if (L2.returnTitle() == title)
                {
                    flag=1;
                    L2.returnBook();
                    break;
                }  
            }
             if(flag==0)
            {
                cout << "Book not found!"<<endl;
            }

            break;
        }
        case 4:
            cout <<endl<< "Displaying all books:"<<endl;
            for (const auto &L : library)
            {
                L.display();
            }
            break;
        case 5:
            cout << "Thank you!";
            exit(0);
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    }
    return 0;
}
