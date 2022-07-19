#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	int a = 12;
	ostringstream stringVal;
	stringVal << a;

	string converString = stringVal.str();

	cout << "string is " << converString << endl;

	a = 33;
	istringstream intVal(converString);

	intVal >> a;
	cout << "Int is " << a;
}
