hw1: main.o LibrarySystem.o Student.o Book.o
	g++ main.o LibrarySystem.o Student.o Book.o -o hw1
 
main.o: main.cpp
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

LibrarySystem.o: LibrarySystem.cpp LibrarySystem.h
	g++ -c LibrarySystem.cpp