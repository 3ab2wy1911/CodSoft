#include <bits/stdc++.h>
#include "sqlite/sqlite3.h"
using namespace std;
/*
TASK 5
LIBRARY MANAGEMENT SYSTEM
 10 / 9 / 2023
A system to manage books, borrowers, and
transactions in a library
 */

//________________________________________________________________
class manager{
public:
    manager()= default;
    static void display (){
        int input = 1;
        while (input){
            cout << "Welcome to LIBRARY MANAGEMENT SYSTEM :)\n";
            cout << "Please Enter a choice :\n";
            cout << "0.Exit\n1. Administrator\n2.Customer\n";
            cin >>input;
            if (input == 1) {
                admin_display();
            }
            else if (input == 2) {
                customer_display();
            }
            cout << "___________________________________________________________________________________________________\n";
        }
        cout << "Thanks for using LIBRARY MANAGEMENT SYSTEM \n";
    }
    //----------------------------------------------------------------
    // insert the book to the database
    static void insert_book(int book_id, const string& title, const string& author, const string& isbn, double price, const string& status){
        sqlite3* db;
        sqlite3_open("Library.db", &db);
        string sql = "INSERT INTO books (book_id, title, author, ISBN, price, status) VALUES (" +
                     to_string(book_id) + ", '" + title + "', '" + author + "', '" + isbn + "', " +
                     to_string(price) + ", '" + status + "');";
        sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
    };
    //----------------------------------------------------------------
    static void delete_book(int book_id) {
        sqlite3* db;
        sqlite3_open("Library.db", &db);
        string check_sql = "SELECT 1 FROM books WHERE book_id = " + to_string(book_id) + ";";
        sqlite3_stmt* check_stmt;

        if (sqlite3_prepare_v2(db, check_sql.c_str(), -1, &check_stmt, nullptr) == SQLITE_OK) {
            if (sqlite3_step(check_stmt) == SQLITE_ROW) {
                string sql = "DELETE FROM books WHERE book_id = " + to_string(book_id) + ";";
                if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr) == SQLITE_OK) {
                    cout << "Book with ID " << book_id << " has been deleted." << endl;
                } else {
                    cerr << "Error deleting book: " << sqlite3_errmsg(db) << endl;
                }
            } else {
                cout << "Book with ID " << book_id << " does not exist in the library." << endl;
            }

            sqlite3_finalize(check_stmt);
        } else {
            cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) << endl;
        }

        sqlite3_close(db);
    }
    //----------------------------------------------------------------
    static void update_book(int id , const string& status){  // update the book from available to unavailable.
        sqlite3* db;
        sqlite3_open("Library.db", &db);
        string sql = "UPDATE books SET status = \'" +status+ " \' WHERE book_id = " + to_string(id) + ";\"";
        sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
        sqlite3_close(db);
    };
    //----------------------------------------------------------------
    static void print_books(){ // to display all books.
        sqlite3* db;
        sqlite3_stmt* stmt;
        sqlite3_open("Library.db", &db);
        string sql = "SELECT book_id, title, author, isbn, price, status FROM books;";

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            cout << "Books in the library:" << endl;
            cout<<"----------------------------------------------------------------\n";
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                int bookId = sqlite3_column_int(stmt, 0);
                const char* title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                const char* author = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                const char* isbn = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
                double price = sqlite3_column_double(stmt, 4);
                const char* status = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

                // Print book information
                cout << "Book ID: " << bookId << endl;
                cout << "Title: " << title << endl;
                cout << "Author: " << author << endl;
                cout << "ISBN: " << isbn << endl;
                cout << "Price: $" << price << endl;
                cout << "Status: " << status << endl;
                cout<<"-------------------------------------------------------------------------------------------------\n";
                cout << endl;
            }

            sqlite3_finalize(stmt);
        }
        else {
            cerr << "Error preparing SQL statement: " << sqlite3_errmsg(db) <<endl;
        }
        cout << "___________________________________________________________________________________________________\n";
        sqlite3_close(db);
    }
    //----------------------------------------------------------------
    static void check_out(int book_id){
        double customer_balance;
        sqlite3* db;
        sqlite3_open("Library.db", &db);
        string sql = "SELECT price FROM books WHERE book_id = " + to_string(book_id) + "\" AND status = 'Available';\";";
        sqlite3_stmt* stmt;
        double book_price;

        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                book_price = sqlite3_column_double(stmt, 0);
                cout << "The book price is " << book_price << endl;
                cout << "Please enter the money amount";
                cin>>customer_balance;
                if (customer_balance >= book_price) {
                    update_book(book_id, "Unavailable");

                    cout << "----------------------------------------------------------------\n";
                    cout << "Book with ID " << book_id << " has been checked out." << endl;
                    cout << "Amount paid: " << customer_balance << endl;
                    cout << "Book price is " << book_price << endl;
                    cout << "Reminder: " << customer_balance - book_price << endl;
                    cout << "----------------------------------------------------------------\n";
                }
                else {
                    cout << "Insufficient balance to check out the book." << endl;
                }
            }
            else {
                cout << "Book with ID " << book_id << " is not available." << endl;
            }

            sqlite3_finalize(stmt);
        }
        else {
            cout<<"Book is not available:(\n";
        }

        cout << "___________________________________________________________________________________________________\n";

        sqlite3_close(db);
    }
    //----------------------------------------------------------------
    static void admin_display() {
        int input =1;
        while(input){
            cout << "Welcome our Administrator!" << endl;
            cout << "Choose an option to do :\n";
            cout << "1.Insert a new book\n2.Remove book.\n0.Exit\n";
            cin >> input;
            if(input == 1){
                string title,isbn,author,status;
                double price;
                int id;
                cout<<"Please enter book title:";
                cin.ignore();
                getline(cin,title);
                cout<<"Please enter book author:";
                getline(cin,author);
                cout<<"Please enter book id:";
                cin >> id;
                cout<<"Please enter book isbn:";
                cin >> isbn;
                cout<<"Please enter book price:";
                cin >> price;
                insert_book(id,title,author,isbn,price,"Available");
            }

            else if (input == 2){
                print_books();
                int id;
                cout << "Please enter book id:";
                cin >>id;
                delete_book(id);
            }
            cout << "___________________________________________________________________________________________________\n";
        }

    };
    //----------------------------------------------------------------
    static void customer_display(){    // customer menu display.
        string name;
        int input = 1;
        //----------------------------------------------------------------
        while (input){
            int book_id =1;
            cout << "Welcome our Dear Customer :)\n";
            cout << "Please enter your Choice :" << endl;
            cout << "1.Borrow a Book\n2.Return a Book\n0.Exit!\n";
            cin>> input;
            //----------------------------------------------------------------
            if(input == 1){
                print_books();
                cout <<"Please enter the id of the book you want to buy :" << endl;
                cin>>book_id;
                check_out(book_id);
            }
            //----------------------------------------------------------------
            else if(input == 2){
                cout << "Please Enter the id of your Book :" << endl;
                cin>> book_id;
                update_book(book_id,"Available");
                cout<<"Thanks for returning the Book\n";
            }
            //-----------------------------------------------------------------
            cout << "___________________________________________________________________________________________________\n";
        }

    }
    //----------------------------------------------------------------
};





int main() {

    // Open the database and add the tables to the database if not existing.
    sqlite3* db;
    sqlite3_open("Library.db", &db);
    sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS books (book_id INTEGER PRIMARY KEY AUTOINCREMENT, title TEXT NOT NULL, author TEXT, isbn TEXT NOT NULL, price REAL NOT NULL, status TEXT NOT NULL);",nullptr,nullptr,nullptr);

    // Calling the main display function of the Program
    manager::display();

}
