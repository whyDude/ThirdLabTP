#pragma once

#include <fstream>

class Parr {
public:
	static int count;
	Parr() {};
	~Parr() {};
	virtual void print() = 0;
	virtual float findY() = 0;
	virtual int  write(std::ofstream& outFile) = 0;
	virtual int  read(std::ifstream& inFile) = 0;
	virtual int get_id() = 0;
};