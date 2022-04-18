#pragma once
#include <fstream>
#include"Parr.h"
//y=kx+b
class Straight final : public Parr {
private:

	const int id = 1;
	float y = 0.0;
	float x;
	float k;
	float b;

public:
	Straight();
	Straight(float x_var, float k_var = 1.0, float b_var = 0.0);
	Straight(const Straight& copy_straight);
	~Straight();

	static int getCount();

	float findY() override;
	void print() override;
	int write(std::ofstream& outFile);
	int read(std::ifstream& inFile);
	int get_id() override;

	float get_Y();
	float get_X();
	float get_K();
	float get_B();
	


	void set_Y(float Y);
	void set_X(float X);
	void set_K(float K);
	void set_B(float B);
protected:

};