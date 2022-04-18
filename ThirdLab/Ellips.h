#pragma once

#include"Parr.h"
//y=sqrt((1-(x^x)/(a^a))(b^b))
class Ellips final : public Parr {
private:
	const int id = 2;
	float x;
	float y = 0.0;
	float a;
	float b;
public:
	Ellips();
	Ellips(float x_var, float a_var = 1.0, float b_var = 1.0); //круг по умолчанию
	Ellips(const Ellips& copy_ellips);
	 ~Ellips();
	
	float findY() override;
	void print() override;
	int write(std::ofstream& outFile);
	int read(std::ifstream& inFile);
	int get_id() override;

	float get_Y();
	float get_X();
	float get_A();
	float get_B();

	void set_Y(float Y);
	void set_X(float X);
	void set_A(float A);
	void set_B(float B);
};
