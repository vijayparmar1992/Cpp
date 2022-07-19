#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void printString(string& s)
{
	cout << s << endl;
}

void printInteger(int a)
{
	cout << a << endl;
}
int main()
{
	string name = "Vijay";
	getline(cin, name);
	printString(name);

	name.push_back(' ');
	name.push_back('T');
	name.push_back('o');
	name.push_back('E');
	name.pop_back();
	printString(name);
	printInteger(name.length());

	string::iterator nameItr = name.begin();

	string s(5, '#'); //string intitialization
	printString(s);
	printInteger(name.at(2));

	char ch = name.front();

	// returns null terminated char array
	const char* charStr = name.c_str();
	cout << charStr << endl;

	name.append(" Vadodara");
	printString(name);

	// find is 0 based index
	printInteger(name.find(".."));

	// find 1st position of occureance of "Va"
	// 0 based index
	printInteger(name.find_first_of("Va"));

}
