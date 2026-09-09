 #include<bits/stdc++.h>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    double price;
    int quantity;

    
    public :
    static int total_records;

    Book() {
        title = "UNKNOWN";
        author = "UNKNOWN";
        publisher = "UNKNOWN";
        price = 0.0;
        quantity = 0;
    }

    void addBook() {
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Author Name: ";
        cin >> author;
        cout << "Enter Publisher: ";
        cin >> publisher;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
        total_records++;
    }

    void displayBook() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void updateBook() {
        cout << "Enter new Book Title: ";
        cin >> title;
        cout << "Enter new Author Name: ";
        cin >> author;
        cout << "Enter new Publisher: ";
        cin >> publisher;
        cout << "Enter new Price: ";
        cin >> price;
        cout << "Enter new Quantity: ";
        cin >> quantity;
    }

    void sellBook() {
        int sellQuantity;
        cout << "Enter Quantity to Sell: ";
        cin >> sellQuantity;
        if (sellQuantity <= quantity) {
            quantity -= sellQuantity;
            cout << "Sold " << sellQuantity << " copies of " << title << endl;
        } 
        else {
            cout << "Insufficient stock to sell " << sellQuantity << " copies." << endl;
        }
    }

    friend void searchBook( Book [] , string title , string purpose ) ;
    friend void displayAllBooks( Book [] ) ;
};

void displayAllBooks( Book books[] ) {
    cout << "Total Records: " << Book::total_records << endl;
    cout << "title\tAuthor\tPublisher\tPrice\tQuantity" << endl;
    for (int i = 0; i < Book::total_records; i++) {
         
        cout << books[i].title << "\t" << books[i].author << "\t" << books[i].publisher << "\tRs" << books[i].price << "\t" << books[i].quantity << endl;
    }
}


void searchBook( Book books[], string title , string purpose ) {
    int flag = 0;
    for (int i = 0; i < Book::total_records; i++) {
        if (books[i].title == title) {
            if (purpose == "sell") {
                books[i].sellBook();
            }
             else if (purpose == "update") {
                books[i].updateBook();
            }
            else if (purpose == "display") {
                books[i].displayBook();
            }
            flag = 1 ;
            return;
        }
    }
    if (flag == 0) {
        cout << "Book not found." << endl;
    }
    return ;
}

int Book::total_records = 0;

int main() {
    Book books[100];
    int choice;
    do {
        cout << "1. Add Book" << endl;
        cout << "2. Display Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Sell Book" << endl;
        cout << "5.Display All Books" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                int i = Book::total_records;
                books[i].addBook();
                break;
            }
            case 2: {
                string title;
                cout << "Enter Book Title to Display: ";
                cin >> title;
                searchBook(books, title, "display");
                break;
            }
            case 3: {
                string title;
                cout << "Enter Book Title to Update: ";
                cin >> title;
                searchBook(books, title, "update");
                break;
            }
            case 4: {
                string title;
                cout << "Enter Book Title to Sell: ";
                cin >> title;
                searchBook(books, title, "sell");
                break;
            }
            case 5: {
                displayAllBooks(books);
                break;
            }
            case 6:{
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}