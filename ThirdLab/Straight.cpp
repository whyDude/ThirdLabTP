#include <iostream>
#include <cmath>
#include <locale>
#include "Straight.h"
#include <fstream>

using namespace std;

Straight::Straight() : x(0.0), y(0.0), k(1.0), b(0.0) { count++; }
Straight::~Straight()
{
	x = 0;
	y = 0;
	k = 0;
	b = 0;
	count--;
}

Straight::Straight(float x_var, float k_var, float b_var)
{
	x = x_var;
	k = k_var;
	b = b_var; 
	count++;
}

Straight::Straight(const Straight& copy_straight)
{
	x = copy_straight.x;
	y = copy_straight.y;
	k = copy_straight.k;
	b = copy_straight.b;
	count++;
}

float Straight::findY()
{
	y = k * x + b;
	return y;
}

float Straight::get_Y() { return y; }
float Straight::get_X() { return x; }
float Straight::get_K() { return k; }
float Straight::get_B() { return b; }
int Straight::get_id() { return id; }

void Straight::set_Y(float Y) { y = Y; }
void Straight::set_X(float X) { x = X; }
void Straight::set_B(float B) { b = B; }
void Straight::set_K(float K) { k = K; }


int Straight::write(std::ofstream& outFile)
{
	if (outFile.is_open())
	{
		outFile << this->get_id() << " " << this->get_X() << " " << this->get_K() << " " << this->get_B() << "\n";
		return 1;
	}
	return 0;
}

int  Straight::read(ifstream& inFile){
	float x_str, k_str, b_str;
	if (inFile.is_open())
	{

		inFile >> x_str >> k_str >> b_str;
		this->set_X(x_str);
		this->set_K(k_str);
		this->set_B(b_str);
		return 1;
	}
	return 0;	
	
}

void Straight::print()
{
	cout << "Координата Y прямой: " << this->findY() << ", при введенных Х = " << this->get_X() << ", К = " << this->get_K() << ", В = " << this->get_B() << endl;
}

int Straight::getCount() {
	return count;
}