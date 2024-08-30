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
    int copies;

public:
    Library() : title(""), author(""), copies(0) {}
    
    Library(string t, string a, int c) : title(t), author(a), copies(c) {}
   

    void addBook()
    {
        cout << "Enter the book title: ";
        cin.ignore(); 
        getline(cin, title);
        cout << "Enter the author: ";
        getline(cin, author);
        cout << "Enter the number of copies: ";
        cin >> copies;
    }

    void issueBook()
    {
        if (copies > 0)
        {
            copies--;
            cout << "Book issued successfully"<<endl;
        }
        else
        {
            cout << "Book not available"<<endl;
        }
    }

    void returnBook()
    {
        copies++;
        cout << "Book returned successfully"<<endl;
    }

    void display() const
    {
        cout << "Title: " << title <<endl<<
         "Author: " << author <<endl<<
          "Copies: " << copies << endl;
    }

    string getTitle() const
    {
        return title;
    }
};

int main()
{
    vector<Library> library;
    int choice;

    
    cout << "Enter your choice: "<<endl;
    cout << "1. Add Book"<<endl<<
    "2. Issue Book"<<endl<<
    "3. Return Book"<<endl<<
    "4. Display All Books "<<endl<<
    "5. Exit"<<endl;
      
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            Library newBook;
            newBook.addBook();
            library.push_back(newBook);
            cout << "Book added successfully!";
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter the book title to issue: ";
            cin.ignore();
            getline(cin, title);

            for (auto &book : library)
            {
                if (book.getTitle() == title)
                {
                    book.issueBook();
                    break;
                }
                else
                {
                    cout << "Book not found!";
                    break;
                }

            }
        }
        case 3:
        {
            string title;
            cout << "Enter the book title to return: ";
            cin.ignore(); 
            getline(cin, title);

           
            for (auto &book : library)
            {
                if (book.getTitle() == title)
                {
                    book.returnBook();
                    break;
                }
                 else
                {
                    cout << "Book not found!";
                    break;
                }
            }
            break;
        }
        case 4:
            cout <<endl<< "Displaying all books:"<<endl;
            for (const auto &book : library)
            {
                book.display();
            }
            break;
        case 5:
            cout << "Thank you!";
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    return 0;
}

