#include<iostream>
#include<map>
using namespace std;
template<class T>
void printMap(T mmap)
{
	cout << "priniting map" << endl;
	for (auto mitr : mmap)
	{
		cout << "name is " << mitr.first << " age is " << mitr.second << endl;
	}
}

int main()
{
	map<string, int> mmap = { {"vijay",30},{"shweta",28},{"Dilip",33},{"Parth",25},{"shweta",30} };

	mmap["vijay"] = 31;//edit current key
	mmap["Ajay"] = 99; //Add new pair
	printMap(mmap);
	//**Add new pair
	pair<string, int>p;
	p.first = "NA";
	p.second = 0;
	mmap.insert(p);
	printMap(mmap);
	//**traverse through map
	map<string, int>::iterator m_itr;
	for (m_itr = mmap.begin(); m_itr != mmap.end(); m_itr++)
	{
		cout << m_itr->first << " : " << m_itr->second << endl;
	}
	//find/search map for given key or get value using key
	string name = "Parth";
	m_itr = mmap.find(name);
	if(m_itr!=mmap.end())
		cout << m_itr->first << " : " << m_itr->second << endl;
	//erase element from map
	mmap.erase("shweta"); //provide key
	mmap.erase(mmap.begin()); //using iterator
	mmap.erase(mmap.begin(),mmap.begin()++);//However map supports bidirectional iterator
	mmap.erase(mmap.begin(), mmap.find("vijay")); //delete all element till "otheres"
	printMap(mmap);

	/***********MultiMap****************/
	multimap<string, int> map_collage = { {"rk",5},{"gtu",10},{"iit",10},{"others",25} };

	//edit element
	p.first = "rk";
	p.second = 5;
	map_collage.insert(p);
	//printMap(map_collage);

	multimap<string, int>::iterator multiitr;
	//traverse through multimap
	for (multiitr = map_collage.begin(); multiitr != map_collage.end(); multiitr++)
	{
		cout << multiitr->first << " " << multiitr->second << endl;
	}

	//erase element
	map_collage.erase("gtu");
	printMap(map_collage);
	multiitr = map_collage.begin();
	multiitr++; //bi-directional itr only allows to inc or dec by 1
	multiitr++;
	map_collage.erase(multiitr);
	p.first = "msu"; p.second = 3;
	map_collage.insert(p);
	printMap(map_collage);
	map_collage.erase(map_collage.begin(), map_collage.find("others")); //delete all element till "otheres"
	printMap(map_collage);
	map_collage.insert(p);
	map_collage.insert(p);
	map_collage.insert(p);
	printMap(map_collage);
	map_collage.erase("msu");//Remove all elements which has key "msu"
	printMap(map_collage);

	//find element
	multiitr=map_collage.find("rk");
	cout << "*****rk value is " << multiitr->second<<endl;
	// assigning the elements from map_collage to map_uni
	multimap<string, int>map_uni(map_collage.begin(), map_collage.end());
	printMap(map_uni);

	multimap<string, int> my_map = { {"rk",5},{"gtu",10},{"iit",10},{"others",25} };
	printMap(my_map);
	/**lower_bound and uper bound can be use for deleting key&value*/
	//returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter
	//In case k is not present in the set container, the function returns an iterator
	//pointing to the immediate next element which is just greater than k
	cout << my_map.lower_bound("iit")->first << " " << my_map.lower_bound("others")->second<<endl;
	cout << my_map.lower_bound("jk")->first << " " << my_map.lower_bound("power")->second<<endl;
	//returns an iterator pointing to the immediate next element which is just greater than k
	//If the key passed in the parameter exceeds the maximum key in the container,
	//then the iterator returned points to next of last element
	cout << my_map.upper_bound("iit")->first << " " << my_map.upper_bound("others")->second << endl;
	cout << my_map.upper_bound("jk")->first << " " << my_map.upper_bound("power")->second << endl;

	//replace element




	return 0;

}
