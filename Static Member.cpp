/*
Example of Static variable in Class
-	Each object contains its own DM and shared FM. Static allows to shared DM among objects i.e counter or s/w license management
-	Mostly we declare static as private. Ctor and Dtor we declare in public section
-	An instance/normal MF can access instance as well as static DM
-	Static MF can only access static DM
-	This pointer never exist for static function. Hence we don’t access it using object, we access using class
-	A static DM has nothing to do with static storage class
-	Static DM definition is require outside of class, Forgetting this could lead to error by linker not by compiler

*/

#include<iostream>

using namespace std;

class Base {
private:
	static string sName;
	int age=0;
public:
	explicit Base() {};
	~Base() {};

	//Static MF can only acess static DM
	static void setName(string n)
	{
		sName = n;
		//age = 1; //This is error
	}

	//An instance/normal MF can access instance as well as static DM
	void setParameter(int a)
	{
		age = a;
		//sName = "Default"; //This is valid statement
	}
	string getName()
	{
		return sName;
	}

	void display()
	{
		cout << "Name is " << sName << endl;
		cout << "Age is " << age << endl;

	}

};

//static DM definition os require outside of class
string Base::sName = "Welcome";

int main()
{
	Base b;
	b.display();
	b.setName("Vijay");
	b.setParameter(12);
	b.display();

	//Each object share same static DM
	Base c;
	c.display();
	//Each object share same static DM
	b.setName("Changed-No");
	b.setParameter(33);
	c.display();

	return 0;
}
