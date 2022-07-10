//
// Created by cagin on 21.06.2022.
//

#ifndef PROJECT111111111_BOOK_H
#define PROJECT111111111_BOOK_H


using namespace std;
#include <string>

class Book {
public:
    Book();
    Book(const int bookId, const string name, const string authors, const int year);

    //getters
    int getBookID();
    string getBookName();
    string getBookAuthors();
    int getBookYear();
    bool getIsCheckedOut();

    //setters
    void setBookID(int newBookID);
    void setBookName(string newBookName);
    void setBookAuthors(string newBookAuthors);
    void setBookYear(int newBookYear);
    void setIsCheckedOut(bool newIsCheckedOut);

private:
    int bookID;
    string bookName;
    string bookAuthors;
    int bookYear;
    bool isCheckedOut;
};


#endif //PROJECT111111111_BOOK_H
