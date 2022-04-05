/*
multiset stores unique value in sorting order
*/
#include <iostream>
#include<set>
#include<algorithm>
using namespace std;

template <class T>
void displayMultiset(T& mset)
{
	cout << "Priniting multiset" << endl;
	multiset<int>::iterator i;
	for (i = mset.begin(); i != mset.end(); i++)
	{
		cout << *i << endl;
	}
}

int main()
{
	multiset<int> mset;
	mset = { 23,34,45,56,23,67,34 };
	displayMultiset(mset);

	//de-scending order
	multiset<int,less<int>> mset2 = { 78,12,45,67,8965,78,27,49,36,98,54,83 };
	displayMultiset(mset2);

	multiset<int> mresult;

	//set union
	set_union(mset.begin(), mset.end(), mset2.begin(), mset2.end(), inserter(mresult,mresult.begin()));
	displayMultiset(mresult);
	//set_intersection , set_difference,set_symmetric_difference

	return 0;
}
