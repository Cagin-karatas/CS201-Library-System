//
// Created by cagin on 21.06.2022.
//

#include "Book.h"
#include <string>
using namespace std;

Book::Book() {
    bookID = -1;
    bookName = "";
    bookAuthors = "";
    bookYear = -1;
    isCheckedOut = false;
}
Book::Book(const int bookId, const string name, const string authors, const int year) {
    this->bookID = bookId;
    this->bookName = name;
    this->bookAuthors = authors;
    this->bookYear = year;

}
int Book::getBookID() {
    return bookID;
}

string Book::getBookName() {
    return bookName;
}

string Book::getBookAuthors() {
    return bookAuthors;
}

int Book::getBookYear() {
    return bookYear;
}
bool Book::getIsCheckedOut(){
    return isCheckedOut;
}

void Book::setBookID(int newBookID) {
    bookID = newBookID;
}

void Book::setBookName(string newBookName) {
    bookName = newBookName;
}

void Book::setBookAuthors(string newBookAuthors) {
    bookAuthors = newBookAuthors;
}

void Book::setBookYear(int newBookYear) {
    bookYear = newBookYear;
}
void Book::setIsCheckedOut(bool newIsCheckedOut) {
    this->isCheckedOut = newIsCheckedOut;
}
