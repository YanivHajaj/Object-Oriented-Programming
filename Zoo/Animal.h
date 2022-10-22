#pragma once
#include<iostream>
# include<string>
using namespace std;

class Animal
{
private:
	int _animalAge;
		string _name;
protected:
	int _type;
public:
	Animal();
	virtual ~Animal();
	virtual void print()const;
	virtual void makeNoise()const;
	string getName() { return this->_name; }
	int getType()const { return this->_type; }
	int getAge()const { return this->_animalAge; }
};

