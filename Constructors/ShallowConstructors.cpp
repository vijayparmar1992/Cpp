#include <iostream>

using namespace std;

class Complex
{
public:
	double real, image;

	// Ctor
	Complex(double real = 0, double image = 0) : real(real), image(image) {}

	// Operator overloading
	Complex operator +(const Complex& C1)
	{
		cout << "Overload operator called" << endl;
		return Complex(real + C1.real,  image + C1.image);
	}

	// Copy contstructpr
	Complex(const Complex& C1)
	{
		cout <<"In Copy constructor" << endl;
		real = C1.real;
		image = C1.image;
	}

	// Overload assigment operator
	Complex& operator =(const Complex& C1)
	{
		cout << "In Overaload assignment operator" << endl;
		real = C1.real;
		image = C1.image;
		return *this; // required for chained assigment  a=b=c
	}

	// Dtor
	~Complex() {}
};

void display(const Complex& C1)
{
	cout << "Real part : " << C1.real << ", Image part :" << C1.image << endl;
}

int main()
{
	Complex a(1, 1);
	Complex b(2, 2);
	a = b;
	Complex c = a + b;
	display(c);
	display(a);
	display(b);
	return 0;
}
