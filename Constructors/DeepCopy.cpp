#include <iostream>

using namespace std;

class Test
{
public:
	int* data;
	int age;
	Test() = delete;

	Test(int d, int a)
	{
		data = new int(d);
		age = a;
	}

	// Deep copy
	Test(const Test& t)
	{
		cout << "In Copy Ctor" << endl;
		data = new int(*t.data);
		age = t.age;
	}

	// Move Ctor
	Test(Test&& t) noexcept
	{
		cout << "In move Ctor" << endl;
		data = t.data;
		t.data = nullptr;
		age = t.age;
	}

	// Move assignment 
	Test& operator =(Test&& t) noexcept
	{
		cout << "In Move assigment operator" << endl;
		if (this != &t)
		{
			// for std containers , default copy is usually sufficient
			// for raw resources, need to perform deep copy manually.
			delete data;
			data = t.data; 
			t.data = nullptr;
			age = t.age;
		}
		return *this;
	}

	// Deep copy
	Test& operator =(const Test& t)
	{
		cout << "In overload assigment operator" << endl;
		if (this != &t)
		{
			delete data;
			data = new int(*t.data);
			age = t.age;
		}
		return *this;
	}

	// Dtor
	~Test()
	{
		delete data;
	}


};

int main()
{
	Test b(2,2), c(3,3);
	Test d = b; // Call to copy ctor
	cout << *(b.data) << endl;
	cout << *(d.data) << endl;
	*(b.data) = 44;
	cout << *(d.data) << endl;
	*(d.data) = 55;
	cout << *(d.data) << endl;
	cout << *(b.data) << endl;

	c = b; // Call to copy overload assigment operator
	cout << *(b.data) << endl;
	cout << *(c.data) << endl;
	*c.data = 66;
	cout << *(b.data) << endl;
	cout << *(c.data) << endl;
	cout << *(d.data) << endl;

	d = std::move(c); // Call to Move assignment operator
	cout << *(d.data) << endl;

	Test e = std::move(d); // Call to Move copy ctor
	cout << *(e.data) << endl;
  
	return 0;
}
