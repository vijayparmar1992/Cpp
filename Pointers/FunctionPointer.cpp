// Example of Function pointers
// Use case of Function pointers : callback mechanism, dynamic function invocation
#include <iostream>

using namespace std;


// Function pointer declaration
int (*fp)(int, int) = NULL; // Always good to assign NULL 

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

// Passing function pointer as argument to function
int operate(int (*fp)(int, int), int a, int b)
{
	return fp(a, b);
}

// Array of function pointers
int (*fpArray[10])(int, int) = { NULL };

int main()
{
	// **Case1: Simple usage of function pointer
	int a = 5; int b = 3;
	// Assign address of function add()
	fp = add;
	int result = fp(a, b);
	cout << result<<endl;

	// Assign address of function sub()
	fp = sub;
	result = fp(a, b);
	cout << result << endl;

	// **Case2: Passing function pointer as argument to function
	cout<< operate(add, a, b)<<endl;
	cout << operate(sub, a, b) << endl;

	// **Case3: Array of function pointer
	fpArray[0] = add;
	fpArray[1] = sub;
	a = 12;
	fpArray[2] = add;
	fpArray[3] = sub;
	fpArray[4] = sub;

	for (int i = 0; i < 5; i++)
	{
		cout << operate(fpArray[i], a, b) << endl;
		a = 5;
	}
	
	return 0;
}
