/*Bubble sorting method*/
/*complexity O(n2)*/
#include<iostream>
using namespace std;

int main()
{
	int size = 10;
	int marks[size] = { 12,45,56,7,78,23,46,90,34,1 };
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (marks[j] > marks[j + 1])
			{
				int temp;
				temp = marks[j];
				marks[j] = marks[j + 1];
				marks[j + 1] = temp;
			}
		}

	}

	for (int i = 0; i < size; i++)
	{
		cout << marks[i] << " ";
	}
	return 0;
}
