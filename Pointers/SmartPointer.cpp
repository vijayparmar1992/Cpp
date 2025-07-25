#include <iostream>
using namespace std;
 class SmartPointer
 {
 private:
	 int* ptr;
 public:
	 SmartPointer()
	 {
		 ptr = new int;
		 cout << ptr <<endl;
	 }

	 int& operator*()
	 {
		 cout << ptr << endl;
		 return *ptr;
	 }

	 SmartPointer(const SmartPointer&) = delete;
         SmartPointer& operator=(const SmartPointer&) = delete;

	 ~SmartPointer()
	 {
		 cout << "In Dtor" << endl;
		 delete ptr;
	 }



 };

int main()
{
	int j = 45;
	cout << &j << endl;
	SmartPointer s;
	*s = j;
	cout << *s;
	cin.get();
	return 0;
}
