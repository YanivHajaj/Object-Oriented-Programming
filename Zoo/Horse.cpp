#include "Horse.h"
#include "Lion.h"
Horse::Horse() {
	this->_type = 4;
	cout << "(Horse) Enter the speed : ";
	cin >> this->_speed;
	cout << "(Horse) Horse constructed ";
}
Horse::~Horse() {
	cout << "(Horse) Horse destroyed";
}
void Horse::print() const {
	Mammel::print();
	cout << "(Horse) speed : " << this->_speed << endl;
}
void Horse::makeNoise() const {
	cout << "(Horse) Horse noise...ZzZ..." << endl;
}