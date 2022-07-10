//
// Created by cagin on 21.06.2022.
//


#include <iostream>
#include <string>
#include "LibrarySystem.h"

//#include "Book.h"
//#include "Student.h"
using namespace std;

//Constructor
LibrarySystem::LibrarySystem() {
    books = NULL;
    bookNum = 0;
    students = NULL;
    studentNum = 0;
}

LibrarySystem:: ~LibrarySystem() {
    if(books != NULL){
        delete[] books;
    }
    if(students != NULL){
        delete[] students;
    }
}

void LibrarySystem::addBook(const int bookId, const string name, const string authors, const int year) {
    for(int i = 0; i < bookNum; i++){
        if (books[i].getBookID() == bookId){
            cout << "Book "<< bookId << " already exist."<< endl;
            return;
        }
    }
    Book *temp = new Book[bookNum+1];
    for (int i = 0; i < bookNum; ++i) {
        temp[i] = books[i];
    }
    temp[bookNum] = Book(bookId,name,authors,year);
    delete[] books;
    books = temp;
    bookNum++;
    cout << "Book " << bookId << " has been added. "<< endl;
}
void LibrarySystem::deleteBook(const int bookId) {
    int isThere = 0;
    for(int i = 0; i < bookNum; i++){
        if(books[i].getBookID() == bookId){
            isThere = 1;
        }
    }

    if(!isThere){
        cout <<"Book " << bookId << " does not exist. "<< endl;
        return;
    }
    else {
        for(int i = 0; i < bookNum; i++){
            if(books[i].getBookID() == bookId){
                if(!books[i].getIsCheckedOut()){
                    cout <<"Book " << bookId << " has not been checked out. "<< endl;
                };
            }
        }
        returnBook(bookId);
        cout <<"Book " << bookId << " has been deleted. "<< endl;
    }

    Book *temp = new Book[bookNum-1];
    int newNum = 0;
    for(int i = 0; i < bookNum; i++){
        if(books[i].getBookID() != bookId){
             temp[newNum] = books[i];
             newNum++;
        }
    }
    delete[] books;
    books = temp;
    bookNum--;
}

void LibrarySystem::addStudent(const int studentId, const string name) {
    for(int i = 0; i < studentNum; i++){
        if (students[i].getStudentID() == studentId){
            cout << "Student "<< studentId << " already exist."<< endl;
            return;
        }
    }
    Student *temp = new Student[studentNum+1];
    for (int i = 0; i < studentNum; ++i) {
        temp[i] = students[i];
    }
    temp[studentNum] = Student(studentId,name);
    delete[] students;
    students = temp;
    studentNum++;
    cout << "Student " << studentId << " has been added. "<< endl;
}
void LibrarySystem::deleteStudent(const int studentId) {
    int isThere = 0;
    for(int i = 0; i < studentNum; i++){
        if(students[i].getStudentID() == studentId){
            isThere = 1;
        }
    }

    if(!isThere){
        cout <<"Student " << studentId << " does not exist. "<< endl;
        return;
    }
    else {
        for (int i = 0; i < studentNum; ++i) {
            Book *tempArray = students[i].getCheckedOutBooks();
            int size = students[i].getCheckedOutBookSize();
            if(students[i].getStudentID() == studentId){
                for (int j = 0; j < size; j++) {
                    returnBook(tempArray[j].getBookID());
                }
            }
        }
        cout <<"Student " << studentId << " has been deleted. "<< endl;
    }

    Student *temp = new Student[studentNum-1];
    int newNum = 0;
    for(int i = 0; i < studentNum; i++){
        if(students[i].getStudentID() != studentId){
            temp[newNum] = students[i];
            newNum++;
        }
    }
    delete[] students;
    students = temp;
    studentNum--;
}

Book* LibrarySystem::getBookByID(const int bookId) {
    for(int i = 0; i < bookNum; i++){
        if(bookId == books[i].getBookID()){
            return &books[i];
        }
    }
    return NULL;
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
    bool bookFlag = false;
    bool studentFlag = false;
    for(int i = 0; i < bookNum; i++){
        if(books[i].getBookID()==bookId){
            bookFlag = true;
        }
    }
    if(!bookFlag){
        cout << "Book " << bookId <<" does not exist for checkout." << endl;
        return;
    }
    /*if(tempBook.getBookID() == -1){
        cout << "Book " << bookId <<" is not in the system." << endl;
        return;
    }*/
    for(int i = 0; i < studentNum; i++){
        if(studentId == students[i].getStudentID()){
            if(!(*getBookByID(bookId)).getIsCheckedOut()){
                students[i].addBookToStudent((*getBookByID(bookId)));
                (*getBookByID(bookId)).setIsCheckedOut(true);
                cout << "Book "<< bookId <<" has been checked out by student "<< studentId << endl;
            }
            else{
                cout << "Book " << bookId <<"  has been already checked out by another student." << endl;
            }
            studentFlag = true;
        }
    }
    if(!studentFlag){
        cout << "Student " << studentId <<" does not exist for checkout." << endl;
    }
}

void LibrarySystem::returnBook(const int bookId) {
    bool flag = false;
    if(bookNum < 1){
        cout << "There are no book in library. " << endl;
    }
    else{
        for (int i = 0; i < studentNum; i++) {
            Book *tempArray = students[i].getCheckedOutBooks();
            for (int j = 0; j < students[i].getCheckedOutBookSize(); j++) {
                if(tempArray[j].getBookID() == bookId){
                    flag = true;
                    students[i].removeBookFromStudent(tempArray[j]);
                    getBookByID(bookId)->setIsCheckedOut(0);
                    //tempArray[j].setIsCheckedOut(0); // ŞELOW KOPİ
                }
            }
        }
        if(!flag){
            cout << "Book " << bookId << " has not been checked out." << endl;
        }
    }
}

void LibrarySystem::showAllBooks() {
    if(books == NULL){
        cout << "No books in there" << endl;
        return;
    }
    else{
        cout << "Book id " << "Name " << "Author " << "Year " << " Status " << endl;
        for(int i = 0; i < bookNum; i++){
            if(books[i].getIsCheckedOut() == 0){
                cout << books[i].getBookID() << books[i].getBookName() << books[i].getBookAuthors() << books[i].getBookYear() << "           Not checked out" << endl;
            }
            else{
                int bookID = books[i].getBookID();
                //cout << bookID << endl;
                for (int j = 0; j < studentNum; ++j) {
                    Book *tempArray = students[j].getCheckedOutBooks();
                    for (int k = 0; k < students[j].getCheckedOutBookSize(); ++k) {
                        if (tempArray[k].getBookID() == bookID){
                            cout << books[i].getBookID() << books[i].getBookName() << books[i].getBookAuthors() << books[i].getBookYear() << " Checked out by " << students[j].getStudentID() << endl;
                        }
                    }
                }
            }
        }
    }
}

void LibrarySystem::showBook(const int bookId) {
    int studentID;
    for (int i = 0; i < studentNum; i++) {
        Book *tempArray = students[i].getCheckedOutBooks();
        for (int j = 0; j < students[i].getCheckedOutBookSize(); j++) {
            if (tempArray[j].getBookID() == bookId){
                studentID = students[i].getStudentID();
            }
        }
    }
    for(int i = 0; i < bookNum; i++){
        if(books[i].getBookID() == bookId){
            if(books[i].getIsCheckedOut() == 0){
                cout << books[i].getBookID() << books[i].getBookName() << books[i].getBookAuthors() << books[i].getBookYear() << "           Not checked out" << endl;
            }
            else{

                cout << books[i].getBookID() << books[i].getBookName() << books[i].getBookAuthors() << books[i].getBookYear() << " Checked out by student " << studentID << endl;
            }
        }
    }

}

void LibrarySystem::showStudent(const int studentId) {
    for (int i = 0; i < studentNum; ++i) {
        if(students[i].getStudentID() == studentId){
            cout << "Student id: " << students[i].getStudentID() << " student name: " << students[i].getStudentName() << endl;
            students[i].showCheckedOutBookOfStudent(studentId);
            return;
        }
    }
    cout << "Student: " << studentId << " does not exist." << endl;
    return;
}

