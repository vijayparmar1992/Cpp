#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void display(unordered_map<int, int>& m)
{
	for (auto itr : m)
		cout << itr.first << " " << itr.second << " " << endl;
}

int main()
{
	vector<int> maxVector;
	int tot = 0,max_count=0;
	vector<int> v = { 1,2,3,1,1,3,3,6,6,6,6 };
	unordered_map<int,int> mymap;
	for (int i = 0; i < v.size(); i++)
	{
		tot=++mymap[v[i]]; //tot gives # times element occurs

		cout << "tot is " <<tot<< endl;
		if (tot == max_count)
		{
			maxVector.push_back(v[i]); //All element which has same frequency added here
		}
		else if(tot > max_count)
		{
			maxVector.clear(); //clear previously added hire freq element, as current one has highest frequecy
			maxVector.push_back(v[i]); //Add highest freq. element
			max_count = tot;
		}
	}
	display(mymap);
	for (auto itr : maxVector)
	{
		cout << "Most occurance of this element " << itr << endl;
	}

	return 0;
}
