#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int size = 0;
    cin >> size ;
    int query = 0;
    int x = 0;
    
    set<int> s ;
    
    for (int indexI =0; indexI<size; indexI++)
    {
        cin >> query >> x; 
        
        if (query == 1)
            s.insert(x);
        else if (query == 2)
        {
            if(s.end() == s.find(x))
            {
                // Don't delete
            }
            else
                s.erase(x);                
        }
        else if(query == 3)
        {
            if(s.end() == s.find(x))
            {
                cout << "No" << endl;
            }
            else
                cout << "Yes" << endl;
        }
    }
      
    return 0;
}



