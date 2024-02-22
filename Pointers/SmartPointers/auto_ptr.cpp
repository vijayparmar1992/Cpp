/*
auto_ptr:
The auto_ptr smart pointer takes a raw pointer, wraps it, and ensures the memory pointed
by the raw pointer is released back whenever the auto_ptr object goes out of scope. At any
time, only one auto_ptr smart pointer can point to an object. Hence, whenever one
auto_ptr pointer is assigned to another auto_ptr pointer, the ownership gets transferred
to the auto_ptr instance that has received the assignment; the same happens when
an auto_ptr smart pointer is copied.
*/

/*
However, due to the following reasons, auto_ptr is deprecated in C++11 onward:
- An auto_ptr object can't be stored in an STL container
- The auto_ptr copy constructor will remove the ownership from the original
  source, that is, auto_ptr
- The auto_ptr copy assignment operator will remove the ownership from the
  original source, which is, auto_ptr
- The original intention of copy constructor and assignment operators are
  violated by auto_ptr as the auto_ptr copy constructor and assignment
  operators will remove the ownership of the source object from the right-hand
  side object and assign the ownership to the left-hand side object
*/

#include<iostream>
#include<exception>
using namespace std;

class Student
{

public:
	Student()
	{
		cout << "Student constructor" << endl;
	}

	void sayHello()
	{
		cout << "Hello!" << endl;
	}
	~Student()
	{
		cout << "Student de-structor" << endl;
	}
};

int main()
{
	auto_ptr<Student> ptr1(new Student());
	auto_ptr<Student> ptr2(new Student());

	ptr1->sayHello();
	ptr2->sayHello();

	ptr1 = ptr2; // ptr2 will get destry here
	cout << "Above statement will call destructor for object pointed by ptr2" << endl;

	// ptr2->sayHello(); // will result in core dump

	ptr1->sayHello();
	
	return 0; // destructor get call here
}
