#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    string isbn;
    string title;
    string author;
    string category;
    string availability;

    // Add a new book
    void addBook()
    {
        cout << "Enter ISBN: ";
        cin >> isbn;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        cout << "Enter Category: ";
        getline(cin, category);

        availability = "Available";
    }

    // Display book details
    void display()
    {
        cout << "\nISBN: " << isbn;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nCategory: " << category;
        cout << "\nAvailability: " << availability << endl;
    }
};

// Add book to file
void addBook()
{
    Book b;
    b.addBook();

    ofstream file("library.txt", ios::app);

    file << b.isbn << "|"
         << b.title << "|"
         << b.author << "|"
         << b.category << "|"
         << b.availability << endl;

    file.close();

    cout << "\nBook added successfully!\n";
}

// Search book
void searchBook()
{
    string isbn;
    cout << "Enter ISBN to search: ";
    cin >> isbn;

    ifstream file("library.txt");
    Book b;
    bool found = false;

    while (getline(file, b.isbn, '|') &&
           getline(file, b.title, '|') &&
           getline(file, b.author, '|') &&
           getline(file, b.category, '|') &&
           getline(file, b.availability))
    {
        if (b.isbn == isbn)
        {
            b.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "\nBook not found!\n";
}

// Issue book
void issueBook()
{
    string isbn;
    cout << "Enter ISBN to issue: ";
    cin >> isbn;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    Book b;
    bool found = false;

    while (getline(file, b.isbn, '|') &&
           getline(file, b.title, '|') &&
           getline(file, b.author, '|') &&
           getline(file, b.category, '|') &&
           getline(file, b.availability))
    {
        if (b.isbn == isbn)
        {
            found = true;

            if (b.availability == "Available")
            {
                b.availability = "Issued";
                cout << "\nBook issued successfully!\n";
            }
            else
            {
                cout << "\nBook is already issued!\n";
            }
        }

        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Return book
void returnBook()
{
    string isbn;
    cout << "Enter ISBN to return: ";
    cin >> isbn;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    Book b;
    bool found = false;

    while (getline(file, b.isbn, '|') &&
           getline(file, b.title, '|') &&
           getline(file, b.author, '|') &&
           getline(file, b.category, '|') &&
           getline(file, b.availability))
    {
        if (b.isbn == isbn)
        {
            found = true;

            if (b.availability == "Issued")
            {
                b.availability = "Available";
                cout << "\nBook returned successfully!\n";
            }
            else
            {
                cout << "\nBook is already available!\n";
            }
        }

        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Update book details
void updateBook()
{
    string isbn;
    cout << "Enter ISBN to update: ";
    cin >> isbn;

    ifstream file("library.txt");
    ofstream temp("temp.txt");

    Book b;
    bool found = false;

    while (getline(file, b.isbn, '|') &&
           getline(file, b.title, '|') &&
           getline(file, b.author, '|') &&
           getline(file, b.category, '|') &&
           getline(file, b.availability))
    {
        if (b.isbn == isbn)
        {
            found = true;

            cin.ignore();

            cout << "Enter new title: ";
            getline(cin, b.title);

            cout << "Enter new author: ";
            getline(cin, b.author);

            cout << "Enter new category: ";
            getline(cin, b.category);

            cout << "\nBook updated successfully!\n";
        }

        temp << b.isbn << "|"
             << b.title << "|"
             << b.author << "|"
             << b.category << "|"
             << b.availability << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (!found)
        cout << "\nBook not found!\n";
}

// Availability report
void availabilityReport()
{
    ifstream file("library.txt");

    Book b;
    int available = 0;
    int issued = 0;

    cout << "\n===== AVAILABILITY REPORT =====\n";

    while (getline(file, b.isbn, '|') &&
           getline(file, b.title, '|') &&
           getline(file, b.author, '|') &&
           getline(file, b.category, '|') &&
           getline(file, b.availability))
    {
        b.display();

        if (b.availability == "Available")
            available++;
        else
            issued++;
    }

    file.close();

    cout << "\nTotal Available Books: " << available;
    cout << "\nTotal Issued Books: " << issued << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Search Book";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Update Book";
        cout << "\n6. Availability Report";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            searchBook();
            break;

        case 3:
            issueBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            updateBook();
            break;

        case 6:
            availabilityReport();
            break;

        case 7:
            cout << "\nExiting program...";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 7);

    return 0;
}
