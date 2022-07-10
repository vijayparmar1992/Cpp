// This program creates 2d array dynamically
#include <iostream>

using namespace std;

int main()
{
	int noOfRow = 5, noOfColumn = 10;

	// No. of row
	// Pointer to pointer
	int** table = new int* [noOfRow];

	for (int i = 0; i < noOfRow; i++)
	{
		// no. of column per row
		table[i] = new int[noOfColumn];
	}

	// Traverse 2D array
	for (int i = 0; i < noOfRow; i++)
	{
		for (int j = 0; j < noOfColumn; j++)
		{
			// Assign values
			table[i][j] = i;
		}
	}

	// Traverse 2D array
	for (int i = 0; i < noOfRow; i++)
	{
		for (int j = 0; j < noOfColumn; j++)
		{
			// Display values
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	// Deallocate memory
	for (int i = 0; i < noOfRow; i++)
	{
		// Delete inner array
		delete[] table[i];
	}
	//Delete outer array
	// Which contains the pointer of all the inner arrays
	delete[] table;



	return 0;
}
