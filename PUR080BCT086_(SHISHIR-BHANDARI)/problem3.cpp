/*Define a class Library with bookTitle, author, and numberOfCopies as datamembers.
Implement methods to add new books, issue books, and return books.Ensure that
the number of copies is appropriately updated for each operation.*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

class Book
{
    string title;
    string author;
    int numberOfCopies;

public:
    Book()
    {
        numberOfCopies = 0;
    }

    void getData()
    {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter number of copies: ";
        cin >> numberOfCopies;
        cin.ignore();
    }

    void showData()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Number of copies: " << numberOfCopies << endl;
    }

    void addBooks(int n)
    {
        numberOfCopies += n;
        cout << "Added " << n << " books successfully\n";
    }

    void issueBook()
    {
        if (numberOfCopies == 0)
        {
            cout << "Sorry, the book is currently unavailable." << endl;
        }
        else
        {
            numberOfCopies--;
            cout << "Book issued successfully\n";
        }
    }

    void returnBook()
    {
        numberOfCopies++;
        cout << "Book returned successfully\n";
    }

    string getTitle()
    {
        return title;
    }
};

class Library
{
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library()
    {
        bookCount = 0;
    }

    void addBook()
    {
        if (bookCount >= MAX_BOOKS)
        {
            cout << "Library is full. Cannot add more books.\n";
            return;
        }
        books[bookCount].getData();
        bookCount++;
        cout << "Book added to library successfully.\n";
    }

    void showAllBooks()
    {
        if (bookCount == 0)
        {
            cout << "No books available in the library.\n";
            return;
        }
        for (int i = 0; i < bookCount; i++)
        {
            books[i].showData();
            cout << endl;
        }
    }

    void issueBook()
    {
        string title;
        cout << "Enter the title of the book to issue: ";
        getline(cin, title);

        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getTitle() == title)
            {
                books[i].issueBook();
                return;
            }
        }
        cout << "Book not found in the library.\n";
    }

    void returnBook()
    {
        string title;
        cout << "Enter the title of the book to return: ";
        getline(cin, title);

        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getTitle() == title)
            {
                books[i].returnBook();
                return;
            }
        }
        cout << "Book not found in the library.\n";
    }
};

int main()
{
    Library library;
    int choice;

    while (true)
    {
        cout << "\nWelcome to the library" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Show All Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit\n"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.showAllBooks();
            break;
        case 3:
            library.issueBook();
            break;
        case 4:
            library.returnBook();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice, please try again.";
        }

        cout << "\nPress enter to continue...";
        cin.ignore();
    }

    return 0;
}
