#include <iostream>
#include <string>
#include <sstream>
using namespace std;





struct Book {
    string name;
    string author;
    int year;
    int countPages;
    string genre;
};

struct Library {
    int year;
    string address;
    string name;
    string owner;
    int maxCustomers;
};

void inputBook(Book& b) {
    cout << "Name: ";
    getline(cin >> ws, b.name);
    cout << "Author: ";
    getline(cin >> ws, b.author);
    cout << "Year: ";
    cin >> b.year;
    cout << "Pages: ";
    cin >> b.countPages;
    cout << "Genre: ";
    getline(cin >> ws, b.genre);
}

void printbook(const Book& b, int index) {
    cout << "\nBook #" << index + 1 << endl;
    cout << "Name: " << b.name << endl;
    cout << "Author: " << b.author << endl;
    cout << "Year: " << b.year << endl;
    cout << "Pages: " << b.countPages << endl;
    cout << "Genre: " << b.genre << endl;
}

void printAll(const Book books[], int count) {
    if (count == 0) {
        cout << "Library is empty.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        printbook(books[i], i);
    }
}

void search(const Book books[], int count, const string& title) {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (books[i].name == title) {
            printbook(books[i], i);
            found = true;
        }
    }
    if (!found)
        cout << "No book with that name found.\n";
}

void sort(Book books[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (books[j].year > books[j + 1].year) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    cout << "Books sorted by year.\n";
}

void edit(Book books[], int count) {
    int index;
    cout << "Enter book index (1-" << count << "): ";
    cin >> index;

    if (index >= 1 && index <= count) {
        inputBook(books[index - 1]);
        cout << "Book updated.\n";
    }
    else {
        cout << "Invalid index.\n";
    }
}

void deletebook(Book books[], int& count) {
    string title;
    cout << "Enter book name to delete: ";
    getline(cin >> ws, title);

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].name == title) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    for (int i = index; i < count - 1; i++) {
        books[i] = books[i + 1];
    }

    count--;
    cout << "Book deleted.\n";
}

void main() {
    const int MAX_BOOKS = 10;
    Book books[MAX_BOOKS];
    int count = 0;

    while (true) {
       
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search by Name\n";
        cout << "4. Sort by Year\n";
        cout << "5. Edit Book\n";
        cout << "6. Delete Book\n";


        int choice;
        cin >> choice;

        if (choice == 1) {
            if (count < MAX_BOOKS) {
                inputBook(books[count]);
                count++;
                cout << "Book added\n";
            }
            else {
                cout << "Library full\n";
            }
        }
        else if (choice == 2) {
            printAll(books, count);
        }
        else if (choice == 3) {
            string title;
            cout << "Enter book name: ";
            getline(cin >> ws, title);
            search(books, count, title);
        }
        else if (choice == 4) {
            sort(books, count);
        }
        else if (choice == 5) {
            edit(books, count);
        }
        else if (choice == 6) {
            deletebook(books, count);
        }

    }
}
