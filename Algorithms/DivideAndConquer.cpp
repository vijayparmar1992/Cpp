// Divide and Conquer algorithms
// Time complexity 0(n) as there are n recursion calls
#include <iostream>
using namespace std;

int getMaxArray(int a[] , int index, int size)
{
	int max = 0;
	// Array only has one element
	if (index == 1)
	{
		return a[index];
	}

	if (index >= size - 2)
	{
		if (a[index] > a[index + 1])
		{
			return a[index];
		}
		return a[index + 1];
	}

	max = getMaxArray(a, index + 1, size);
	if (max > a[index])
	{
		return max;
	}
	return a[index];

}

int main()
{
	int array[6] = { 4,78,5,7,34,2 };
	cout << getMaxArray(array, 0, 6);
	cin.get();
	return 0;
}
