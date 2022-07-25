#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arrayLength, noOfQueries;
    cin>>arrayLength>>noOfQueries;
    
    if (arrayLength <= 0)
        return 0;
    int arraySize = 0;
    //Dynamically alloctae 2D array
    vector<vector<int>> vectArray(arrayLength);
    
    for (int i =0; i<arrayLength; i++)
    {
        // Get array size
        cin>>arraySize;
        vectArray[i] = vector<int>(arraySize);
        
        // Get array
        for (int j =0; j<arraySize; j++)
        {
          cin>>vectArray[i][j];  
        }
        
    }
    
    // Get and process queries
    int i, j = 0;
    for (int index = 0; index < noOfQueries; index++)
    {
        cin >> i >> j;
        cout << vectArray[i][j] << endl;
    }
}
