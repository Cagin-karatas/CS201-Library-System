//
// Created by cagin on 21.06.2022.
//

#include "Student.h"
#include <string>
using namespace std;
#include <iostream>

Student::Student() {
    studentID = -1;
    studentName = "";
    checkedOut = NULL;
    checkedOutBookSize = 0;
}

Student::Student(const int studentId, const string name) {
    this->studentID = studentId;
    this->studentName = name;
    checkedOut = NULL;
    checkedOutBookSize = 0;
}

int Student::getStudentID() {
    return studentID;
}

string Student::getStudentName() {
    return studentName;
}
Book* Student::getCheckedOutBooks() {
    return checkedOut;
}

int Student::getCheckedOutBookSize() {
    return checkedOutBookSize;
}

void Student::setStudentID(int newStudentID) {
    studentName = newStudentID;
}

void Student::setStudentName(string newStudentName) {
    studentName = newStudentName;
}
void Student::addBookToStudent(Book book) {
    checkedOutBookSize++;
    Book *temp;
    temp = new Book[checkedOutBookSize-1];
    for(int i = 0; i < checkedOutBookSize-1; i++){
        temp[i] = checkedOut[i];
    }
    //temp = checkedOut;
    if(checkedOutBookSize != 1){
        delete[] checkedOut;
    }
    checkedOut = new Book[checkedOutBookSize];
    if(checkedOutBookSize != 1){
        for(int i = 0; i < checkedOutBookSize-1; i++){
            checkedOut[i] = temp[i];
        }
    }
    checkedOut[checkedOutBookSize-1] = book; //? override yok
    delete[] temp;
    //burada segfault
}

void Student::showCheckedOutBookOfStudent(int studentID) {

    if(checkedOutBookSize == 0){
        cout << "Student " << studentID << " has no books"<< endl;
    }
    else{
        cout << "Student " << studentID << " has checked out the following books " << endl;
        cout << "Book id     " << "Book Name       " << "Authors        " << "         Year" << endl;
        for(int i = 0; i < checkedOutBookSize; i++){
            cout << checkedOut[i].getBookID() << "    " << checkedOut[i].getBookName() << "    " << checkedOut[i].getBookAuthors() << "      " << checkedOut[i].getBookYear() << endl;
        }
    }

}
void Student::removeBookFromStudent(Book book) {
    int index = 0;
    bool exist = false;
    for (int i = 0; i < checkedOutBookSize; ++i) {
        if (checkedOut[i].getBookID() == book.getBookID()){
            exist = true;
            index = i;
        }
    }
    if(!exist){
        cout << "Book " << book.getBookID() << " has not been checked out." << endl;
    }
    else{

        for (int i = index; i < checkedOutBookSize-1; ++i) {
            checkedOut[i] = checkedOut[i+1];
        }
        Book *temp = new Book[checkedOutBookSize-1];
        checkedOutBookSize--;
        for (int i = 0; i < checkedOutBookSize; ++i) {
            temp[i] = checkedOut[i];
        }
        cout << "Book " << book.getBookID() << " has been returned" << endl;
        delete[] checkedOut;
        checkedOut = temp;
    }
}
