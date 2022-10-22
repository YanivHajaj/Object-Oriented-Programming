#include "Insect.h"

Insect::Insect() {
	this->_type = 2;
	cout << "(Insect) Enter the number of legs : ";
	cin >> this->_numOfLegs;
	cout << "(Insect) insect constructed : " << endl;
}
Insect::~Insect() {
	cout << "(Insect) insect destroyed: " << endl;
}
void Insect::print()const {
	Animal::print();
		cout << "(Insect) number of legs : "<<this->_numOfLegs<<endl;
}
void Insect::makeNoise()const {
	cout << "(Insect) Insect noise...ZzZ..." << endl;
}