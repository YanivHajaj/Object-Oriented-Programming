#pragma once
#include "Insect.h"
class Butterfly :public Insect
{
private:
	string _color;
public:
	Butterfly();
	~Butterfly();
	void print()const;
	void makeNoise()const;
};

