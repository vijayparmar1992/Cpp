/*
shared_ptr:
- he shared_ptr smart pointer is used when a group of shared_ptr objects shares the
ownership of a heap-allocated object.
- The shared_ptr pointer releases the shared object
when all the shared_ptr instances are done with the use of the shared object.
- The shared_ptr pointer uses the reference counting mechanism to check the total references to
the shared object; whenever the reference count becomes zero, the last shared_ptr
instance deletes the shared object.
*/

#include<iostream>
#include<exception>
#include<vector>
using namespace std;

class Student
{
	string name;
	static int count;

public:
	Student(string n)
	{
		count++;
		name = n;
		cout << "constructor" << " from "<< name << endl;
	}

	void sayHello()
	{
		cout << "Hello "<< " from "<< name << endl;
	}
	~Student()
	{
		cout << "de-structor" << " from " << name << endl;
	}
};

int Student::count = 0;

int main()
{
	shared_ptr<Student>ptr1(new Student("object ptr1"));
	ptr1->sayHello();
	cout << "Shared ptr count is "<< ptr1.use_count() << endl<<endl;

	// using { } to define scope of ptr2 in below section
	{
		// creating a new shared pointer that shares ownership
		shared_ptr<Student>ptr2(ptr1); // ptr2 is pointing same objecst as ptr1
		ptr2->sayHello();
		cout << "Shared ptr count is " << ptr1.use_count() << endl;
		cout << "Shared ptr count is " << ptr2.use_count() << endl << endl;
	} // scope of ptr2 is limited to this ending } , however there would be no destructor() as this was just pointing to ptr1
	
	cout << "Shared ptr count is " << ptr1.use_count() << endl;
	shared_ptr<Student>ptr3 = ptr1;
	cout << "Shared ptr count is " << ptr1.use_count() << endl;

	// will destroy ptr1 and ptr3, reducing the reference count to zero.		
	return 0; // there would be only one destructor call for this program 
}
