/* Smart pointers require to overload two operators * and -> */
#include<iostream>
using namespace std;

class SmartPointer
{
private:
	int* p;
public:
	SmartPointer()
	{
		p = new int;
	}

	~SmartPointer()
	{
		cout << "Distructor" << endl;
		delete p;
	}
	//int operator*()
	//{
	//	return *p;
	//}
	void operator=(int value)
	{
		*p = value;
	}
	int& operator*()
	{
		return *p;
	}


};

void trySmart()
{
	SmartPointer q;

}

int main()
{
	SmartPointer s;

	int test = 1234;
	s = 12;
	*s = 13;
	cout << *s << endl;

	trySmart();

	return 0;
}
