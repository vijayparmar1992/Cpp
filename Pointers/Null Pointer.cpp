
#include <iostream>

using namespace std;

int main()
{
	int* ptr = NULL;

	// Below line generates error as null pointers can't be
	// dereferenced
	//cout << *(int*)ptr << endl;

	void* ptr1;
	int x = 10;
	char ch = 'V';
	ptr1 = &x;

	// Null pointer can't be dereferebced
	// Require to cast a void pointer to
	// to another kind of pointer before using it
	cout << " Generic pointer points to integer value " << *(int*)ptr1 << endl;

	ptr1 = &ch;
	cout << " Generic pointer points to character value " << *(char*)ptr1 << endl;

	return 0;
}
