// This program demonstrates Pointers and Array
#include <iostream>

using namespace std;
int main()
{
	int* ptr[3];
	int a = 11, b = 22, c = 33;
	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;

	for (int index = 0; index < 3; index++)
	{
		cout << *ptr[index] << endl;
	}

	// 1D Array - Array of pointers
	// int *parray[3] means array of 3 pointer
	// raw is fixed to 3(SIZE) , column can be dynamic
	int array1[] = { 1,2,3,4,5,6 };
	int array2[] = { 11,12,13,14,15 };
	int array3[] = { 21,22,23,24,25 };

	int* parray[3] = { array1,array2,array3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << *(parray[i] + j) << " ";

		}
		cout << endl;
	}

	// 2D Array
	// int(*twoDimesionalPtr)[2] means twoDimesionalPtr is a pointer to
	// array of 2 elements
	// raw is dynamic, column is fized to 2 (SIZE)
	cout << ">>>> 2D Array <<<<<" << endl;
	const int noOfRaw = 3;
	int arr[noOfRaw][2] = { {1,2},{3,4},{5,6} };
	int(*twoDimesionalPtr)[2];
	twoDimesionalPtr = arr;
	for (int i = 0; i < noOfRaw; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << *(twoDimesionalPtr[i] + j) << " ";

		}
		cout << endl;
	}


	return 0;
}
