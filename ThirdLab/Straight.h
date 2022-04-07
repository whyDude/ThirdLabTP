#pragma once

#include"Parr.h"
//y=kx+b
class Straight final : public Parr {
private:
	float y = 0.0;
	float x;
	float k;
	float b;
public:
	Straight();
	Straight(float x_var, float k_var = 1.0, float b_var = 0.0);
	Straight(const Straight& copy_straight);
	virtual ~Straight();

	float findY() override;
};