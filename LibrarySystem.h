//
// Created by cagin on 21.06.2022.
//

#ifndef PROJECT111111111_LIBRARYSYSTEM_H
#define PROJECT111111111_LIBRARYSYSTEM_H


#include "Book.h"
#include "Student.h"

class LibrarySystem {
public :
    LibrarySystem () ;
    ~LibrarySystem();
    void addBook ( const int bookId , const string name , const string authors ,const int year ) ;
    void deleteBook ( const int bookId ) ;
    void addStudent ( const int studentId , const string name ) ;
    void deleteStudent ( const int studentId ) ;
    void checkoutBook ( const int bookId , const int studentId ) ;
    void returnBook ( const int bookId ) ;
    void showAllBooks () ;
    void showBook ( const int bookId ) ;
    void showStudent ( const int studentId ) ;
    Book *getBookByID(const int bookId);

private:
    int bookNum;
    int studentNum;
    Book *books;
    Student *students;
};

#endif //PROJECT111111111_LIBRARYSYSTEM_H
