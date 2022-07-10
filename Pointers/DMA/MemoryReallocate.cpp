#include <iostream>

using namespace std;

int main()
{
	//Dynamic allocated ptrArray of 5 element
	int size = 5;
	int* ptrArray = new int[size];

	// Write values
	for (int index = 0; index < size; index++)
	{
		ptrArray[index] = index;
		cout << *(ptrArray + index) << endl;
	}
	// Re-allocate 10 element to ptrArray
	cout << ">>>Memory re-allocation<<<" << endl;
	// Temporary memory allocation
	int newSize = 10;
	int* tempAllocation = new int[newSize];

	//copy old array
	for (int index = 0; index < size; index++)
	{
		tempAllocation[index] = ptrArray[index];
	}

	//delete old  allocated memory
	delete [] ptrArray;

	// assign new memory (memory re-allocation)
	ptrArray = tempAllocation;

	//tempAllocation can't be delete because it points to same mem. location as *ptrArray
	tempAllocation = NULL;

	// Write  more locations after memory allocations
	for (int index = 5; index <10; index++)
	{
		ptrArray[index] = index;
	}

	// Display array
	for (int index = 0; index < 10; index++)
	{
		cout << "location "<<index<<" value is " << ptrArray[index] << endl;
	}

	return 0;
}
