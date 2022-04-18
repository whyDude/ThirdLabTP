#include"Ellips.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <locale>

using namespace std;

Ellips::Ellips() : x(1.0), y(0.0), a(1.0), b(1.0) { count++; }
Ellips::~Ellips() { count--; }

Ellips::Ellips(float x_var, float a_var, float b_var)
{
	a = a_var;
	b = b_var;
	x = x_var;
	count++;
}

Ellips::Ellips(const Ellips& copy_ellips)
{
	x = copy_ellips.x;
	y = copy_ellips.y;
	a = copy_ellips.a;
	b = copy_ellips.b;
	count++;
}

float Ellips::findY()
{
	float sqrt_num = (1 - x / a) * (1 + x / a);
	if (sqrt_num < 0)
		return y = -1;
	y = b * sqrt(sqrt_num);
	return y;
}

float Ellips::get_Y() { return y; }
float Ellips::get_X() { return x; }
float Ellips::get_A() { return a; }
float Ellips::get_B() { return b; }
int Ellips::get_id() { return id; }

void Ellips::set_Y(float Y) { y = Y; }
void Ellips::set_X(float X) { x = X; }
void Ellips::set_A(float A)
{
	if (A == 0)
	{
		setlocale(LC_ALL, "Rus");
		cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
		A = 1;
	}
	a = A;
}
void Ellips::set_B(float B)
{
	if (B == 0)
	{
		setlocale(LC_ALL, "Rus");
		cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
		B = 1;
	}
	b = B;
}

int Ellips::write(std::ofstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << this->get_id() << " " << this->get_X() << " " << this->get_A() << " " << this->get_B() << "\n";
		return 1;
	}
	return 0;
}

int Ellips::read(std::ifstream& inFile)
{
	float x_elp, a_elp, b_elp;


	inFile >> x_elp >> a_elp >> b_elp;

	if (inFile.is_open())
	{
		if (a_elp == 0)
		{
			setlocale(LC_ALL, "Rus");
			cout << "Значение А для эллипса не может быть нулевым, поэтому А будет равен единице" << endl;
			a_elp = 1;
		}
		if (b_elp == 0)
		{
			setlocale(LC_ALL, "Rus");
			cout << "Значение B для эллипса не может быть нулевым, поэтому B будет равен единице" << endl;
			b_elp = 1;
		}

		this->set_X(x_elp);
		this->set_A(a_elp);
		this->set_B(b_elp);
		return 1;
	}
	return 0;

}

void Ellips::print() 
{
	cout << "Координата Y эллипса: " << this->findY() << ", при введенных Х = " << this->get_X() << ", А = " << this->get_A()<< ", В = " << this->get_B()<< endl;
}


