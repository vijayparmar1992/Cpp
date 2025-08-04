#include <iostream>

using namespace std;

// Base class
class Index {
protected:
	int count;
public:
	Index()
	{
		count = 0;
	}

	void operator ++()
	{
		count++;
	}

	void display()
	{
		cout << "count is " << count << endl;
	}
};

// Derived class
class NewIndex : public Index
{
public:
	void operator  --()
	{
		count--;
	}
};

int main()
{
	Index i;
	++i;
	i.display();
	++i;
	i.display();

	NewIndex n;
	++n;
	++n;
	n.display();
	--n;
	n.display();

	return 0;
}
