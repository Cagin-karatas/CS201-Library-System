//
// Created by cagin on 21.06.2022.
//

#ifndef PROJECT111111111_STUDENT_H
#define PROJECT111111111_STUDENT_H
using namespace std;
#include <string>
#include "Book.h"

class Student {
public:

    Student();
    Student(const int studentId , const string name);

    //getters
    int getStudentID();
    string getStudentName();
    Book* getCheckedOutBooks();
    int findBookOfStudentID();
    int getCheckedOutBookSize();

    //setters
    void setStudentID(int newStudentID);
    void setStudentName(string newStudentName);
    void addBookToStudent(Book book);
    void removeBookFromStudent(Book book);
    void showCheckedOutBookOfStudent(int studentID);

private:
    int studentID;
    int numOfBooks;
    string studentName;
    Book *checkedOut;
    int checkedOutBookSize;
    };


#endif //PROJECT111111111_STUDENT_H
