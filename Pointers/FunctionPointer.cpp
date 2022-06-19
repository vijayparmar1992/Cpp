// This program demonstrates Function pointer;
#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

// Function pointer
int (*operation)(int a, int b) = NULL; // Inialize to NULL

//Func pointer as argument to function
int operate(int (*fp)(int a, int b), int num1, int num2)
{
	return fp(num1, num2);
}

//Array of Function pointer
int (*funcs[2])(int a, int b) = { NULL };

int main()
{
	operation = add;
	cout << "Addition is " << operation(6, 5) << endl;

	operation = sub;
	cout << "Substraction is " << operation(6, 5) << endl;

	// Passing function pointer as argument to function
	cout << "Addition result is " << operate(add, 10, 20) <<endl;
	cout << "Substraction result is " << operate(sub, 10, 20) <<endl;
	
	// Array of Function pointer
	funcs[0] = add;
	funcs[1] = sub;

	for(int (*func)(int a, int b) :funcs)
	{
		cout << func(8, 5) << endl;
	}

	return 0;
}

