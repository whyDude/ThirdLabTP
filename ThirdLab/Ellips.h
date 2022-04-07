#pragma once

#include"Parr.h"
//y=sqrt((1-(x^x)/(a^a))(b^b))
class Ellips final : public Parr {
private:
	float x;
	float y = 0.0;
	float a;
	float b;
public:
	Ellips();
	Ellips(float x_var, float a_var = 1.0, float b_var = 1.0); //круг по умолчанию
	Ellips(const Ellips& copy_ellips);
	virtual ~Ellips();

	float findY() override;
};
