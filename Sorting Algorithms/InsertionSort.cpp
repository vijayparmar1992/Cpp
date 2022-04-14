/*Insertion sorting method*/
#include<iostream>
using namespace std;

int main()
{
	int size = 6;
	int marks[size] = { 1,4,2,8,5,9};
	int temp;


	int j = 0;
	for (int i = 0; i < size-1; i++)
	{

		for (j = 0; j <= i; j++)
		{
			if (marks[i + 1] < marks[j])//If element in sorted array is big
			{
				temp = marks[i + 1];
				marks[i + 1] = marks[j];
				marks[j] = temp;
				break; //
			}
			else if (i == j) //reached at end of sorted array, Hence add unsorted element at end
			{
				marks[j + 1] = marks[i+1];
			}

		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << marks[i] << " ";
	}
	return 0;
}
