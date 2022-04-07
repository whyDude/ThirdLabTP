#pragma once

#include "Parr.h"

class Hyperbola final : public Parr {
private:
	float x;
	float y = 0.0;
	float k;
	float b;
public:
	Hyperbola();
	Hyperbola(float x_var, float k_var = 1.0, float b_var = 0);
	Hyperbola(const Hyperbola& copy_hyper);
	virtual ~Hyperbola();

	float findY() override;

};