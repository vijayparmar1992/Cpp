/*Selection sorting method*/
#include<iostream>
using namespace std;

int main()
{
	int size = 10;
	int marks[10] = { 12,45,56,7,78,23,46,90,34,1 };
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (marks[i] > marks[j])
			{
				temp = marks[i];
				marks[i] = marks[j];
				marks[j] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << marks[i] << " ";
	}
	return 0;
}
