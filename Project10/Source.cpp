#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};
Book::Book(const char* n)  
{

	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	pages = 0;
}

Book::Book(const char* n, int p):Book(n)
{
	pages = p;
}

void Book::Print()
{
	cout << " Name: " << name << " Pages: " << pages << endl;
}

Book::~Book()
{
	delete[]name;
}


class Student
{
	char* name;
	const double step;
	Book book; 
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);
	~Student();
	void Print();

};
Student::Student() :step(0), book(nullptr) {
	name = nullptr;
}
Student::Student(const char* n, double st, const char* bookName, int bookPages) :step(st), book(bookName, bookPages) 
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

Student::~Student()
{
	delete[]name;
}

void Student::Print()
{
	cout << " Name: " << name << " Step: " << step <<endl<<" Book: " << endl;
	book.Print();
}

int main()
{
	Student subj1("MyName", 1, "MyBookName", 20);
	subj1.Print();
}