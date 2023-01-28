#include <iostream>

using namespace std;

int maxSum(int arr[], int n, int k)
{
    if (n < k)
        return -1;

    int totalSum=0;
    int windowSum=0;

    // Compute the first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    //remove first element of the last window
    //slide window by 1
    //add next element to window
    for (int i = 0; i < n - k; i++)
    {
        windowSum += arr[k + i] - arr[i];
        totalSum = max(windowSum, totalSum);
    }

    return totalSum;
}

int main()
{
    int arr[] = { 10,34,56,7,89,3,1,5,7,9,0,43,6,8,9,43,67,9,8,7 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n, k);


	cin.get();
	return 0;
}
