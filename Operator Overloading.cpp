#include<iostream>

using namespace std;

class Employee
{
private:

	int age,name;
public:
	Employee() {};
	Employee(int a) { age = a; }
	~Employee() {};
	void setAge(int a)
	{
		age = a;
	}
	int getAge()
	{
		return age;
	}
	int operator*(Employee* emp)
	{

		this->age= age + emp->age;
		return age;
	}


};


int main()
{
	Employee vijay, harsh,all;
	vijay.setAge(12);
	harsh.setAge(11);
	int ageAverage= vijay * &harsh;
	cout << ageAverage<<endl;

	cout << sizeof(vijay);

	return 0;
}
