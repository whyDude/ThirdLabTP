#include "Hyperbola.h"
#include <iostream>
#include <cmath>
#include <locale>

using namespace std;


Hyperbola::Hyperbola() : x(1.0), y(0.0), k(1.0), b(0.0) { count++; }
Hyperbola::~Hyperbola() { count--; }

Hyperbola::Hyperbola(float x_var, float k_var, float b_var)
{
	x = x_var;
	k = k_var;
	b = b_var;
	count++;
}

Hyperbola::Hyperbola(const Hyperbola& copy_hyper)
{
	x = copy_hyper.x;
	y = copy_hyper.y;
	k = copy_hyper.k;
	b = copy_hyper.b;
	count++;
}

float Hyperbola::findY()
{
	y = k / x + b;
	return y;
}

float Hyperbola::get_Y() { return y; }
float Hyperbola::get_X() { return x; }
float Hyperbola::get_K() { return k; }
float Hyperbola::get_B() { return b; }
int Hyperbola::get_id() { return id; }

void Hyperbola::set_Y(float Y) { y = Y; }
void Hyperbola::set_X(float X)
{
	if (X == 0)
	{
		setlocale(LC_ALL, "Rus");
		cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
		X = 1;
	}
	x = X;
}
void Hyperbola::set_B(float B) { b = B; }
void Hyperbola::set_K(float K) { k = K; }

int Hyperbola::write(std::ofstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << this->get_id() << " " << this->get_X() << " " << this->get_K() << " " << this->get_B() << "\n";
		return 1;
	}
	return 0;
}

int  Hyperbola::read(ifstream& inFile) {
	float x_hyp, k_hyp, b_hyp;
	if (inFile.is_open())
	{
		inFile >> x_hyp >> k_hyp >> b_hyp;
		if (x_hyp == 0)
		{
			setlocale(LC_ALL, "Rus");
			cout << "Значение Х для гиперболы не может быть нулевым, поэтому Х будет равен единице" << endl;
			x_hyp = 1;
		}

		this->set_X(x_hyp);
		this->set_K(k_hyp);
		this->set_B(b_hyp);
		return 1;
	}
	return 0;

}
void Hyperbola::print()
{
	cout << "Координата Y гиперболы: " << this->findY() << ", при введенных Х = " << this->get_X() << ", К = " << this->get_K() << ", В = " << this->get_B() << endl;
}