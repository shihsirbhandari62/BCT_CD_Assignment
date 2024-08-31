/*
Define a class LIbrary with bookTitl,author, and numberOfCopies as data members. Implement methods to add new books,
issue books,and return books. Ensure that the number of copies is appropriately updated for each operation.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Library
{
    string bookTitle;
    string author;
    int numberOfCopies;

public:
    Library()
    {
        bookTitle = "";
        author = "";
        numberOfCopies = 0;
    }
    Library(string b, string a, int n)
    {
        bookTitle = b;
        author = a;
        numberOfCopies = n;
    }

    void addBook()
    {
        cout << "Enter the book title: ";
        cin.ignore(); // To ignore the newline left by the previous input
        getline(cin, bookTitle);
        cout << "Enter the author: ";
        getline(cin, author);
        cout << "Enter the number of copies: ";
        cin >> numberOfCopies;
    }

    void issueBook()
    {
        if (numberOfCopies > 0)
        {
            numberOfCopies--;
            cout << "Book issued successfully\n";
        }
        else
        {
            cout << "Book not available\n";
        }
    }

    void returnBook()
    {
        numberOfCopies++;
        cout << "Book returned successfully\n";
    }

    void display() const
    {
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
        cout << "Number of Copies: " << numberOfCopies << endl;
    }

    string getTitle() const
    {
        return bookTitle;
    }
};

int main()
{
    vector<Library> library;
    int choice;

    do
    {
        cout << "\n1. Add Book\n2. Issue Book\n3. Return Book\n4. Display All Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Library newBook;
            newBook.addBook();
            library.push_back(newBook);
            cout << "Book added successfully\n";
            break;
        }
        case 2:
        {
            string title;
            cout << "Enter the book title to issue: ";
            cin.ignore(); // To ignore the newline left by the previous input
            getline(cin, title);

            bool found = false;
            for (auto &book : library)
            {
                if (book.getTitle() == title)
                {
                    book.issueBook();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found\n";
            }
            break;
        }
        case 3:
        {
            string title;
            cout << "Enter the book title to return: ";
            cin.ignore(); // To ignore the newline left by the previous input
            getline(cin, title);

            bool found = false;
            for (auto &book : library)
            {
                if (book.getTitle() == title)
                {
                    book.returnBook();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found\n";
            }
            break;
        }
        case 4:
            cout << "\nDisplaying all books:\n";
            for (const auto &book : library)
            {
                book.display();
            }
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}